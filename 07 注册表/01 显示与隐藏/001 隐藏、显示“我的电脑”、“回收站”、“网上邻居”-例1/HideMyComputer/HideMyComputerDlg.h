// HideMyComputerDlg.h : header file
//

#if !defined(AFX_HIDEMYCOMPUTERDLG_H__FABCD4C9_0F42_44F3_9FCD_21DA86AFB72F__INCLUDED_)
#define AFX_HIDEMYCOMPUTERDLG_H__FABCD4C9_0F42_44F3_9FCD_21DA86AFB72F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "btnst.h"
/////////////////////////////////////////////////////////////////////////////
// CHideMyComputerDlg dialog

class CHideMyComputerDlg : public CDialog
{
// Construction
public:
	CHideMyComputerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideMyComputerDlg)
	enum { IDD = IDD_HIDEMYCOMPUTER_DIALOG };
	CButtonST	m_srecy;
	CButtonST	m_snet;
	CButtonST	m_scomputer;
	CButtonST	m_hrecy;
	CButtonST	m_hnet;
	CButtonST	m_hcomputer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideMyComputerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HICON computer,recycle,network;
	// Generated message map functions
	//{{AFX_MSG(CHideMyComputerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHideComputer();
	afx_msg void OnShowComputer();
	afx_msg void OnHideRecy();
	afx_msg void OnShowRecy();
	afx_msg void OnHideNet();
	afx_msg void OnShowNet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDEMYCOMPUTERDLG_H__FABCD4C9_0F42_44F3_9FCD_21DA86AFB72F__INCLUDED_)
