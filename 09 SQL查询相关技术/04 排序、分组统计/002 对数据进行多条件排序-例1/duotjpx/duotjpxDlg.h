// duotjpxDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_DUOTJPXDLG_H__3C13924A_5307_4837_80BD_27E9DC362525__INCLUDED_)
#define AFX_DUOTJPXDLG_H__3C13924A_5307_4837_80BD_27E9DC362525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDuotjpxDlg dialog

class CDuotjpxDlg : public CDialog
{
// Construction
public:
	CDuotjpxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDuotjpxDlg)
	enum { IDD = IDD_DUOTJPX_DIALOG };
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDuotjpxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDuotjpxDlg)
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

#endif // !defined(AFX_DUOTJPXDLG_H__3C13924A_5307_4837_80BD_27E9DC362525__INCLUDED_)
