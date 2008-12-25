/***************************************************************************
    NWNXVaultster.cpp - Implementation of the CNWNXVaultster class for Windows.
    Copyright (C) 2004 Jeroen Broekhuizen (nwnx@jengine.nl)
    
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
	03-07-2005: 
	  - Added extra logging information
    05-07-2005:
	  - Fixed default servervault path to '.' (trailing backslash results
	    in file not found errors.
	  - Added a checkfor trailing backspace in configuration file for the
	    servervault (see note above).

 ***************************************************************************/

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "nwnxvaultster.h"
#include "..\NWNXDll\inifile.h"

CNWNXVaultster::CNWNXVaultster(void)
{
}

CNWNXVaultster::~CNWNXVaultster(void)
{
}

BOOL CNWNXVaultster::OnCreate(const char* logDir)
{
	char buf[284], key[15];
	bool startServer, validateClient;
	DWORD serverId;

	// initialize the base class
	sprintf (buf, "%s\\nwnx_vaultster.txt", logDir);
	if (!CNWNXBase::OnCreate (buf))
		return FALSE;

	// write copy information to the log file
	Log ("NWNX2 Vaultster version 1.4.6 for Windows.\n");
	Log ("Copyright 2004-2005 (C) Jeroen Broekhuizen\n\n");

	// start up WSA (winsock library)
	if (!CSock::StartWSA ()) {
		return false;
	}

	// load in the settings
	CIniFile iniFile ("nwnx.ini");
	startServer = iniFile.ReadInteger ("VAULTSTER", "startserver", 1);
	validateClient = iniFile.ReadInteger ("VAULTSTER", "validateclient", 1);
	server.setValidate (validateClient);
	maxClients = iniFile.ReadInteger ("VAULTSTER", "MaxClients", 10);
	server.setMaxClients (maxClients);
	iniFile.ReadString ("VAULTSTER", "Path", buf, MAX_PATH, ".");
	// remove trailing backspace
	if (buf[strlen (buf)-1] == '\\')
		buf[strlen (buf)-1] = 0;
	CClient::setServervault (buf);
	server.setServervault (buf);
	iniFile.ReadString ("VAULTSTER", "Key", buf, 128, "*invalid");
	CClient::setCryptoKey (buf);
	server.setCryptoKey (buf);
	iniFile.ReadString ("VAULTSTER", "Password", buf, 128, "PWD!@");
	CClient::setPassword (buf);
	server.setPassword (buf);
	int port = iniFile.ReadInteger ("VAULTSTER", "Port", 5100);
	CClient::setPort (port);
	server.setPort (port);
	int lowprior = iniFile.ReadInteger ("VAULTSTER", "Low prior", 0);

	// load in the know servers
	if (validateClient) {
		int serverCount = iniFile.ReadInteger ("VAULTSTER", "Count", 0);
		Log ("o Loading in %d known servers.\n", serverCount);
		for (int i = 0; i < serverCount; i++) {
			sprintf (key, "Server%d", i+1);
			iniFile.ReadString ("VAULTSTER", key, buf, 284, "");
			if (buf[0] != 0) server.addKnownServer (buf);
			Log ("o Loaded: %s\n", buf);
		}
	}

	// initialize the clients
	clients = new CClient[maxClients];

	// start up the server
	if (startServer) {
		hServer = CreateThread (NULL, 0, CServer::thread, &server, 0, &serverId);
		if (hServer == NULL) {
			// Failing starting up the server should not end
			// VaultSTER, the client part can still run.
			Log ("o Failed to start up the server.\n");
			return TRUE;
		}
		else {
			Log ("o Server started on port %d.\n", port);
			// set the server thread priority
			if (lowprior == 1)
				SetThreadPriority (hServer, THREAD_PRIORITY_BELOW_NORMAL);
			else if (lowprior == 2)
				SetThreadPriority (hServer, THREAD_PRIORITY_LOWEST);
		}
	}
	return TRUE;
}

BOOL CNWNXVaultster::OnRelease(void)
{
	Log ("* Shutdown server successfull.\n");
	return CNWNXBase::OnRelease ();
}

char* CNWNXVaultster::OnRequest(char* gameObject, char* request, char* parameters)
{
	Functions cmd = (stricmp(request,"GET") == 0 ? Get : (stricmp(request,"SEND") == 0 ? Put : Status));
	if (cmd == Status) {
		// return status about current client
		int job = atoi (parameters);
		int status = clients[job].getStatus ();
		Log ("o Retreived status for %s\\%s = %d\n", clients[job].gamespy, clients[job].character, status);
		if (status == STATUS_ERROR)
			clients[job].setStatus (STATUS_OK);
		sprintf (parameters, "%d", status);
		return NULL;
	}
	else if (cmd == Get || cmd == Put) {
		char* pos[2];
		DWORD id;
		int i;

		// find a not busy client spot in the array
		for (i = 0; i < maxClients; i++) {
			if (clients[i].getStatus() == STATUS_OK)
				break;
		}

		if (i == maxClients) {
			Log ("o Too many clients already.\n");
			// can not help this client yet
			sprintf (parameters, "-2");
			return NULL;
		}
		else
			clients[i].setStatus (STATUS_BUSY);

		pos[0] = strchr (parameters, '|');
		pos[1] = strchr (&pos[0][1], '|');
		if (!pos[0] || !pos[1]) {
			Log ("o Invalid parameter (%s)!\n", parameters);
			sprintf (parameters, "-4");
			return NULL;
		}

		// set up the client for running
		memset (clients[i].server, 0, 128);
		memset (clients[i].gamespy, 0, 128);
		memset (clients[i].character, 0, 32);
		strncpy (clients[i].server, parameters, pos[0] - parameters);
		strncpy (clients[i].gamespy, &pos[0][1], pos[1] - pos[0] - 1);
		strcpy  (clients[i].character, &pos[1][1]);
		clients[i].setCommand (cmd);

		// start up the client thread
		clients[i].hThread = CreateThread (NULL, 0, CClient::thread, &clients[i], 0, &id);
		if (clients[i].hThread == NULL) {
			Log ("o Failed to start client thread!\n");
			sprintf (parameters, "-1");
		}
		else {
			sprintf (parameters, "%d", i);
		}
		return NULL;
	}
	else {
		Log ("o Invalid command.\n");
		return NULL;
	}
	/*
	// NWNX 2.61 Base class doesn't have OnRequest
	else {
		// see if the base class can do something
		return CNWNXBase::OnRequest (gameObject, request, parameters);
	}
	*/
}

