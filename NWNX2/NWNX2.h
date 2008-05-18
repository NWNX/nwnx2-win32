/***************************************************************************
    NWNX2.h - main header file for the NWNX2 application
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

#if !defined(AFX_NWNX2_H__198F0636_21B1_4540_BDA5_6E4879ABAD33__INCLUDED_)
#define AFX_NWNX2_H__198F0636_21B1_4540_BDA5_6E4879ABAD33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "NWNX2Dlg.h"
#include "cmdlineargs.h"
#include "nwnserver.h"
#include "../NWNXdll/IniFile.h"


/////////////////////////////////////////////////////////////////////////////
// CNWNX2App:
// See NWNX2.cpp for the implementation of this class
//

class CNWNX2App : public CWinApp
{
public:
	CNWNX2App();
	void parseNWNCmdLine();
	void parseIniFile();

	CNWNX2Dlg dlg;
	COleDateTime startTime;
	char *cmdline;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNWNX2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNWNX2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NWNX2_H__198F0636_21B1_4540_BDA5_6E4879ABAD33__INCLUDED_)
