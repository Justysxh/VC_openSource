// ScanManageDlg.h : header file
//
//{{AFX_INCLUDES()
#include "imgscan.h"
#include "imgedit.h"
//}}AFX_INCLUDES

#if !defined(AFX_SCANMANAGEDLG_H__0E7C764C_E606_42FD_B20E_AA0A4DE202AB__INCLUDED_)
#define AFX_SCANMANAGEDLG_H__0E7C764C_E606_42FD_B20E_AA0A4DE202AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScanManageDlg dialog

class CScanManageDlg : public CDialog
{
// Construction
public:
	CScanManageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScanManageDlg)
	enum { IDD = IDD_SCANMANAGE_DIALOG };
	CImgScan	m_Scan;
	CImgEdit	m_ScanEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScanManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANMANAGEDLG_H__0E7C764C_E606_42FD_B20E_AA0A4DE202AB__INCLUDED_)
