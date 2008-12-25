/***************************************************************************
    NWNXBase.h: interface for the CNWNXBase class.
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com) and 
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

/**
 * Modified:
 * 24-10-2004
 *    - Moved the ini file class to this file.
 *    - Base class now opens the ini file for the module
 */

#if !defined(AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_)
#define AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>

class CIniFile  
{
public:
	CIniFile();
   CIniFile(LPCSTR lpszFileName);
	virtual ~CIniFile();

   bool open (LPCSTR lpszFileName);
	int ReadInteger (LPCSTR lpszSection, LPCSTR lpszKey, int iDefault);
	void ReadString (LPCSTR lpszSection, LPCSTR lpszKey, LPSTR lpszBuffer, int Size, LPCSTR lpszDefault);

//private:
	char m_szFileName[MAX_PATH];
};

class CNWNXBase  
{
public:
	CNWNXBase();
	virtual ~CNWNXBase();

	///////////////////////////////////////////////////////////////////////////
	// Function: OnCreate
	// Description
	//	This function is called just when an instance is created.
	//	Overloading is allowed, but the base class function must be called first.
	// Parameters
	//	LogFile		: optionally a path and filename of the log file
	virtual BOOL OnCreate (const char* logFileName = NULL);

	///////////////////////////////////////////////////////////////////////////
	// Function: OnRequest (char* Request, char* Parameters)
	// Description
	//	Called when a request is pending from a NWScript.
	//	This function must be overloaded by the module.
	// Parameters
	//	Request		: the job that must be performed
	//  Parameters	: optional parameters
	virtual char* OnRequest (char *gameObject, char* Request, char* Parameters);

	///////////////////////////////////////////////////////////////////////////
	// Function: OnRelease
	// Description
	//	Called just before deletion of an instance of this class.
	//	Overloading is allowed, but the base class function must be called.
	// Parameters
	//	None
	virtual BOOL OnRelease ();

	///////////////////////////////////////////////////////////////////////////
	// Function: Log (const char* pcMsg[, argument]...);
	// Description:
	//	This function formats and writes a message to the log file. It works
	//  the same way as the standard C printf function.
	//  Example: Log ("Set array item %d with value %s.", iIndex, pcValue);
	// Parameters:
	//	Msg			: the format string
	//  [argument]	: optional arguments
	void Log (const char* Msg, ...);

protected:
   CIniFile iniFile;

private:
	//HANDLE m_hFile;
	char* logFile;
	FILE* m_fFile;
};

#endif // !defined(AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_)
