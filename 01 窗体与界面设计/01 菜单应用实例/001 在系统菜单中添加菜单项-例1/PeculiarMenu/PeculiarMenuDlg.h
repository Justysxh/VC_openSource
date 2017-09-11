// PeculiarMenuDlg.h : header file
//

#if !defined(AFX_PECULIARMENUDLG_H__F15AE62A_72E2_4118_BF99_718AFD37DEB3__INCLUDED_)
#define AFX_PECULIARMENUDLG_H__F15AE62A_72E2_4118_BF99_718AFD37DEB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPeculiarMenuDlg dialog

class CPeculiarMenuDlg : public CDialog
{
// Construction
public:
	CMenu* m_pMenu;
	CPeculiarMenuDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CPeculiarMenuDlg)
	enum { IDD = IDD_PECULIARMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeculiarMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPeculiarMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PECULIARMENUDLG_H__F15AE62A_72E2_4118_BF99_718AFD37DEB3__INCLUDED_)
