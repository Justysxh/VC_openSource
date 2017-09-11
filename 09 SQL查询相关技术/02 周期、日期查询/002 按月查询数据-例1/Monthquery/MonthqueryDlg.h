// MonthqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_MONTHQUERYDLG_H__089F62E5_9A67_4DFA_BBA3_2F2DE8FB5D51__INCLUDED_)
#define AFX_MONTHQUERYDLG_H__089F62E5_9A67_4DFA_BBA3_2F2DE8FB5D51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMonthqueryDlg dialog

class CMonthqueryDlg : public CDialog
{
// Construction
public:
	CMonthqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMonthqueryDlg)
	enum { IDD = IDD_MONTHQUERY_DIALOG };
	CComboBox	m_combo;
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonthqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMonthqueryDlg)
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

#endif // !defined(AFX_MONTHQUERYDLG_H__089F62E5_9A67_4DFA_BBA3_2F2DE8FB5D51__INCLUDED_)
