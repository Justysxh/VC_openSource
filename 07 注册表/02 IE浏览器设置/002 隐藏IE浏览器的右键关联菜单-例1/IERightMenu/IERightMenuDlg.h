// IERightMenuDlg.h : header file
//

#if !defined(AFX_IERIGHTMENUDLG_H__8110B6B4_CBBF_484E_95DC_F03BEAC7DBAB__INCLUDED_)
#define AFX_IERIGHTMENUDLG_H__8110B6B4_CBBF_484E_95DC_F03BEAC7DBAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BtnST.h"
/////////////////////////////////////////////////////////////////////////////
// CIERightMenuDlg dialog

class CIERightMenuDlg : public CDialog
{
// Construction
public:
	CIERightMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIERightMenuDlg)
	enum { IDD = IDD_IERIGHTMENU_DIALOG };
	CButtonST	m_show;
	CButtonST	m_hide;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIERightMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIERightMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHide();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IERIGHTMENUDLG_H__8110B6B4_CBBF_484E_95DC_F03BEAC7DBAB__INCLUDED_)
