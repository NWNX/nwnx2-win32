/***************************************************************************
    NWNX2Dlg.cpp - Dialog header file
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

#if !defined(AFX_NWNX2DLG_H__164C5F1E_BCDB_4186_B501_2626D4DE8669__INCLUDED_)
#define AFX_NWNX2DLG_H__164C5F1E_BCDB_4186_B501_2626D4DE8669__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "watchdogprocess.h"
#include "watchdoggamespy.h"

/////////////////////////////////////////////////////////////////////////////
// CNWNX2Dlg dialog

class CNWNX2Dlg : public CDialog
{
// Construction
public:
	CNWNX2Dlg(CWnd* pParent = NULL);	// standard constructor

	CWatchdogProcess* watchdogProcess;
	CWatchdogGamespy* watchdogGamespy;

	CWnd* pProcessIcon;
	CWnd* pGamespyIcon;

	char* pCmdLine;

// Dialog Data
	//{{AFX_DATA(CNWNX2Dlg)
	enum { IDD = IDD_NWNX2_DIALOG };
	int m_intLockupCounter;
	CString	m_strStarted;
	BOOL	m_boolWatchdogProcess;
	int		m_intUpdateIntervalProcess;
	int		m_intCrashCounterProcess;
	int		m_intCrashCounterGamespy;
	BOOL	m_boolWatchdogGamespy;
	int		m_intUpdateIntervalGamespy;
	int		m_intGamespyRetries;
	int		m_intRestartDelay;
	int		m_intServerPort;
	CString	m_strModuleName;
	bool	m_boolOldGamespyProtocol;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNWNX2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	afx_msg LRESULT OnServerRestartedProcess(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnServerRestartedGamespy(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnServerRestartedGamespyLockup(WPARAM wParam, LPARAM lParam);

	afx_msg LRESULT OnProcessStateChecking(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnProcessStateNone(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGamespyStateChecking(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGamespyStateNone(WPARAM wParam, LPARAM lParam);

	// Generated message map functions
	//{{AFX_MSG(CNWNX2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWatchdogProcess();
	afx_msg void OnChangeUpdateintervallProcess();
	afx_msg void OnWatchdogGamespy();
	afx_msg void OnChangeUpdateintervallGamespy();
	afx_msg void OnChangeGamespyRetries();
	afx_msg void OnBtnabout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NWNX2DLG_H__164C5F1E_BCDB_4186_B501_2626D4DE8669__INCLUDED_)
