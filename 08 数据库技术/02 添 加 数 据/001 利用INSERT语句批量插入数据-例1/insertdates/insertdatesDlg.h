// insertdatesDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_INSERTDATESDLG_H__37F16816_2144_4A74_B8FC_C1E4BA1DA91C__INCLUDED_)
#define AFX_INSERTDATESDLG_H__37F16816_2144_4A74_B8FC_C1E4BA1DA91C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInsertdatesDlg dialog

class CInsertdatesDlg : public CDialog
{
// Construction
public:
	CInsertdatesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CInsertdatesDlg)
	enum { IDD = IDD_INSERTDATES_DIALOG };
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertdatesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CInsertdatesDlg)
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

#endif // !defined(AFX_INSERTDATESDLG_H__37F16816_2144_4A74_B8FC_C1E4BA1DA91C__INCLUDED_)
