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

#if !defined(AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_)
#define AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>

#define OBJECT_INVALID 0x7F000000

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
	virtual BOOL OnCreate (const char* LogFile = NULL);

	///////////////////////////////////////////////////////////////////////////
	// Function: OnRequest (char* Request, char* Parameters)
	// Description
	//	Called when a request is pending from a NWScript.
	//	This function must be overloaded by the module.
	// Parameters
	//	Request		: the job that must be performed
	//  Parameters	: optional parameters
	virtual char* OnRequest (char *gameObject, char* Request, char* Parameters) = 0;

	///////////////////////////////////////////////////////////////////////////
	// Function: OnRequestObject (char* Request)
	// Description
	//	Called when a request is pending from a NWScript.
	//	This function must be overloaded by the module.
	//	Request		: the job that must be performed
	virtual unsigned long OnRequestObject (char *gameObject, char* Request);


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

	///////////////////////////////////////////////////////////////////////////
	// Function: Log (const char* pcMsg[, argument]...);
	// Description:
	//	This function formats and writes a message to the log file. It works
	//  the same way as the standard C printf function.
	//  Example: Log ("Set array item %d with value %s.", iIndex, pcValue);
	// Parameters:
	//	Msg			: the format string
	//  [argument]	: optional arguments
	void Log (int debugPri, const char* Msg, ...);
	void TimestampedLog (int debugPri, const char* Msg, ...);
	void WriteLogHeader();

	///////////////////////////////////////////////////////////////////////////
	// Function: SetDebugLevel (int level);
    // Description:
	//  Helper function to alter the instance's debuglevel independent of
	//  the global level.  Returns the old debuglevel.
	// Parameters:
	//  level	: the desired level
	int SetDebugLevel (int level);

	///////////////////////////////////////////////////////////////////////////
	// Function: BaseConf ();
    // Description:
	//  This function parses the generic config options: "debuglevel", etc.
	// Parameters:
	//  None
	void BaseConf ();

	FILE* m_fFile;
	char* m_LogFile;
	long m_maxLogSizeKB;
	char* confKey;
	int debuglevel;

protected:
	char acBuffer[65535];

};

#endif // !defined(AFX_NWNXBASE_H__3EFE2318_DB02_45C1_B2EA_28BA72475F77__INCLUDED_)
