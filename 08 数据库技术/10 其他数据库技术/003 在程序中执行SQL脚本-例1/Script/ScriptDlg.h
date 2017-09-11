// ScriptDlg.h : header file
//

#if !defined(AFX_SCRIPTDLG_H__8D1BA2C6_808D_4E18_A59D_31CAC1F66DFC__INCLUDED_)
#define AFX_SCRIPTDLG_H__8D1BA2C6_808D_4E18_A59D_31CAC1F66DFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScriptDlg dialog

class CScriptDlg : public CDialog
{
// Construction
public:
	CScriptDlg(CWnd* pParent = NULL);	// standard constructor
	CString strText;
// Dialog Data
	//{{AFX_DATA(CScriptDlg)
	enum { IDD = IDD_SCRIPT_DIALOG };
	CStatic	m_Path;
	CRichEditCtrl	m_RichEdit;
	CString	m_Server;
	CString	m_Database;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScriptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButexecute();
	afx_msg void OnButselect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTDLG_H__8D1BA2C6_808D_4E18_A59D_31CAC1F66DFC__INCLUDED_)
