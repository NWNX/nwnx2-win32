/***************************************************************************
    Chat plugin for NWNX - Implementation of the CNWNXChat class.
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

#include "stdafx.h"
#include "NWNXChat.h"
#include "HookChat.h"
#include "../NWNXdll/IniFile.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXChat::CNWNXChat()
{
	m_LogLevel = processNPC = ignore_silent = 0;
	confKey = "CHAT";
}

CNWNXChat::~CNWNXChat()
{
}

BOOL CNWNXChat::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_chat.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
    WriteLogHeader();
	LoadConfiguration();
	lastMsg = new char[maxMsgLen+13];
	return HookFunctions();
}

char *CNWNXChat::SendMessage(char* Parameters)
{
    if (m_LogLevel >= logAll)
		Log("o SPEAK: %s\n", Parameters);
    int oSender, oRecipient, nChannel;
    int nParamLen = strlen(Parameters);
    char *nLastDelimiter = strrchr(Parameters, '¬');
    if (!nLastDelimiter || (nLastDelimiter-Parameters)<0)
    {
		if (m_LogLevel >= logAll)
			Log("o nLastDelimiter error\n");
		return "0";
    }
	int nMessageLen = nParamLen-(nLastDelimiter-Parameters)+1;
	char *sMessage = new char[nMessageLen];
    if (sscanf(Parameters, "%x¬%x¬%d¬", &oSender, &oRecipient, &nChannel)<3)
    {
		if (m_LogLevel >= logAll)
			Log("o sscanf error\n");
		delete[] sMessage;
		return "0";
    }
	strncpy(sMessage, nLastDelimiter+1, nMessageLen-1);
    int nRecipientID = GetID(oRecipient);
    if ((nChannel==4 || nChannel==20) && oRecipient<=0x7F000000)
    {
		if (m_LogLevel >= logAll)
			Log("o oRecipient is not a PC\n");
		delete[] sMessage;
		return "0";
    }
    if(nChannel!=4 && nChannel!=20) nRecipientID=-1;
    if (m_LogLevel >= logAll)
		Log("o SendMsg(%d, %08lX, '%s', %d)\n", nChannel, oSender, sMessage, nRecipientID);
    int nResult = SendMsg(nChannel, oSender, sMessage, nRecipientID);
	if (m_LogLevel >= logAll)
		Log("o Return value: %d\n", nResult); //return value for full message delivery acknowledgement
	delete[] sMessage;
	if(nResult) return "1";
	else return "0";
}

//char buf4msg[1024];

char* CNWNXChat::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	if (strncmp(Request, "GETID", 5) == 0)
	{
		int OID = strtol(Parameters, 0, 16);
		char *LastID = (char *) malloc(32);
		if (!OID)
			strcpy(LastID, "-1");
		else
			sprintf(LastID, "%ld", GetID(OID));
		if (m_LogLevel >= logScripter)
			Log("o GETID: oID='%s', ID=%s\n", Parameters, LastID);
		return LastID;
	}
	else if (strncmp(Request, "LOGNPC", 6) == 0)
	{
		processNPC = atoi(Parameters);
	}
	else if (strncmp(Request, "IGNORESILENT", 12) == 0)
	{
		ignore_silent = atoi(Parameters);
		if (m_LogLevel >= logScripter)
			Log("o ignore_silent = %d\n", ignore_silent);
	}
	else if (strncmp(Request, "SPEAK", 5) == 0)
	{
		char *sReturn = SendMessage(Parameters);
		strncpy(Parameters, sReturn, strlen(Parameters));
		Parameters[strlen(sReturn)] = 0;
		return NULL;
	}
	
	if (!scriptRun) return NULL; // all following cmds - only in chat script
	
	if (strncmp(Request, "TEXT", 4) == 0)
	{
		unsigned int length = strlen(lastMsg);
		char *ret = (char *) malloc(length+1);
		strncpy(ret, lastMsg, length);
		ret[length]=0;
		return ret;
	}
	else if (strncmp(Request, "LOG", 3) == 0)
		Log("%s", Parameters);
	else if (strncmp(Request, "SUPRESS", 7) == 0)
	{
		if (atoi(Parameters)==1)
			supressMsg = 1;
	}
	return NULL;
}

BOOL CNWNXChat::OnRelease ()
{
	Log ("o Shutdown.\n");
	// call base class function
	return CNWNXBase::OnRelease();
}

int CNWNXChat::Chat(const int mode, const int id, const char *msg, const int to)
{
	if ( !msg ) return 0; // don't process null-string
	int cmode = mode & 0xFF;
	if (m_LogLevel >= logAll)
		Log("o CHAT: mode=%lX, from_oID=%08lX, msg='%s', to_ID=%08lX\n", cmode, id, (char *)msg, to);
	sprintf(lastMsg, "%02d%10d", cmode, to);
	strncat(lastMsg, (char*)msg, maxMsgLen);
	supressMsg = 0;
	if (ignore_silent && (cmode==0xD || cmode==0xE)) return 0;
	if ( (processNPC && id != 0x7F000000) || (!processNPC && (unsigned long)id >> 16 == 0x7FFF) )
	{
		RunScript(chatScript, id);
	}
	else if (cmode==5 && id==0x7F000000) {
		RunScript(servScript, to);
	}
	return supressMsg;
}

void CNWNXChat::LoadConfiguration ()
{
	CIniFile iniFile ("nwnx.ini");

	// read log file setting
	m_LogLevel = iniFile.ReadLong(confKey, "LogLevel", 0);
	maxMsgLen = iniFile.ReadLong(confKey, "max_msg_len", 1024);
	processNPC = iniFile.ReadLong(confKey, "processnpc", 0);
	ignore_silent = iniFile.ReadLong(confKey, "ignore_silent", 0);
	iniFile.ReadString(confKey, "chat_script", chatScript, 16, "chat_script");
	iniFile.ReadString(confKey, "server_script", servScript, 16, "server_script");

	if (m_LogLevel > 0)
	{
		fprintf(m_fFile, "Settings:\n");
		fprintf(m_fFile, "chat_script: %s\n", chatScript);
		fprintf(m_fFile, "server_script: %s\n", servScript);
		fprintf(m_fFile, "max_msg_len: %d\n", maxMsgLen);
		fprintf(m_fFile, "processnpc: %d\n", processNPC);
		fprintf(m_fFile, "ignore_silent: %d\n\n", processNPC);
	}
}

void CNWNXChat::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Chat version 0.3.4 for Windows.\n");
	fprintf(m_fFile, "(c) 2005-2006 by dumbo (dumbo@nm.ru)\n");
	fprintf(m_fFile, "(c) 2006-2008 virusman (virusman@virusman.ru)\n");
}