// mohuqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_MOHUQUERYDLG_H__0396B500_89AD_4C79_BB42_5CACF6A5CFBE__INCLUDED_)
#define AFX_MOHUQUERYDLG_H__0396B500_89AD_4C79_BB42_5CACF6A5CFBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMohuqueryDlg dialog

class CMohuqueryDlg : public CDialog
{
// Construction
public:
	CMohuqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMohuqueryDlg)
	enum { IDD = IDD_MOHUQUERY_DIALOG };
	CComboBox	m_combo;
	CAdodc	m_adodc;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMohuqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMohuqueryDlg)
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

#endif // !defined(AFX_MOHUQUERYDLG_H__0396B500_89AD_4C79_BB42_5CACF6A5CFBE__INCLUDED_)
