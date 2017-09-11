// SuperConnectDlg.h : header file
//

#if !defined(AFX_SUPERCONNECTDLG_H__833B0438_BA00_42F4_A146_A8A33D4858E2__INCLUDED_)
#define AFX_SUPERCONNECTDLG_H__833B0438_BA00_42F4_A146_A8A33D4858E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SuperLabel.h"
/////////////////////////////////////////////////////////////////////////////
// CSuperConnectDlg dialog

class CSuperConnectDlg : public CDialog
{
// Construction
public:
	CSuperConnectDlg(CWnd* pParent = NULL);	// standard constructor

	CSuperLabel m_Lebel;

// Dialog Data
	//{{AFX_DATA(CSuperConnectDlg)
	enum { IDD = IDD_SUPERCONNECT_DIALOG };
	CSuperLabel	m_Connect;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSuperConnectDlg)
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

#endif // !defined(AFX_SUPERCONNECTDLG_H__833B0438_BA00_42F4_A146_A8A33D4858E2__INCLUDED_)
