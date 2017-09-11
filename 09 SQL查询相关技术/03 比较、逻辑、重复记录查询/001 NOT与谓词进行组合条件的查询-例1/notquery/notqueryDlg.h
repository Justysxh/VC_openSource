// notqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_NOTQUERYDLG_H__024A70AF_1B5E_42E2_B073_A245FD256F7A__INCLUDED_)
#define AFX_NOTQUERYDLG_H__024A70AF_1B5E_42E2_B073_A245FD256F7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNotqueryDlg dialog

class CNotqueryDlg : public CDialog
{
// Construction
public:
	int radio;
	CNotqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNotqueryDlg)
	enum { IDD = IDD_NOTQUERY_DIALOG };
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNotqueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTQUERYDLG_H__024A70AF_1B5E_42E2_B073_A245FD256F7A__INCLUDED_)
