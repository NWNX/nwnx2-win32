/***************************************************************************
    Server.h - Definition of the Server and ServerClient class.
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
 ***************************************************************************/

#pragma once
#include <string>
#include <vector>
#include "constants.h"
#include "sock.h"
#include "blowfish.h"

using namespace std;

class CServerClient
{
public:
	CServerClient();
	~CServerClient();

	static DWORD WINAPI thread (LPVOID param);

	static void setPassword (char* pwd);
	static void setCryptoKey (char* key);
	static void setServervault (char* vault);

	inline void setSocket (CSock& s) { client = s; }
	inline void setReady (bool r = true) { ready = r; }
	inline bool isReady () { return ready; }

protected:
	bool run ();

	bool handShake ();
	bool getFileName (char* filename);
	void createPattern (char* pattern);
	bool findLatestFile (char* pattern, char* filename);
	void processCommand (char* filename);

private:
	static char serverVault[256];
	static char cryptoKey[128];
	static char password[64];

	char gamespy[128];
	char character[32];

	CBlowFish fish;
	CSock client;
	bool ready;
	int cmd;
};

class CServer
{
public:
	CServer(void);
	~CServer(void);

	static DWORD WINAPI thread(LPVOID param);

	void setPort (int port);
	void setMaxClients (int max);
	void setPassword (char* pwd);
	void setCryptoKey (char* key);
	void setServervault (char* vault);
	void setValidate (bool validate);

	void addKnownServer (string server);

protected:
	bool run ();
	bool isValidClient (sockaddr_in& client);

private:
	char serverVault[256];
	char cryptoKey[128];
	char password[64];
	bool noValidate;
	int maxClients;
	int port;

	vector<string> knownServers;

	HANDLE mutex;
	CServerClient* clients;
	CSock socket;
};
