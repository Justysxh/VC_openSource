// NetProcessActDlg.h : header file
//

#if !defined(AFX_NETPROCESSACTDLG_H__E4E2E42D_51C0_4F20_A687_94C899207160__INCLUDED_)
#define AFX_NETPROCESSACTDLG_H__E4E2E42D_51C0_4F20_A687_94C899207160__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "atlbase.h"
#include <Mshtml.h>
/////////////////////////////////////////////////////////////////////////////
// CNetProcessActDlg dialog

class CNetProcessActDlg : public CDialog
{
// Construction
public:
	CNetProcessActDlg(CWnd* pParent = NULL);	// standard constructor
	CComPtr<IDispatch> spDispatch;
	SHDocVw::IShellWindowsPtr m_spSHWinds;
// Dialog Data
	//{{AFX_DATA(CNetProcessActDlg)
	enum { IDD = IDD_NETPROCESSACT_DIALOG };
	CListCtrl	m_actlist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetProcessActDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetProcessActDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnExit();
	afx_msg void OnEnter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTray(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETPROCESSACTDLG_H__E4E2E42D_51C0_4F20_A687_94C899207160__INCLUDED_)
