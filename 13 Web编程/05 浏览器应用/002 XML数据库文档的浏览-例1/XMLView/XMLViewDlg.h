// XMLViewDlg.h : header file
//

#if !defined(AFX_XMLVIEWDLG_H__D0A72BA4_C431_4273_BEA9_F9D05AC6882A__INCLUDED_)
#define AFX_XMLVIEWDLG_H__D0A72BA4_C431_4273_BEA9_F9D05AC6882A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXMLViewDlg dialog

class CXMLViewDlg : public CDialog
{
// Construction
public:
	CXMLViewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXMLViewDlg)
	enum { IDD = IDD_XMLVIEW_DIALOG };
	CListCtrl	m_xmllist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXMLViewDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXMLViewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLVIEWDLG_H__D0A72BA4_C431_4273_BEA9_F9D05AC6882A__INCLUDED_)
