// PrintFormDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc1.h"
//}}AFX_INCLUDES

#if !defined(AFX_PRINTFORMDLG_H__A510CD17_FC5B_4FC4_9FD7_B3075703674A__INCLUDED_)
#define AFX_PRINTFORMDLG_H__A510CD17_FC5B_4FC4_9FD7_B3075703674A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintFormDlg dialog


class CPrintFormDlg : public CDialog
{
// Construction
public:

	CPrintFormDlg(CWnd* pParent = NULL);	// standard constructor

	int x ;
// Dialog Data
	//{{AFX_DATA(CPrintFormDlg)
	enum { IDD = IDD_PRINTFORM_DIALOG };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintFormDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	
	// Generated message map functions
	//{{AFX_MSG(CPrintFormDlg)
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

#endif // !defined(AFX_PRINTFORMDLG_H__A510CD17_FC5B_4FC4_9FD7_B3075703674A__INCLUDED_)
