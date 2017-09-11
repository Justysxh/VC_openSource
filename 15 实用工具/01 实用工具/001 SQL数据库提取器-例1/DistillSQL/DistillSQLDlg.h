// DistillSQLDlg.h : header file
//

#if !defined(AFX_DISTILLSQLDLG_H__AC1CA9D8_7C6D_42C8_AD77_BD313F73AD75__INCLUDED_)
#define AFX_DISTILLSQLDLG_H__AC1CA9D8_7C6D_42C8_AD77_BD313F73AD75__INCLUDED_
#include "ADO.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDistillSQLDlg dialog

class CDistillSQLDlg : public CDialog
{
// Construction
public:
	void GetTableFrame();
	void GetTableList();
	void FormatString(CString sText, CComboBox *pComboBox);
	CString GetServer();
	CDistillSQLDlg(CWnd* pParent = NULL);	// standard constructor
	CADO m_Ado;

// Dialog Data
	//{{AFX_DATA(CDistillSQLDlg)
	enum { IDD = IDD_DISTILLSQL_DIALOG };
	CListCtrl	m_Frame;
	CEdit	m_Pwd;
	CEdit	m_Name;
	CComboBox	m_Table;
	CComboBox	m_Database;
	CComboBox	m_Server;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistillSQLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDistillSQLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefurbish();
	afx_msg void OnLogin();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnToword();
	afx_msg void OnToexcel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTILLSQLDLG_H__AC1CA9D8_7C6D_42C8_AD77_BD313F73AD75__INCLUDED_)
