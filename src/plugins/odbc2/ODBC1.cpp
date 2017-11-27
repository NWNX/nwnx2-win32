/***************************************************************************
    ODBC1.cpp - Implementation of the CODBC class.
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
/* Change log
 *
 * 16-12-2004 (Jeroen)
 *   - improved performance during fetch
 */

#include "stdafx.h"
#include "ODBC1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CODBC::CODBC() : CDB()
{
	henv = NULL;
	hdbc = NULL;
	hstmt = NULL;
}

CODBC::~CODBC()
{

}

BOOL CODBC::Connect ()
{
	return Connect ("nwn", 10);
}

BOOL CODBC::Connect(char* DSN, int timeout)
{
	SQLAllocEnv (&henv);
	SQLAllocConnect (henv,&hdbc);
	SQLSetConnectAttr (hdbc, SQL_LOGIN_TIMEOUT, &timeout, 0);
	rc = SQLConnect (hdbc, (unsigned char*)DSN, SQL_NTS, NULL, 0, NULL, 0);

	// On error: deallocate handles, display error message, and exit.
	if (!MYSQLSUCCESS(rc))
	{
		SQLCHAR SqlState[6];
		SQLINTEGER NativeError;
		SQLSMALLINT MsgLen;

		SQLGetDiagRec(SQL_HANDLE_DBC, hdbc, 1, SqlState, &NativeError, (unsigned char *)lastError, 2048, &MsgLen);
		SQLFreeEnv(henv);
		SQLFreeConnect(hdbc);
		return FALSE;
	}

	// connecting was succesfull
	rc=SQLAllocStmt(hdbc, &hstmt);
	return TRUE;
}

void CODBC::Disconnect()
{
	// free up the ODBC connection
	/*
	SQLFreeStmt(hstmt, SQL_DROP);
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
	*/
}

BOOL CODBC::Execute(const uchar *query)
{
	SQLFreeStmt(hstmt,SQL_CLOSE);

	// execute the query
	rc=SQLExecDirect(hstmt, (unsigned char *)query, SQL_NTS);
	if (!MYSQLSUCCESS(rc))  // Error
	{
		SaveSQLError ();
		return FALSE;
	}
	return TRUE;
}

uint CODBC::Fetch(char *buffer, uint buffersize)
{
	uint total, totalbytes = 0;
	SQLSMALLINT NumCols, i;

	buffer[0] = 0x0;

	// walk through the resultset
	if (SQLFetch(hstmt) != SQL_SUCCESS)
		return -1;

	// add each column to buffer
	SQLNumResultCols(hstmt, &NumCols);
	for (i = 1; i <= NumCols; i++)
	{
		SQLGetData(hstmt, i, SQL_C_CHAR, columnData, MAX_DATA, &cbData);
		
		total = totalbytes + cbData;
		if ((total < buffersize) && (cbData != SQL_NULL_DATA)) {
			memcpy (&buffer[totalbytes], columnData, cbData);
			totalbytes = total;					
		}

		if ((i != NumCols) && (totalbytes + 1 < buffersize)) {
			buffer[totalbytes] = '¬'; // ascii 170
			totalbytes++;
		}
	}

	buffer[totalbytes] = 0;
	return totalbytes;
}

BOOL CODBC::WriteScorcoData(char* SQL, BYTE* pData, int Length)
{
	SQLRETURN retcode;
	SQLINTEGER cbObjectParam;
	SQLPOINTER pToken;

	char* pSQL = new char[strlen(SQL)];
	sprintf(pSQL, SQL, "?");

	SQLFreeStmt(hstmt,SQL_CLOSE);
	retcode = SQLPrepare(hstmt, (unsigned char *)pSQL, SQL_NTS);
	if (MYSQLSUCCESS(rc))
	{
		SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_LONGVARBINARY, 
			0, 0, (SQLPOINTER) 2, 0, &cbObjectParam);

		cbObjectParam = SQL_LEN_DATA_AT_EXEC(0);
		retcode = SQLExecute(hstmt);

		while (retcode == SQL_NEED_DATA)
		{
			retcode = SQLParamData(hstmt, &pToken);
			if (retcode == SQL_NEED_DATA)
				SQLPutData(hstmt, pData, Length);
		}
		return TRUE;
	}
	else
	{
		SaveSQLError();
		return FALSE;
	}
}

BYTE* CODBC::ReadScorcoData(char* SQL, char *param, BOOL* pSqlError, int *size)
{
	SQLSMALLINT NumCols;
	SQLUINTEGER columnSizePtr;

	if (strcmp(param, "FETCHMODE") != 0)
	{	
		SQLFreeStmt(hstmt,SQL_CLOSE);

		// execute the query
		rc=SQLExecDirect(hstmt, (unsigned char *)SQL, SQL_NTS);
		if (!MYSQLSUCCESS(rc))
		{
			SaveSQLError();
			*pSqlError = true;
			return NULL;
		}
	}

	*pSqlError = false;
	// walk through the resultset
	if (SQLFetch(hstmt) != SQL_SUCCESS)
		return NULL;

	SQLNumResultCols(hstmt, &NumCols);
	if (NumCols == 1)
	{
		SQLDescribeCol(hstmt, 1, NULL, 0, NULL, NULL, &columnSizePtr, NULL, NULL);
		if (columnSizePtr > MAXRESULT)
		{
			sprintf(lastError, "Critical error - object too large (>%ld bytes).\n", MAXRESULT);
			*pSqlError = true;
			return NULL;
		}
		SQLGetData(hstmt, 1, SQL_C_BINARY, pReturn, columnSizePtr, &cbData);
		*size = columnSizePtr;
		return pReturn;	
	}
	else
		return NULL;
}

const char* CODBC::GetErrorMessage()
{
	// return last error
	return lastError;
}

void CODBC::SaveSQLError()
{
	unsigned char szSQLSTATE[10];
	SDWORD nErr;
	SWORD cbmsg;

	// fetch the last SQL error
	SQLError(0, 0, hstmt, szSQLSTATE, &nErr, (unsigned char*) lastError, sizeof(lastError), &cbmsg);
}

