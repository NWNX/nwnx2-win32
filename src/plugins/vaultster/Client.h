/***************************************************************************
    Client.h - Definition of the Client class.
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
 ***************************************************************************/
#pragma once

#include "constants.h"
#include "sock.h"
#include "blowfish.h"

enum Functions { Get = 1, Put, Status };

class CClient
{
public:
   CClient(void);
   ~CClient(void);

   static DWORD WINAPI thread (LPVOID param);

   static void setPort (int port);
   static void setPassword (char* pwd);
	static void setCryptoKey (char* key);
	static void setServervault (char* vault);

   void setCommand (Functions cmd);
   void setStatus (int stat);
   int getStatus ();

   char server[128];
	char gamespy[128];
	char character[32];

	HANDLE hThread;

protected:
   void createPattern (char* pattern);
   bool findLatestFile (char* pattern, char* filename);
   void generatePassword (char pwd[128]);
   bool handShake ();
   bool transmitFile (char* localFile);
   void sendEncrypted (char* str);

   bool run ();

private:
   static char serverVault[256];
	static char cryptoKey[128];
	static char password[64];
   static int port;
  
   int status;
   int command;
   CBlowFish fish;
	CSock socket;
};
