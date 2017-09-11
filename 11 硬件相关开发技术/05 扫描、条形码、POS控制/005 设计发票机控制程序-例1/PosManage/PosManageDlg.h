// PosManageDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_POSMANAGEDLG_H__0C0A84F0_770B_4C94_A2CE_AECA41C1F6B4__INCLUDED_)
#define AFX_POSMANAGEDLG_H__0C0A84F0_770B_4C94_A2CE_AECA41C1F6B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPosManageDlg dialog

class CPosManageDlg : public CDialog
{
// Construction
public:
	CPosManageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPosManageDlg)
	enum { IDD = IDD_POSMANAGE_DIALOG };
	CEdit	m_Send;
	CEdit	m_Receive;
	CMSComm	m_Com;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPosManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPosManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton5();
	afx_msg void OnCom1();
	afx_msg void OnCom2();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSMANAGEDLG_H__0C0A84F0_770B_4C94_A2CE_AECA41C1F6B4__INCLUDED_)
