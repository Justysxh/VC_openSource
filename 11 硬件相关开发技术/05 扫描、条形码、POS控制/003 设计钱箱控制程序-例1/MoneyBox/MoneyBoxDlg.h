// MoneyBoxDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mdctogglebutton.h"
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_MONEYBOXDLG_H__5AE016F9_1721_44C6_AE0F_E28ADBAA9FA3__INCLUDED_)
#define AFX_MONEYBOXDLG_H__5AE016F9_1721_44C6_AE0F_E28ADBAA9FA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyLabel.h"
/////////////////////////////////////////////////////////////////////////////
// CMoneyBoxDlg dialog

class CMoneyBoxDlg : public CDialog
{
// Construction
public:
	CMoneyBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMoneyBoxDlg)
	enum { IDD = IDD_MONEYBOX_DIALOG };
	CListCtrl	m_List;
	CMyLabel	m_Title;
	CMSComm	m_Com;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoneyBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMoneyBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnOk2();
	afx_msg void OnCom1();
	afx_msg void OnCom2();
	afx_msg void OnCom3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONEYBOXDLG_H__5AE016F9_1721_44C6_AE0F_E28ADBAA9FA3__INCLUDED_)
