// ExecScriptDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_EXECSCRIPTDLG_H__109615DC_CA8A_4871_9586_CFC6EE3ADE8C__INCLUDED_)
#define AFX_EXECSCRIPTDLG_H__109615DC_CA8A_4871_9586_CFC6EE3ADE8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExecScriptDlg dialog

class CExecScriptDlg : public CDialog
{
// Construction
public:
	CExecScriptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExecScriptDlg)
	enum { IDD = IDD_EXECSCRIPT_DIALOG };
	CWebBrowser2	m_webbrowser;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExecScriptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExecScriptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXECSCRIPTDLG_H__109615DC_CA8A_4871_9586_CFC6EE3ADE8C__INCLUDED_)
