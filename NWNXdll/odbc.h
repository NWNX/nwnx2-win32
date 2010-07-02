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

#pragma once

#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <stdlib.h>
#include <mbstring.h>

#define MAX_DATA 65536 // one column
#define MYSQLSUCCESS(rc) ((rc==SQL_SUCCESS)||(rc==SQL_SUCCESS_WITH_INFO))

class direxec
{
	FILE* logFile;
	RETCODE rc;        // ODBC return code
	HENV henv;         // Environment   
	HDBC hdbc;         // Connection handle
	HSTMT hstmt;       // Statement handle
	char szData[MAX_DATA];   // Returned data storage
	SDWORD cbData;     // Output length of data
	unsigned char chr_ds_name[SQL_MAX_DSN_LENGTH];   // Data source name
	char msg[SQL_MAX_MESSAGE_LENGTH+1]; // Message buffer
	unsigned int request_counter;
	unsigned int sqlerror_counter;
   
public:
	direxec();		 // Constructor
	bool sqlconn(FILE*);		 // Allocate env, stat, and conn
	bool ProcessRequest(char*, unsigned int);
	int sqlexec(char *, unsigned int);   // Execute SQL statement
	int sqlfetch(char*, unsigned int);	 // Fetch a row
	void sqldisconn();   // Free pointers to env, stat, conn,
						 // and disconnect
	char* direxec::error_msg();
	bool IsValidSQLStatement(unsigned char*);
	bool errorstate;	// TRUE is error occured
};
