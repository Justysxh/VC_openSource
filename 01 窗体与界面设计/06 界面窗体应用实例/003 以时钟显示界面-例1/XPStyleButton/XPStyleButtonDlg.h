// XPStyleButtonDlg.h : header file
//

#if !defined(AFX_XPSTYLEBUTTONDLG_H__CC00BF21_287D_48E5_ADEA_C6770C37060D__INCLUDED_)
#define AFX_XPSTYLEBUTTONDLG_H__CC00BF21_287D_48E5_ADEA_C6770C37060D__INCLUDED_
#include "CustomButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CXPStyleButtonDlg dialog

class CXPStyleButtonDlg : public CDialog
{
// Construction
public:
	CXPStyleButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CXPStyleButtonDlg)
	enum { IDD = IDD_XPSTYLEBUTTON_DIALOG };
	CCustomButton	m_Button8;
	CCustomButton	m_Button7;
	CCustomButton	m_Button6;
	CCustomButton	m_Button5;
	CCustomButton	m_Button4;
	CCustomButton	m_Button3;
	CCustomButton	m_Button2;
	CCustomButton	m_Button1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXPStyleButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CXPStyleButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XPSTYLEBUTTONDLG_H__CC00BF21_287D_48E5_ADEA_C6770C37060D__INCLUDED_)
