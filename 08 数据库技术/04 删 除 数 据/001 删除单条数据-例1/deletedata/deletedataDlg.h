// deletedataDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_DELETEDATADLG_H__AF4936C2_0C15_4814_B395_1432334AE8AF__INCLUDED_)
#define AFX_DELETEDATADLG_H__AF4936C2_0C15_4814_B395_1432334AE8AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeletedataDlg dialog

class CDeletedataDlg : public CDialog
{
// Construction
public:
	CDeletedataDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeletedataDlg)
	enum { IDD = IDD_DELETEDATA_DIALOG };
	CAdodc	m_adodc;
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeletedataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDeletedataDlg)
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

#endif // !defined(AFX_DELETEDATADLG_H__AF4936C2_0C15_4814_B395_1432334AE8AF__INCLUDED_)
