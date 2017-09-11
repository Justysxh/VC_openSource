// modviewDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_MODVIEWDLG_H__64F99333_556E_47C7_A4B5_8E15A491DE8E__INCLUDED_)
#define AFX_MODVIEWDLG_H__64F99333_556E_47C7_A4B5_8E15A491DE8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CModviewDlg dialog

class CModviewDlg : public CDialog
{
// Construction
public:
	CModviewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CModviewDlg)
	enum { IDD = IDD_MODVIEW_DIALOG };
	CAdodc	m_adodc;
	int		m_money;
	CString	m_name;
	CString	m_work;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CModviewDlg)
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

#endif // !defined(AFX_MODVIEWDLG_H__64F99333_556E_47C7_A4B5_8E15A491DE8E__INCLUDED_)
