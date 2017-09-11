// realplayerDlgDlg.h : header file
//
//{{AFX_INCLUDES()
#include "realaudio.h"
//}}AFX_INCLUDES

#if !defined(AFX_REALPLAYERDLGDLG_H__D7C76D46_D402_47E5_9B1D_76A3D4FC40EE__INCLUDED_)
#define AFX_REALPLAYERDLGDLG_H__D7C76D46_D402_47E5_9B1D_76A3D4FC40EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRealplayerDlgDlg dialog

class CRealplayerDlgDlg : public CDialog
{
// Construction
public:
	CRealplayerDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRealplayerDlgDlg)
	enum { IDD = IDD_REALPLAYERDLG_DIALOG };
	//}}AFX_DATA
	CRealAudio	m_realplayer;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealplayerDlgDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRealplayerDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnSoundAdd();
	afx_msg void OnSoundSub();
	afx_msg void OnProcAdd();
	afx_msg void OnProcSub();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALPLAYERDLGDLG_H__D7C76D46_D402_47E5_9B1D_76A3D4FC40EE__INCLUDED_)
