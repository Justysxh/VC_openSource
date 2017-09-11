// SqlqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_SQLQUERYDLG_H__5313DD43_104A_4F71_B760_F3015DCEDD37__INCLUDED_)
#define AFX_SQLQUERYDLG_H__5313DD43_104A_4F71_B760_F3015DCEDD37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSqlqueryDlg dialog

class CSqlqueryDlg : public CDialog
{
// Construction
public:
	CSqlqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSqlqueryDlg)
	enum { IDD = IDD_SQLQUERY_DIALOG };
	CComboBox	m_combo;
	CAdodc	m_adodc;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSqlqueryDlg)
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

#endif // !defined(AFX_SQLQUERYDLG_H__5313DD43_104A_4F71_B760_F3015DCEDD37__INCLUDED_)
