// ClearhszDlg.h : header file
//

#if !defined(AFX_CLEARHSZDLG_H__0B2DC40E_82AC_4B2F_94E2_DAB04E6D93FD__INCLUDED_)
#define AFX_CLEARHSZDLG_H__0B2DC40E_82AC_4B2F_94E2_DAB04E6D93FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClearhszDlg dialog

class CClearhszDlg : public CDialog
{
// Construction
public:
	CClearhszDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClearhszDlg)
	enum { IDD = IDD_CLEARHSZ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClearhszDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClearhszDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButclear();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEARHSZDLG_H__0B2DC40E_82AC_4B2F_94E2_DAB04E6D93FD__INCLUDED_)
