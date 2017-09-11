// DomainNameDlg.h : header file
//

#if !defined(AFX_DOMAINNAMEDLG_H__61283E70_4486_4E6E_B03F_122365A3AA59__INCLUDED_)
#define AFX_DOMAINNAMEDLG_H__61283E70_4486_4E6E_B03F_122365A3AA59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDomainNameDlg dialog

class CDomainNameDlg : public CDialog
{
// Construction
public:
	CDomainNameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDomainNameDlg)
	enum { IDD = IDD_DOMAINNAME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDomainNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDomainNameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOMAINNAMEDLG_H__61283E70_4486_4E6E_B03F_122365A3AA59__INCLUDED_)
