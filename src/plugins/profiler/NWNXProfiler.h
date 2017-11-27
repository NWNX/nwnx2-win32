/***************************************************************************
    NWNXProfiler.h - Interface for the CNWNXProfiler class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)

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

#if !defined(AFX_NWNXPROFILER_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
#define AFX_PROFILER_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_

#include "NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "hash.h"

class CNWNXProfiler : public CNWNXBase
{
	
public:
	CNWNXProfiler();
	virtual ~CNWNXProfiler();
	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	void LoadConfiguration();
	void WriteLogHeader();

	enum ELogLevel {logNothing, logStats, logCallstack};
	int	m_LogLevel;

};

#endif // !defined(AFX_PROFILER_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
