/***************************************************************************
    scorcohook.h - Hooking of StoreCampaingObject and RetrieveCampaignObject
    Copyright (C) 2005 Ingmar Stieger (Papillon, papillon@blackdagger.com)

	Thanks go to Earandel for conducting the fundamental research and 
	for creating the hooks to SCO and RCO.

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

void SCOHookProc();
void RCOHookProc();
void HookSCO(FILE* logFile, char* logFileName);
void HookRCO(FILE* logFile, char* logFileName);
DWORD FindHookSCO();
DWORD FindHookRCO();

int SQLSCO(char** Database, char** Key, char** Player, int Flags, BYTE* pData, int Size);
void* SQLRCO(char** Database, char** Key, char** Player, int* arg4, int* size);
