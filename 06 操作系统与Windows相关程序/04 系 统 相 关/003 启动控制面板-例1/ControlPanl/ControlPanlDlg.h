// ControlPanlDlg.h : header file
//

#if !defined(AFX_CONTROLPANLDLG_H__123D6D8B_9CA4_4784_B4D9_DA8BC2B3CD91__INCLUDED_)
#define AFX_CONTROLPANLDLG_H__123D6D8B_9CA4_4784_B4D9_DA8BC2B3CD91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "btnst.h"
/////////////////////////////////////////////////////////////////////////////
// CControlPanlDlg dialog

class CControlPanlDlg : public CDialog
{
// Construction
public:
	CControlPanlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControlPanlDlg)
	enum { IDD = IDD_CONTROLPANL_DIALOG };
	
	CButtonST	m_button9;
	CButtonST	m_button8;
	CButtonST	m_button7;
	CButtonST	m_button6;
	CButtonST	m_button5;
	CButtonST	m_button4;
	CButtonST	m_button3;
	CButtonST	m_button2;
	CButtonST	m_button12;
	CButtonST	m_button11;
	CButtonST	m_button10;
	CButtonST	m_button1;
	
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlPanlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HICON internet,mmsys,timedate,desk,access,mouse,keyboard,intl,appwiz,hdwwiz,sysdm,telephon;
	// Generated message map functions
	//{{AFX_MSG(CControlPanlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLPANLDLG_H__123D6D8B_9CA4_4784_B4D9_DA8BC2B3CD91__INCLUDED_)
