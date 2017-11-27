/***************************************************************************
    NWN Extender - ODBC persistence functions
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

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
#include "string.h"
#include "stdio.h"
#include "odbc.h"

direxec::direxec()
{
	_mbscpy(chr_ds_name,(const unsigned char *)"nwn");
	errorstate = FALSE;
	request_counter = 0;
	sqlerror_counter = 0;
}

// Allocate environment handle, allocate connection handle,
// connect to data source, and allocate statement handle.
bool direxec::sqlconn(FILE* file)
{
	logFile = file;
	unsigned int timeout = 10; // seconds
	SQLAllocEnv(&henv);
	SQLAllocConnect(henv,&hdbc);
	SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, &timeout, 0);
	rc=SQLConnect(hdbc,chr_ds_name,SQL_NTS,NULL,0,NULL,0);
   
	// Deallocate handles, display error message, and exit.
	if (!MYSQLSUCCESS(rc))
	{
		SQLCHAR SqlState[6];
		SQLINTEGER NativeError;
		SQLSMALLINT MsgLen;

		SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, 1, SqlState, &NativeError, (unsigned char *) szData, 2048, &MsgLen);
		SQLFreeEnv(henv);
		SQLFreeConnect(hdbc);

		fprintf(logFile, "! Error while connecting to database: %s\n", szData);
		errorstate = TRUE;
		return FALSE;
	}

	rc=SQLAllocStmt(hdbc,&hstmt);
	errorstate = FALSE;
	return TRUE;
}

// Execute SQL command with SQLExecDirect() ODBC API.
int direxec::sqlexec(char *buffer, unsigned int buffersize)
{
	SQLFreeStmt(hstmt,SQL_CLOSE);

	rc=SQLExecDirect(hstmt, (unsigned char *) buffer, SQL_NTS);
	if (!MYSQLSUCCESS(rc))  // Error
	{
		errorstate = TRUE;

		char *msg = error_msg();
		if (strlen(msg) < buffersize)
			strcpy(buffer, msg);
		else
		{
			strncpy(buffer, msg, buffersize);
			buffer[buffersize] = 0x0;
		}

		return -1;
	}
	else
		errorstate = FALSE;

	strcpy(buffer, "");
	return 0;
}

int direxec::sqlfetch(char* buffer, unsigned int buffersize)
{
	unsigned int totalbytes = 0;
	SQLSMALLINT NumCols, i;

	buffer[0] = 0x0;

	// walk through the resultset
	if (SQLFetch(hstmt) == SQL_SUCCESS)
	{
		SQLNumResultCols(hstmt, &NumCols);

		// add each column to buffer
		for (i = 1; i <= NumCols; i++)
		{
			SQLGetData(hstmt, i, SQL_C_CHAR, szData, MAX_DATA, &cbData);
			
			if ((totalbytes + cbData <= buffersize) && (cbData != SQL_NULL_DATA))
			{
				totalbytes += cbData;					
				strcat(buffer, szData);
			}

			if ((i != NumCols) && (totalbytes + 1 <= buffersize))
			{
				totalbytes++;
				strcat(buffer, "¬");  // ascii 170
			}
		}
		fprintf(logFile, "o Sent response (%d bytes): %s\n", totalbytes, buffer);
	}
	else
		fprintf(logFile, "o Empty set\n");

	errorstate = FALSE;
	return totalbytes;
}

// Free the statement handle, disconnect, free the connection handle, and
// free the environment handle.
void direxec::sqldisconn(void)
{
	SQLFreeStmt(hstmt,SQL_DROP);
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
}

// return error message 
char* direxec::error_msg(void)
{
   unsigned char szSQLSTATE[10];
   SDWORD nErr;
   SWORD cbmsg;

   if (SQLError(0, 0, hstmt, szSQLSTATE, &nErr, (unsigned char*) msg, sizeof(msg), &cbmsg) == SQL_SUCCESS)
      return msg;
   else
	  return (char *) "";
}

bool direxec::ProcessRequest(char* request, unsigned int responseSize)
{
	unsigned int numBytes;
	
	fprintf(logFile, "o Got request: %s\n", request);
	request_counter++;
    numBytes = sqlexec(request, responseSize - 1);

	if (errorstate)
	{
		sqlerror_counter++;
		fprintf(logFile, "! SQL Error: %s\n", request);
		return FALSE;
	}

	return TRUE;
}