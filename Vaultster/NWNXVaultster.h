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
   TCHAR* CNWNXVaultster::GetLastErrorMessage(DWORD last_error);

private:
   int maxClients;
	CClient *clients;
   CServer server;
   HANDLE hServer;
};

/* TODO: UGLY! */
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
struct CAppManager_s;                     typedef struct CAppManager_s                     CAppManager;
struct CServerExoApp_s;                   typedef struct CServerExoApp_s                   CServerExoApp;
struct CServerExoAppInternal_s;           typedef struct CServerExoAppInternal_s           CServerExoAppInternal;

struct CServerExoApp_s {
    uint32_t                   unknown;

    CServerExoAppInternal      *srv_internal;
};

struct CServerExoAppInternal_s {
    uint8_t                   unknown[0x100D0];
    uint32_t                  srv_pc_export_pending;            /* 100D0 */
};

struct CAppManager_s {
    uint32_t                   field_00;

    CServerExoApp              *app_server;             /* 0004 */
};
