// updateemptyDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_UPDATEEMPTYDLG_H__04F35155_4C8C_4A37_8030_B00780AC8EF0__INCLUDED_)
#define AFX_UPDATEEMPTYDLG_H__04F35155_4C8C_4A37_8030_B00780AC8EF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUpdateemptyDlg dialog

class CUpdateemptyDlg : public CDialog
{
// Construction
public:
	CUpdateemptyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdateemptyDlg)
	enum { IDD = IDD_UPDATEEMPTY_DIALOG };
	CAdodc	m_adodc;
	CString	m_name;
	CString	m_work;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateemptyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUpdateemptyDlg)
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

#endif // !defined(AFX_UPDATEEMPTYDLG_H__04F35155_4C8C_4A37_8030_B00780AC8EF0__INCLUDED_)
