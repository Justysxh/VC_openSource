// zdsjdqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_ZDSJDQUERYDLG_H__85A8E8F4_55D2_4564_94F6_B1B177F8B74B__INCLUDED_)
#define AFX_ZDSJDQUERYDLG_H__85A8E8F4_55D2_4564_94F6_B1B177F8B74B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZdsjdqueryDlg dialog

class CZdsjdqueryDlg : public CDialog
{
// Construction
public:
	CZdsjdqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZdsjdqueryDlg)
	enum { IDD = IDD_ZDSJDQUERY_DIALOG };
	CDateTimeCtrl	m_date2;
	CDateTimeCtrl	m_date1;
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZdsjdqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZdsjdqueryDlg)
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

#endif // !defined(AFX_ZDSJDQUERYDLG_H__85A8E8F4_55D2_4564_94F6_B1B177F8B74B__INCLUDED_)
