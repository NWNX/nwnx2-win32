/***************************************************************************
    Client.cpp - Implementation of the Server and ServerClient class.
    Copyright (C) 2004 Jeroen Broekhuizen (jeroen@nwnx.org)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 ***************************************************************************
    Updates:
	21-05-2005: 
	  - Modified the isValidClient function to resolve to IP addresses 
	    instead of DNS names. 
	  - addKnownServer function got an additional check to make sure that
	    the DNS is zero terminated

 ***************************************************************************/
    

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include "NWNXVaultster.h"

typedef unsigned char uchar;
typedef unsigned long ulong;

#pragma warning (disable: 4267 4996)

// use this variable for logging purposes
extern CNWNXVaultster vaultster;

CServerClient::CServerClient()
{
   ready = true;
}

CServerClient::~CServerClient()
{
}

char CServerClient::serverVault[] = "";
char CServerClient::cryptoKey[] = "";
char CServerClient::password[] = "";

void CServerClient::setServervault (char* vault)
{
	// save a static string with the servervault directory
	strcpy (serverVault, vault); 
}

void CServerClient::setCryptoKey (char* key)
{
	// save a copy of the blowfish key
	strcpy (cryptoKey, key);
}

void CServerClient::setPassword (char* pwd)
{
	// save the password for identification
	strcpy (password, pwd);
}

DWORD CServerClient::thread (LPVOID param)
{
   CServerClient* client = (CServerClient*)param;
   client->run ();
   client->setReady ();
   return 0;
}

bool CServerClient::run ()
{
   char filename[MAX_PATH];

   // initialize the fish crypto engine
   fish.Initialize ((uchar*)cryptoKey, strlen (cryptoKey));

   // try to perform the handshaking process
   if (!handShake ()) {
      client.Close ();
      return false;
   }

   // receive & process the filename
   memset (filename, 0, MAX_PATH);
   if (!getFileName (filename)) {
	  vaultster.Log ("o Failure in sending over file name!\n");
      client.Close ();
      return false;
   }

   // now process the command
   processCommand (filename);
   client.Close ();
   return true;
}

bool CServerClient::handShake ()
{
   // receive the command
   client.Receive (cmd);
   if (cmd < CMD_SEND || cmd > CMD_QUERY) {
      client.Send (INFO_NACK);
      client.Close ();
      return false;
   }
   else
      client.Send (INFO_ACK);

   // do the handshaking
   if (cmd != CMD_QUERY) {
      int len = 128;
      uchar encrypted[128];
      char pwd[128];

      // see if the first part of the decrypted password is correct
      client.Receive (encrypted, len);
      fish.Decode (encrypted, (uchar*)pwd, 128);
      if (strncmp (pwd, password, strlen (password)) != 0) {
         client.Send (INFO_NACK);
         return false;
      }
      else
         client.Send (INFO_ACK);
   }

   return true;
}

bool CServerClient::getFileName (char* filename)
{
   int length;
   uchar encrypted[256];
   char pattern[32];

   memset (encrypted, 0, 256);
   memset (gamespy, 0, 128);
   memset (character, 0, 32);
   memset (pattern, 0, 32);

   // receive gamespy & character name
   client.Receive (length);
   client.Receive (encrypted, length);
   fish.Decode (encrypted, (uchar*)gamespy, length);

   client.Receive (length);
   client.Receive (encrypted, length);
   fish.Decode (encrypted, (uchar*)character, length);

   vaultster.Log ("o Character: %s - %s - %s\n", serverVault, gamespy, character);

   // build up the path
   if (cmd == CMD_SEND) {
     // only construct filename for when the file will be received here.
     sprintf (filename, "%s\\%s\\%s.bic", serverVault, gamespy, character);
     client.Send (INFO_ACK);
   }
   else {
     vaultster.Log ("o File not found here.\n");
     // file name wasn't found
     client.Send (INFO_NACK);
     return false;
   }

   return true;
}

void CServerClient::processCommand (char* filename)
{
   // execute the right command
   switch (cmd) {
   case CMD_SEND:
      client.ReceiveFile (filename);
      break;
   case CMD_GET:
      client.SendFile (filename);
      break;
   }
}

////////////////////////////////////////////////////////////////////////
// Main server part

CServer::CServer(void)
{
}

CServer::~CServer(void)
{
}

void CServer::setPort (int p)
{
   // save the port number, which is used to connect
   port = p;
}

void CServer::setMaxClients (int max)
{
   // keep in mind how much clients can portal at the same time
   maxClients = max;
}

void CServer::setServervault (char* vault)
{
	// save a static string with the servervault directory
   CServerClient::setServervault (vault);
}

void CServer::setCryptoKey (char* key)
{
	// save a copy of the blowfish key
   CServerClient::setCryptoKey (key);
}

void CServer::setPassword (char* pwd)
{
	// save the password for identification
   CServerClient::setPassword (pwd);
}

void CServer::addKnownServer (string server)
{
	// make sure there is not trialing enter
	if (server[server.length()-1] == '\n')
		server[server.length()-1] = '\0';
	// save the server in the list
	knownServers.push_back (server);
}

void CServer::setValidate (bool validate)
{
	// negate to make 
	noValidate = !validate;
}

DWORD CServer::thread(LPVOID param)
{
   // run the server
   CServer* server = (CServer*)param;
   bool retval = server->run ();
   vaultster.Log("o Server thread terminating, CServer::run() returned %d.\n", retval);
   return retval;
}

bool CServer::run ()
{
	CSock client;
	sockaddr_in client_addr;
	DWORD id;
	char mutexname[15];

	// See if there is already a VaultSTER server running on 
	// this port. There can be only one, so leave when the
	// mutex already exists.
	sprintf(mutexname, "VAULTSTER%d", port);
	HANDLE mutex = CreateMutex (NULL, TRUE, mutexname);
	if (GetLastError () == ERROR_ALREADY_EXISTS) {
		vaultster.Log("o Failed to run server; mutex already exists.\n");
		return true;
	}

	// try to open the port
	if (!socket.Create (port)) {
		vaultster.Log("o Failed to run server; could not open socket on port.\n");
		return false;
	}
	socket.Listen ();

	// initialize memory for the clients
	clients = new CServerClient[maxClients];
	   
	// loop forever to 
	while (true) {
		if (socket.Accept (client, (SOCKADDR*)&client_addr)) {
			if (noValidate || isValidClient (client_addr)) {
				// find an empty spot to help this client
				int i = 0;
				for (i = 0; i < maxClients; i++) {
					if (clients[i].isReady ()) {
						clients[i].setReady (false);
						clients[i].setSocket (client);
						HANDLE hThread = CreateThread (NULL, 0, CServerClient::thread, &clients[i], 0, &id);
						if(hThread == NULL)
						{
							DWORD dw = GetLastError();
							vaultster.Log ("o Failed to start serverclient thread (GetLastError returned %d - \"%s\")!\n", dw, vaultster.GetLastErrorMessage(dw));
						}
						break;
					}
				}
				// when no spot is found, close the connection
				if (i == maxClients) {
					client.Close ();
				}
			}
			else {
				// invalid client, log was generated in isValidClient
				// send a nack by default on password checking
				int cmd = 0;
				client.Receive (cmd);
				client.Send (INFO_NACK);
				client.Close ();
			}
		}
	}

	// release the mutex
	ReleaseMutex (mutex);
	vaultster.Log("o Server mutex released.\n");
	return true;
}

/*!
	\fn: CServer::isValidClient(sockaddr_in& client)
	\brief: Tries to validate a client based on IP addresses. If a known server is listed
	as DNS, that name will be resolved to an IP address.
	\param client a client info structure retreived from the accept function
	\returns true in case the client was validated correctly, false otherwise
 */
bool CServer::isValidClient (sockaddr_in& client)
{
	// convert the ip to a string
	string addr = inet_ntoa (client.sin_addr);
	vaultster.Log("o Validating client: %s\n", addr.c_str());

	// try to find the client in our list
	vector<string>::iterator it = knownServers.begin();
	for (; it != knownServers.end(); it++) {
		if (isalpha ((*it)[0])) {
			// resolve IP address of the host
			hostent* host = gethostbyname ((*it).c_str());
			if (host) {
				struct in_addr *address = (struct in_addr *) host->h_addr;
				string server_addr = inet_ntoa(*address);
				if (addr == server_addr)
				{
					vaultster.Log("o Client successfully validated: %s\n", addr.c_str());
					return true;
				}
			}
			else
				vaultster.Log ("* Warning(!!): could not retrieve IP address for host %s; error code: %d.\n", addr.c_str(), WSAGetLastError());
		}
		else {
			if ((*it) == addr)
				return true;
		}
	}

	// if we get here the client is not known, so reject
	vaultster.Log ("* Invalid client tries to connect: %s\n" , addr.c_str());
	return false;
}
