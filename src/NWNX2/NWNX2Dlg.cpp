/***************************************************************************
    NWNX2Dlg.cpp - Dialog implementation file
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
#include "NWNX2Dlg.h"

#include "nwnserver.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNWNX2Dlg dialog

CNWNX2Dlg::CNWNX2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNWNX2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNWNX2Dlg)
	m_intLockupCounter = 0;
	m_strStarted = _T("");
	m_boolWatchdogProcess = FALSE;
	m_intUpdateIntervalProcess = 0;
	m_intCrashCounterProcess = 0;
	m_intCrashCounterGamespy = 0;
	m_boolWatchdogGamespy = FALSE;
	m_intUpdateIntervalGamespy = 0;
	m_intGamespyRetries = 0;
	m_intRestartDelay = 0;
	m_intServerPort = 0;
	m_strModuleName = _T("");
	m_boolOldGamespyProtocol = FALSE;
	//}}AFX_DATA_INIT
}

void CNWNX2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNWNX2Dlg)
	DDX_Text(pDX, IDC_LOCKUPCOUNTER, m_intLockupCounter);
	DDX_Text(pDX, IDC_STARTED, m_strStarted);
	DDX_Check(pDX, IDC_WATCHDOG_PROCESS, m_boolWatchdogProcess);
	DDX_Text(pDX, IDC_UPDATEINTERVALL_PROCESS, m_intUpdateIntervalProcess);
	DDX_Text(pDX, IDC_CRASHCOUNTER_PROCESS, m_intCrashCounterProcess);
	DDX_Text(pDX, IDC_CRASHCOUNTER_GAMESPY, m_intCrashCounterGamespy);
	DDX_Check(pDX, IDC_WATCHDOG_GAMESPY, m_boolWatchdogGamespy);
	DDX_Text(pDX, IDC_UPDATEINTERVALL_GAMESPY, m_intUpdateIntervalGamespy);
	DDX_Text(pDX, IDC_GAMESPY_RETRIES, m_intGamespyRetries);
	DDX_Text(pDX, IDC_SERVERPORT, m_intServerPort);
	DDX_Text(pDX, IDC_MODULENAME, m_strModuleName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNWNX2Dlg, CDialog)
	ON_MESSAGE(WM_SERVERRESTARTED_PROCESS, OnServerRestartedProcess)
	ON_MESSAGE(WM_SERVERRESTARTED_GAMESPY, OnServerRestartedGamespy)
	ON_MESSAGE(WM_SERVERRESTARTED_GAMESPY_LOCKUP, OnServerRestartedGamespyLockup)
	ON_MESSAGE(WM_PROCESS_STATE_CHECKING, OnProcessStateChecking)
	ON_MESSAGE(WM_PROCESS_STATE_NONE, OnProcessStateNone)
	ON_MESSAGE(WM_GAMESPY_STATE_CHECKING, OnGamespyStateChecking)
	ON_MESSAGE(WM_GAMESPY_STATE_NONE, OnGamespyStateNone)
	//{{AFX_MSG_MAP(CNWNX2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WATCHDOG_PROCESS, OnWatchdogProcess)
	ON_EN_CHANGE(IDC_UPDATEINTERVALL_PROCESS, OnChangeUpdateintervallProcess)
	ON_BN_CLICKED(IDC_WATCHDOG_GAMESPY, OnWatchdogGamespy)
	ON_EN_CHANGE(IDC_UPDATEINTERVALL_GAMESPY, OnChangeUpdateintervallGamespy)
	ON_EN_CHANGE(IDC_GAMESPY_RETRIES, OnChangeGamespyRetries)
	ON_BN_CLICKED(IDC_BTNABOUT, OnBtnabout)
	ON_WM_WINDOWPOSCHANGING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNWNX2Dlg message handlers

BOOL CNWNX2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);
	
	// Include module name in window title
	char title[80] = "NWNX2";	
	if (strlen(m_strModuleName) > 0)
	{	
		strcat(title, " - ");
		strcat(title, m_strModuleName);
	}
	SetWindowText(title);

	pProcessIcon = (CWnd*)GetDlgItem(IDC_PROCESS_ICON);	
	pGamespyIcon = (CWnd*)GetDlgItem(IDC_GAMESPY_ICON);	

	// Create and start watchdogs
	watchdogProcess = new CWatchdogProcess();
	watchdogProcess->setHwnd(GetSafeHwnd());
	watchdogProcess->setCmdLine(pCmdLine);
	watchdogProcess->setInterval(m_intUpdateIntervalProcess * 1000);
	if (m_boolWatchdogProcess)
		watchdogProcess->StartThread();

	watchdogGamespy = new CWatchdogGamespy();
	watchdogGamespy->setHwnd(GetSafeHwnd());
	watchdogGamespy->setCmdLine(pCmdLine);
	watchdogGamespy->setPort(m_intServerPort);
	watchdogGamespy->setInterval(m_intUpdateIntervalGamespy * 1000);
	watchdogGamespy->setRetries(m_intGamespyRetries);
	watchdogGamespy->UseOldGamespyProtocol(m_boolOldGamespyProtocol); 
	if (m_boolWatchdogGamespy)
		watchdogGamespy->StartThread();

	// Start nwserver using a seperate thread.
	// This is to prevent NWNX2 from stealing nwserver's focus, which in 
	// turn would make nwserver not set the server name properly (arg...)
	DWORD dwThreadId;
	HANDLE hThread; 
	hThread = CreateThread(NULL, 0, StartServerDummyThread, pCmdLine, 0, &dwThreadId);                
	CloseHandle(hThread);

	return TRUE;
}

void CNWNX2Dlg::OnBtnabout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNWNX2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR CNWNX2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

LRESULT CNWNX2Dlg::OnServerRestartedProcess(WPARAM wParam, LPARAM lParam)
{
	m_intCrashCounterProcess++;
	UpdateData(FALSE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnServerRestartedGamespy(WPARAM wParam, LPARAM lParam)
{
	m_intCrashCounterGamespy++;
	UpdateData(FALSE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnServerRestartedGamespyLockup(WPARAM wParam, LPARAM lParam)
{
	m_intLockupCounter++;
	UpdateData(FALSE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnProcessStateChecking(WPARAM wParam, LPARAM lParam)
{
	pProcessIcon->ShowWindow(SW_RESTORE);
	watchdogGamespy->doSleep(TRUE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnProcessStateNone(WPARAM wParam, LPARAM lParam)
{
	pProcessIcon->ShowWindow(SW_HIDE);
	watchdogGamespy->doSleep(FALSE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnGamespyStateChecking(WPARAM wParam, LPARAM lParam)
{
	pGamespyIcon->ShowWindow(SW_RESTORE);
	watchdogProcess->doSleep(TRUE);
	return NULL;
}

LRESULT CNWNX2Dlg::OnGamespyStateNone(WPARAM wParam, LPARAM lParam)
{
	pGamespyIcon->ShowWindow(SW_HIDE);
	watchdogProcess->doSleep(FALSE);
	return NULL;
}

void CNWNX2Dlg::OnWatchdogProcess() 
{
	UpdateData(TRUE);
	if (m_boolWatchdogProcess && m_intUpdateIntervalProcess >= 1)
		watchdogProcess->StartThread();
	else
	{
		watchdogProcess->StopThread();
		m_boolWatchdogProcess = FALSE;
		UpdateData(FALSE);
	}
}

void CNWNX2Dlg::OnWatchdogGamespy() 
{
	UpdateData(TRUE);
	if (m_boolWatchdogGamespy && m_intUpdateIntervalGamespy >= 1)
		watchdogGamespy->StartThread();
	else
	{
		watchdogGamespy->StopThread();
		m_boolWatchdogGamespy = FALSE;
		UpdateData(FALSE);
	}
}

void CNWNX2Dlg::OnChangeUpdateintervallProcess() 
{
	UpdateData(TRUE);

	if (m_intUpdateIntervalProcess < 1)
	{
		m_boolWatchdogProcess = FALSE;
		UpdateData(FALSE);
		OnWatchdogProcess();
	}

	watchdogProcess->setInterval(m_intUpdateIntervalProcess * 1000);
}

void CNWNX2Dlg::OnChangeUpdateintervallGamespy() 
{
	UpdateData(TRUE);
	if (m_intUpdateIntervalGamespy < 1)
	{
		m_boolWatchdogGamespy = FALSE;
		UpdateData(FALSE);
		OnWatchdogGamespy();
	}

	watchdogGamespy->setInterval(m_intUpdateIntervalGamespy * 1000);
}

void CNWNX2Dlg::OnChangeGamespyRetries() 
{
	UpdateData(TRUE);
	if (m_intGamespyRetries == 0)
	{
		m_boolWatchdogGamespy = FALSE;
		UpdateData(FALSE);
		OnWatchdogGamespy();
	}

	watchdogGamespy->setRetries(m_intGamespyRetries);
}
