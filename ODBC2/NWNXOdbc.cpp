/***************************************************************************
    NWNXOdbc.cpp - Implementation of the CNWNXODBC class.
    Copyright (C) 2005 Ingmar Stieger (Papillon, papillon@blackdagger.com) and 
	Jeroen Broekhuizen (nwnx@jengine.nl)

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
#include "NWNXOdbc.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXODBC::CNWNXODBC()
{
	request_counter = 0;
	sqlerror_counter = 0;
	dbType = dbODBC;
	hookScorco = true;
	logLevel = logAll;
}

CNWNXODBC::~CNWNXODBC()
{
	OnRelease ();
}

BOOL CNWNXODBC::OnCreate (const char* logDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf(log, "%s\\nwnx_odbc.txt", logDir);
	if (!CNWNXBase::OnCreate(log))
		return FALSE;

	// connect to the database
	if (!LoadConfiguration ())
		return false;

	WriteLogHeader();

	if (hookScorco)
	{
		scorcoSQL = (char*) malloc(MAXSQL);
		Log("o Hooking SCO....");
		HookSCO(m_fFile, log);
		Log("o Hooking RCO....");
		HookRCO(m_fFile, log);
	}

	return Connect();
}

BOOL CNWNXODBC::Connect()
{
	BOOL connected;
	CODBC* odbc;
	CMySQL* mysql;
	CSQLite* sqlite;
	
	// create a database instance
	switch (dbType)
	{
		case dbODBC:
			odbc = new CODBC();
			connected = odbc->Connect(p.server);
			db = odbc;
			break;
		case dbMYSQL:
			mysql = new CMySQL();
			connected = mysql->Connect(p.server, p.user, p.pass, p.db, p.charset);
			db = mysql;
			break;
		case dbSQLITE:
			sqlite = new CSQLite();
			connected = sqlite->Connect(p.db);
			db = sqlite;
			break;
	}

	// try to connect to the database
	if (!connected)
	{
		Log ("! Error while connecting to database: %s\n", db->GetErrorMessage ());
		return FALSE;
	}

	// we successfully connected
	Log ("o Connect successful.\n");
	return TRUE;
}

char* CNWNXODBC::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	if (strncmp (Request, "EXEC", 4) == 0)
		Execute(Parameters);
	else if (strncmp (Request, "FETCH", 5) == 0)
		Fetch (Parameters, strlen (Parameters));
	else if (strncmp(Request, "SETSCORCOSQL", 12) == 0)
		SetScorcoSQL(Parameters);
	else if (strncmp(Request, "GETHASH", 7) == 0)
		GetHash(Parameters);

	return NULL;
}

BOOL CNWNXODBC::OnRelease ()
{
	Log ("o Disconnecting from database.\n");
	db->Disconnect ();

	free(scorcoSQL);

	// release the server
	if (p.server)
		free (p.server);

	// release memory
	if (dbType == dbMYSQL)
	{
		free (p.user);
		free (p.pass);
		free (p.db);
	}

	// call base class function
	return CNWNXBase::OnRelease ();
}

void CNWNXODBC::Execute(const char *request)
{
	if (logLevel == logAll)
		Log ("o Got request: %s\n", request);
	request_counter++;

	// try to execute the SQL query
	if (!db->Execute((const uchar*)request))
		if (logLevel > logNothing)
			Log ("! SQL Error: %s\n", db->GetErrorMessage ());
}

void CNWNXODBC::Fetch(char *buffer, unsigned int buffersize)
{
	unsigned int totalbytes = 0;
	buffer[0] = 0x0;

	// fetch data from recordset
	totalbytes = db->Fetch (buffer, buffersize);
	if (logLevel == logAll)
	{
		// log what we received
		if (totalbytes == -1)
			Log ("o Empty set\n");
		else
			Log ("o Sent response (%d bytes): %s\n", totalbytes, buffer);
	}
}

void CNWNXODBC::SetScorcoSQL(char *request)
{
	memcpy(scorcoSQL, request, strlen(request) + 1);
	if (logLevel == logAll)
		Log ("o Got request (scorco): %s\n", scorcoSQL);
}

void CNWNXODBC::GetHash(char *request)
{
	Log("* MD5 hash (gethash): %s\n", lastHash);
	sprintf(request, "%s", lastHash);
}

void CNWNXODBC::WriteScorcoData(char *param, BYTE* pData, int Length)
{
	// This function either stores the object or computes a hash value of it
	if (strcmp(param, "HASH") == 0) 	
	{
		unsigned char out[16];
		hash_state md;
		md5_init(&md);
		md5_process(&md, pData, Length);
		md5_done(&md, out);
		for (int j = 0; j < 16; j += 4)
		{
			sprintf(&lastHash[j*2], "%.2x%.2x%.2x%.2x", out[j], out[j+1], out[j+2], out[j+3]);
		}
		Log("* MD5 hash (writescorcodata, length): %s, %d\n", lastHash, Length);
	}
	else if (Length > 0)
	{
		//Log ("o Writing scorco data.\n");
		if (!db->WriteScorcoData(scorcoSQL, pData, Length))
			if (logLevel > logNothing)
				Log ("! SQL Error: %s\n", db->GetErrorMessage ());
	}
}

BYTE* CNWNXODBC::ReadScorcoData(char *param, int *size)
{
	BYTE* pData;
	BOOL sqlError;
	
	//Log ("o Reading scorco data.\n");
	pData = db->ReadScorcoData(scorcoSQL, param, &sqlError, size);
	
	if (!sqlError && pData)
		return pData;
	else 
	{
		if (sqlError && (logLevel > logNothing))
			Log ("! SQL Error: %s\n", db->GetErrorMessage ());
		return NULL;
	}
}

bool CNWNXODBC::LoadConfiguration ()
{
	char buffer[256];
	CIniFile iniFile ("nwnx.ini");
	memset (&p, 0, sizeof (PARAMETERS));

	// read log file parameters
	m_maxLogSizeKB = 1024 * iniFile.ReadLong("ODBC2", "MaxLogSize", 1024);
	if (m_maxLogSizeKB < 1024)
		m_maxLogSizeKB = 1024;
	logLevel = iniFile.ReadLong("ODBC2", "LogLevel", 2);
	if ((logLevel < 0) || (logLevel > 2))
		logLevel = 2;

	// see what mode should be used
	iniFile.ReadString ("ODBC2", "source", buffer, 256, "ODBC");
	if (stricmp (buffer, "ODBC") == 0) {
		iniFile.ReadString ("ODBC2", "dsn", buffer, 256, "nwn");
		p.server = strdup (buffer);
		dbType = dbODBC;
	}
	else if (stricmp (buffer, "MYSQL") == 0) {
		// load in the settings for a direct mysql connection
		iniFile.ReadString ("ODBC2", "server", buffer, 256, "localhost");
		p.server = _strdup (buffer);
		iniFile.ReadString ("ODBC2", "user", buffer, 256, "");
		p.user = _strdup (buffer);
		iniFile.ReadString ("ODBC2", "pwd", buffer, 256, "");
		p.pass = _strdup (buffer);
		iniFile.ReadString ("ODBC2", "db", buffer, 256, "");
		p.db = _strdup (buffer);
		iniFile.ReadString ("ODBC2", "charset", buffer, 256, "");
		p.charset = _strdup (buffer);
		dbType = dbMYSQL;
	}
	else if (stricmp (buffer, "SQLITE") == 0) {
		// load in the settings for the internal database
		dbType = dbSQLITE;
		iniFile.ReadString ("ODBC2", "file", buffer, 256, "");
		p.db = _strdup (buffer);
	}
	else {
		Log ("o Critical Error: Datasource must be MySQL, ODBC, or SQLite.\n");
		dbType = dbNONE;
		return false;
	}

	// check if scorco should be hooked
	iniFile.ReadString ("ODBC2", "hookscorco", buffer, 256, "");
	if (stricmp (buffer, "false") == 0)
		hookScorco = false;

	return true;
}

void CNWNXODBC::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX ODBC2 plugin V.0.9.2.4\n");
	fprintf(m_fFile, "(c) 2005 by Ingmar Stieger (Papillon) and Jeroen Broekhuizen\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");

	fprintf(m_fFile, "o Logfile maximum size limit is: %d bytes\n", m_maxLogSizeKB);
	fprintf(m_fFile, "o Log level: ");
	switch (logLevel)
	{
		case logNothing:
			fprintf(m_fFile, "Nothing will be logged.\n");
			break;
		case logErrors:
			fprintf(m_fFile, "Only errors will be logged.\n");
			break;
		case logAll:
			fprintf(m_fFile, "Everything will be logged.\n");
			break;
	}
	switch (dbType)
	{
		case dbODBC:
			fprintf(m_fFile, "o Using ODBC connection.\n");
			break;
		case dbMYSQL:
			fprintf(m_fFile, "o Using MySQL connection.\n");
			break;
		case dbSQLITE:
			fprintf(m_fFile, "o Using SQLite connection.\n");
			break;
	}
}
