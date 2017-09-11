// ShadowDlg.h : header file
//

#if !defined(AFX_SHADOWDLG_H__931F7D45_E8BC_4154_AA90_92FC5C48D05D__INCLUDED_)
#define AFX_SHADOWDLG_H__931F7D45_E8BC_4154_AA90_92FC5C48D05D__INCLUDED_
#include "Shaddlg1.h"
#include "Shaddlg2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShadowDlg dialog

class CShadowDlg : public CDialog
{
// Construction
public:
	CShadowDlg(CWnd* pParent = NULL);	// standard constructor
	CShaddlg1 dlg1;
	CShaddlg2 dlg2;
// Dialog Data
	//{{AFX_DATA(CShadowDlg)
	enum { IDD = IDD_SHADOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShadowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShadowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMove(int x, int y);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHADOWDLG_H__931F7D45_E8BC_4154_AA90_92FC5C48D05D__INCLUDED_)
