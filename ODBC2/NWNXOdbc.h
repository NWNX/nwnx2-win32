/***************************************************************************
    NWNXODBC.h: interface for the CNWNXODBC class.
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
/* Change log:
 *
 * 16-12-2004 (Jeroen)
 *   - supports both ODBC and direct mysql
 */

#if !defined(AFX_NWNXARRAY_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
#define AFX_NWNXARRAY_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_

#include "../nwnxdll/NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <stdlib.h>
#include <mbstring.h>
#include <mysql.h>
#include "ODBC1.h"	// Added by ClassView
#include "mysql.h"
#include "sqlite.h"
#include "../NWNXdll/IniFile.h"
#include "scorcohook.h"

class CNWNXODBC : public CNWNXBase
{
public:
	CNWNXODBC();
	~CNWNXODBC();

	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	BOOL OnRelease();
	void WriteLogHeader();

	void WriteScorcoData(BYTE* pData, int Length);
	BYTE* ReadScorcoData(char *param, int *size);

protected:
	BOOL Connect();
	void Execute(const char* request);
	void Fetch(char* buffer, unsigned int buffersize);
	void SetScorcoSQL(char *request);
	bool LoadConfiguration ();

private:
	CDB* db;
	enum EDBType {dbNONE, dbODBC, dbMYSQL, dbSQLITE};
	int dbType;

	struct PARAMETERS {
		char *server;
		char *user;
		char *pass;
		char *db;
	} p;

	unsigned int request_counter;
	unsigned int sqlerror_counter;

	bool hookScorco;
	char* scorcoSQL;

	enum ELogLevel {logNothing, logErrors, logAll};
	int logLevel;
};

#endif // !defined(AFX_NWNXARRAY_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
