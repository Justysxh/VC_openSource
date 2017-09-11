// NotRuleDlg.h : header file
//

#if !defined(AFX_NOTRULEDLG_H__B095C397_19BD_4E21_8F7F_660E1E226FEA__INCLUDED_)
#define AFX_NOTRULEDLG_H__B095C397_19BD_4E21_8F7F_660E1E226FEA__INCLUDED_
#include "CustomButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNotRuleDlg dialog

class CNotRuleDlg : public CDialog
{
// Construction
public:
	CNotRuleDlg(CWnd* pParent = NULL);	// standard constructor
	CCustomButton m_button;
	
// Dialog Data
	//{{AFX_DATA(CNotRuleDlg)
	enum { IDD = IDD_NOTRULE_DIALOG };
	CCustomButton	m_but6;
	CCustomButton	m_but5;
	CCustomButton	m_but4;
	CCustomButton	m_but3;
	CCustomButton	m_but2;
	CCustomButton	m_but1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotRuleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNotRuleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTRULEDLG_H__B095C397_19BD_4E21_8F7F_660E1E226FEA__INCLUDED_)
