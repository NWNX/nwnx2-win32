/***************************************************************************
    Chat plugin for NWNX  - hooks implementation
    (c) 2005,2006 dumbo (dumbo@nm.ru)
    (c) 2006-2007 virusman (virusman@virusman.ru)

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

#include "HookChat.h"
#include "madCHook.h"
#include "NWNXChat.h"

extern CNWNXChat chat;

void (*ChatNextHook)();
void (*pRunScript)();

dword pServThis = 0;
dword pList = 0;
dword pScriptThis = 0;
char *pChatThis = 0;

dword * (*pGetPCobj)();
int (*pChat)(int mode, int id, char *msg, int len, int to);

char scriptRun = 0;
char *lastMsg;
char lastIDs[32];

unsigned long lastRet;

void ChatHookProc(const int mode, const int id, const char *msg, const int len, const int to)
{
//  _asm { int 3 }
  _asm { pushad }
	if (!pChatThis) _asm { mov pChatThis, ecx };
  if (!scriptRun)
		lastRet = (unsigned long)chat.Chat(mode, id, msg, to);
  _asm { popad }
  _asm { leave }
	if (!scriptRun && lastRet)
  {
    _asm { mov eax, lastRet }
    _asm { retn 0x18 }
  }
  _asm { jmp ChatNextHook }
}


DWORD FindChat()
{
/*
_asm{
        nop
        nop
//        int 3
        nop
        nop
        nop
}
*/
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
// 43bdc0:
		if ((ptr[0] == (char) 0x6A) &&
			(ptr[1] == (char) 0xFF) &&
			(ptr[2] == (char) 0x68) &&
			(ptr[0x6A] == (char) 0xFC) &&
			(ptr[0x6B] == (char) 0x00) &&
			(ptr[0x6C] == (char) 0x00) &&
			(ptr[0x6D] == (char) 0x00) &&
			(ptr[0x72] == (char) 0x80) &&
			(ptr[0x73] == (char) 0x7C) &&
 			(ptr[0x74] == (char) 0x24) &&
 			(ptr[0x75] == (char) 0x4C) &&
 			(ptr[0x76] == (char) 0x02)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

// 53 8B 5C 24 08 81 FB 00 00 00 7F
DWORD FindGetPCobjByOID ()
{
    char *ptr = (char *) 0x400000;

    while (ptr < (char *) 0x600000)
    {
        if ((ptr[0] == (char) 0x53) &&
            (ptr[1] == (char) 0x8B) &&
            (ptr[2] == (char) 0x5C) &&
            (ptr[3] == (char) 0x24) &&
            (ptr[4] == (char) 0x08) &&
            (ptr[5] == (char) 0x81) &&
            (ptr[6] == (char) 0xfb) &&
            (ptr[7] == (char) 0x00) &&
            (ptr[8] == (char) 0x00) &&
            (ptr[9] == (char) 0x00) &&
            (ptr[10] == (char) 0x7f)
            )
            return (unsigned long) ptr;
	else
	    ptr++;
    }
    return 0;
}

// 53 55 56 57 8B 7C 24 14 8B F1 8B CF
DWORD FindRunScript()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x53) &&
			(ptr[1] == (char) 0x55) &&
			(ptr[2] == (char) 0x56) &&
			(ptr[3] == (char) 0x57) &&
			(ptr[4] == (char) 0x8B) &&
			(ptr[5] == (char) 0x7C) &&
			(ptr[6] == (char) 0x24) &&
			(ptr[7] == (char) 0x14) &&
			(ptr[8] == (char) 0x8B) &&
 			(ptr[9] == (char) 0xF1) &&
 			(ptr[0xA] == (char) 0x8B) &&
 			(ptr[0xB] == (char) 0xCF) &&
			(ptr[0xC] == (char) 0xE8) &&
			(ptr[0x11] == (char) 0x85) &&
			(ptr[0x12] == (char) 0xC0)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	//64 A1 00 00 00 00 6A FF 68 ** ** ** ** 50 64 89 25 00 00 00 00 83 EC 1C 53 8B 5C 24 30
	ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x64) &&
			(ptr[1] == (char) 0xA1) &&
			(ptr[2] == (char) 0x00) &&
			(ptr[3] == (char) 0x00) &&
			(ptr[4] == (char) 0x00) &&
			(ptr[5] == (char) 0x00) &&
			(ptr[6] == (char) 0x6A) &&
			(ptr[7] == (char) 0xFF) &&
			(ptr[8] == (char) 0x68) &&
			(ptr[0xD] == (char) 0x50) &&
 			(ptr[0xE] == (char) 0x64) &&
 			(ptr[0xF] == (char) 0x89) &&
			(ptr[0x10] == (char) 0x25) &&
			(ptr[0x11] == (char) 0x00) &&
			(ptr[0x12] == (char) 0x00) &&
			(ptr[0x13] == (char) 0x00) &&
			(ptr[0x14] == (char) 0x00) &&
			(ptr[0x15] == (char) 0x83) &&
			(ptr[0x16] == (char) 0xEC) &&
			(ptr[0x17] == (char) 0x1C) &&
			(ptr[0x18] == (char) 0x53) &&
			(ptr[0x19] == (char) 0x8B) &&
			(ptr[0x1A] == (char) 0x5C) &&
			(ptr[0x1B] == (char) 0x24) &&
			(ptr[0x1C] == (char) 0x30) &&
			//8D 8E 70 01 00 00
			(ptr[0x3B] == (char) 0x8D) &&
			(ptr[0x3C] == (char) 0x8E) &&
			(ptr[0x3D] == (char) 0x70) &&
			(ptr[0x3E] == (char) 0x01) &&
			(ptr[0x3F] == (char) 0x00)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

void RunScript(char * sname, int ObjID)
{
  int sptr[4];
  sptr[1] = strlen(sname);
  _asm {
    lea  edx, sptr
    mov  eax, sname
    mov  [edx], eax
    push 1
    push ObjID
    push edx
    mov ecx, pScriptThis
    mov ecx, [ecx]
  }
  scriptRun = 1;
  pRunScript();
  scriptRun = 0;
}

int SendMsg(const int mode, const int id, char *msg, const int to)
{
	int nRetVal;
	if (pChat && pChatThis && msg)
	{
		int len = strlen(msg);
		_asm { 
		  push 0 // extra ;)
		  push to
		  push len
		  push msg
		  push id
		  push mode
		  mov ecx, pChatThis 
		  call [pChat]
		  mov nRetVal, eax
		}
		return nRetVal;
		//pChat(mode, id, msg, len, to);
	}
	else return 0;
}

dword * GetPCobj(dword OID)
{
//  _asm { int 3 }
  _asm {
    mov  ecx, pServThis
    mov  ecx, [ecx]
    mov  ecx, [ecx+4]
    mov  ecx, [ecx+4]
    push OID
  }
  return pGetPCobj();
}

unsigned long GetID(dword OID)
{
	dword * pcObj = GetPCobj(OID);
	if(!pcObj) return NULL;
	return *(pcObj+1); // +1 dword = +4
}

int HookFunctions()
{
	int success1 = 0, success2 = 0;
	DWORD org_Chat = FindChat();
	DWORD org_Run  = FindRunScript();
	DWORD org_Get  = FindGetPCobjByOID();
	if (org_Chat)
	{
		pServThis = *(dword*)(org_Chat + 0x1f);
		pScriptThis = pServThis - 8;
		*(dword*)&pChat = org_Chat;
		success1 = HookCode((PVOID) org_Chat, ChatHookProc, (PVOID*) &ChatNextHook);
	}

	if (org_Chat && success1)
		fprintf(chat.m_fFile, "! ChatProc hooked at %x.\n", org_Chat);
	else
		fprintf(chat.m_fFile, "X Could not find Chat function or hook failed: %x\n", org_Chat);
	
	if (org_Run) {
		*(dword*)&pRunScript = org_Run;
		fprintf(chat.m_fFile, "! RunProc located at %x.\n", org_Run);
	}
	else
		fprintf(chat.m_fFile, "X Could not find Run function: %x\n", org_Run);
	
	if (org_Get) {
		*(dword*)&pGetPCobj = org_Get;
		fprintf(chat.m_fFile, "! GetIDProc located at %x.\n", org_Get);
	}
	else
		fprintf(chat.m_fFile, "X Could not find GetID function: %x\n", org_Get);
	
	
	fprintf(chat.m_fFile, "\n");
	fflush(chat.m_fFile);
	
	return (org_Chat && org_Run && org_Get && pServThis && pScriptThis && success1);
}

