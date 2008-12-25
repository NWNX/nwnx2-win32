/***************************************************************************
    NWNXVaultster.h - Definition of the CNWNXVaultster class for Windows.
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
#include "..\NWNXdll\NWNXBase.h"
#include "client.h"
#include "server.h"

class CNWNXVaultster : public CNWNXBase
{
public:
   CNWNXVaultster(void);
   ~CNWNXVaultster(void);

   BOOL OnCreate(const char* logFileName);
   BOOL OnRelease(void);
   char* OnRequest(char* gameObject, char* Request, char* Parameters);

private:
   int maxClients;
	CClient *clients;
   CServer server;
   HANDLE hServer;
};
