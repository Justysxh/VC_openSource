// ChangeDirIconDlg.h : header file
//

#if !defined(AFX_CHANGEDIRICONDLG_H__2A2AA6FE_0E88_434F_A767_1523F9CAAAC7__INCLUDED_)
#define AFX_CHANGEDIRICONDLG_H__2A2AA6FE_0E88_434F_A767_1523F9CAAAC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Icons.h"
/////////////////////////////////////////////////////////////////////////////
// CChangeDirIconDlg dialog

class CChangeDirIconDlg : public CDialog
{
// Construction
public:
	CChangeDirIconDlg(CWnd* pParent = NULL);	// standard constructor
	CString strpath,extname,despath,desname;
	LPICONRESOURCE lpIR;
	CIcons *pIcons;
// Dialog Data
	//{{AFX_DATA(CChangeDirIconDlg)
	enum { IDD = IDD_CHANGEDIRICON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDirIconDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeDirIconDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSel();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDIRICONDLG_H__2A2AA6FE_0E88_434F_A767_1523F9CAAAC7__INCLUDED_)
