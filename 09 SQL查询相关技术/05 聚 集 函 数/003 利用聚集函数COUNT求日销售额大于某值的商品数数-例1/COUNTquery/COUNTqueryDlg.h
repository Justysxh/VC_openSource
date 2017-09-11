// COUNTqueryDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_COUNTQUERYDLG_H__EA31987E_6604_4279_8695_3714CADF8749__INCLUDED_)
#define AFX_COUNTQUERYDLG_H__EA31987E_6604_4279_8695_3714CADF8749__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCOUNTqueryDlg dialog

class CCOUNTqueryDlg : public CDialog
{
// Construction
public:
	CCOUNTqueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCOUNTqueryDlg)
	enum { IDD = IDD_COUNTQUERY_DIALOG };
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOUNTqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCOUNTqueryDlg)
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

#endif // !defined(AFX_COUNTQUERYDLG_H__EA31987E_6604_4279_8695_3714CADF8749__INCLUDED_)
