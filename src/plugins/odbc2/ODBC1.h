/***************************************************************************
    ODBC1.h - Interface for the CODBC class.
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

#if !defined(AFX_ODBC1_H__4A61FC82_E6C6_49CE_8D1D_4E99995AFA3E__INCLUDED_)
#define AFX_ODBC1_H__4A61FC82_E6C6_49CE_8D1D_4E99995AFA3E__INCLUDED_

#include <sql.h>
#include <sqlext.h>
#include <stdlib.h>
#include <mbstring.h>
#include "db.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_DATA 65536 // one column
#define MYSQLSUCCESS(rc) ((rc==SQL_SUCCESS)||(rc==SQL_SUCCESS_WITH_INFO))

class CODBC : public CDB
{
public:
	CODBC();
	virtual ~CODBC();

	BOOL Connect ();
	BOOL Connect (char* DSN, int timeout=10);
	void Disconnect ();

	BOOL Execute (const uchar* query);
	uint Fetch (char* buffer, uint buffersize);
	BOOL WriteScorcoData(char* SQL, BYTE* pData, int Length);
	BYTE* ReadScorcoData(char* SQL, char *param, BOOL* pSqlError, int *size);

	const char* GetErrorMessage ();

private:
	void SaveSQLError ();
	HENV henv;         // Environment   
	HDBC hdbc;         // Connection handle
	HSTMT hstmt;       // Statement handle
	RETCODE rc;        // ODBC return value

	char lastError[SQL_MAX_MESSAGE_LENGTH+1];
	char columnData[MAX_DATA];
	SDWORD cbData;
};

#endif // !defined(AFX_ODBC1_H__4A61FC82_E6C6_49CE_8D1D_4E99995AFA3E__INCLUDED_)
