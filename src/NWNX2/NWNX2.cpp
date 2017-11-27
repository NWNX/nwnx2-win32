/***************************************************************************
    NWNX2.cpp - Defines the class behaviors for the application.
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
#include "NWNX2.h"

#include <string>

/////////////////////////////////////////////////////////////////////////////
// CNWNX2App

BEGIN_MESSAGE_MAP(CNWNX2App, CWinApp)
	//{{AFX_MSG_MAP(CNWNX2App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNWNX2App construction

CNWNX2App::CNWNX2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	 cmdline = new char[1024];
	 cmdline[0] = 0;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNWNX2App object

CNWNX2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CNWNX2App initialization

BOOL CNWNX2App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	// set default values and parse ini file
	parseIniFile();

	// Parse command line and delete NWNX2 specific switches
	parseNWNCmdLine();
	dlg.pCmdLine = cmdline;

	startTime = COleDateTime::GetCurrentTime();
	dlg.m_strStarted = startTime.Format();

	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CNWNX2App::parseIniFile()
{
	char buffer[256];
	CIniFile iniFile("nwnx.ini");

	dlg.m_intServerPort = iniFile.ReadInteger("NWNX", "ServerPort", 5121);
	iniFile.ReadString("NWNX", "ModuleName", buffer, 256, "");
	dlg.m_strModuleName = buffer;
	dlg.m_strModuleName = "\"" + dlg.m_strModuleName + "\"";
	dlg.m_boolWatchdogProcess = iniFile.ReadBool("NWNX", "WatchdogProcess", true);
	dlg.m_intUpdateIntervalProcess = iniFile.ReadInteger("NWNX", "UpdateIntervalProcess", 5);
	dlg.m_boolWatchdogGamespy = iniFile.ReadBool("NWNX", "WatchdogGamespy", false);
	dlg.m_intUpdateIntervalGamespy = iniFile.ReadInteger("NWNX", "UpdateIntervalGamespy", 20);
	dlg.m_intGamespyRetries = iniFile.ReadInteger("NWNX", "GamespyRetries", 5);
	dlg.m_boolOldGamespyProtocol = iniFile.ReadBool("NWNX", "OldGamespyProtocol", false);
	dlg.m_intRestartDelay = iniFile.ReadInteger("NWNX", "RestartDelay", 5);
}

void CNWNX2App::parseNWNCmdLine()
{
	CmdLineArgs args;

	for (int i = 0; i < args.size(); i++)
	{
		if (stricmp(args[i], "-port") == 0)
		{
			dlg.m_intServerPort = atoi(args[i+1]);
			i++;
		}
		else if (stricmp(args[i], "-module") == 0)
		{
			dlg.m_strModuleName = args[i+1];
			i++;
		}
		else if (stricmp(args[i], "-processwatchdog") == 0)
		{
			if (atoi(args[i+1]) == 0)
				dlg.m_boolWatchdogProcess = false;
			else
				dlg.m_boolWatchdogProcess = true;
			i++;
		}
		else if (stricmp(args[i], "-processinterval") == 0)
		{
			dlg.m_intUpdateIntervalProcess = atoi(args[i+1]);
			i++;
		}
		else if (stricmp(args[i], "-gamespywatchdog") == 0)
		{
			if (atoi(args[i+1]) == 0)
				dlg.m_boolWatchdogGamespy = false;
			else
				dlg.m_boolWatchdogGamespy = true;
			i++;
		}
		else if (stricmp(args[i], "-gamespyinterval") == 0)
		{
			dlg.m_intUpdateIntervalGamespy = atoi(args[i+1]);
			i++;
		}
		else if (stricmp(args[i], "-gamespyretries") == 0)
		{
			dlg.m_intGamespyRetries = atoi(args[i+1]);
			i++;
		}
		else if (stricmp(args[i], "-oldgamespyprotocol") == 0)
		{
			if (atoi(args[i+1]) == 1)
				dlg.m_boolOldGamespyProtocol = true;
			i++;
		}
		else if (stricmp(args[i], "-publicserver") == 0)
		{
			if (atoi(args[i+1]) == 0)
				dlg.m_boolWatchdogGamespy = false;
			strcat(cmdline, args[i]);
			strcat(cmdline, " ");
		}
		else if (stricmp(args[i], "-restartdelay") == 0)
		{
			dlg.m_intRestartDelay = atoi(args[i+1]);
			i++;
		}
		else
		{
			strcat(cmdline, args[i]);
			strcat(cmdline, " ");
		}
	}

	char port[6];
	itoa(dlg.m_intServerPort, port, 10);
	strcat(cmdline, "-port ");
	strcat(cmdline, port);

	if (dlg.m_strModuleName != "")
	{
		strcat(cmdline, " -module ");
		strcat(cmdline, dlg.m_strModuleName);
	}
}
