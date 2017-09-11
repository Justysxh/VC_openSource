// BindAppDlg.h : header file
//

#if !defined(AFX_BINDAPPDLG_H__F1466740_43B1_4ACE_AD31_34996DA6414D__INCLUDED_)
#define AFX_BINDAPPDLG_H__F1466740_43B1_4ACE_AD31_34996DA6414D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBindAppDlg dialog

#include <sys/stat.h>



class CBindAppDlg : public CDialog
{
// Construction
public:
	void RunExeFile(LPCTSTR  lpExeFile);
	void RunBindExe();
	CBindAppDlg(CWnd* pParent = NULL);	// standard constructor

	char		m_szSelfName[MAX_PATH];	//

// Dialog Data
	//{{AFX_DATA(CBindAppDlg)
	enum { IDD = IDD_BINDAPP_DIALOG };
	CEdit	m_File3;
	CEdit	m_File2;
	CEdit	m_File1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBindAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBindAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnCancel();
	afx_msg void OnBuild();
	afx_msg void OnBrowse1();
	afx_msg void OnBrowse2();
	afx_msg void OnBrowse3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINDAPPDLG_H__F1466740_43B1_4ACE_AD31_34996DA6414D__INCLUDED_)
