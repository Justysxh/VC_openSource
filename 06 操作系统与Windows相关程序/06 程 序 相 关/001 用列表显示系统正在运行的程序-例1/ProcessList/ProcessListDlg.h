// ProcessListDlg.h : header file
//

#if !defined(AFX_PROCESSLISTDLG_H__947DBDC6_4CE8_4C23_B78F_DC26580C3402__INCLUDED_)
#define AFX_PROCESSLISTDLG_H__947DBDC6_4CE8_4C23_B78F_DC26580C3402__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProcessListDlg dialog

class CProcessListDlg : public CDialog
{
// Construction
public:
	CProcessListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessListDlg)
	enum { IDD = IDD_PROCESSLIST_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProcessListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSLISTDLG_H__947DBDC6_4CE8_4C23_B78F_DC26580C3402__INCLUDED_)
