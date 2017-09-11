// TextColorDlg.h : header file
//

#if !defined(AFX_TEXTCOLORDLG_H__FFE80244_724B_4E86_A467_A0FD3AA88020__INCLUDED_)
#define AFX_TEXTCOLORDLG_H__FFE80244_724B_4E86_A467_A0FD3AA88020__INCLUDED_
#include "ColorEdit.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextColorDlg dialog

class CTextColorDlg : public CDialog
{
// Construction
public:
	CTextColorDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CTextColorDlg)
	enum { IDD = IDD_TEXTCOLOR_DIALOG };
	CColorEdit	m_Edit4;
	CColorEdit	m_Edit3;
	CColorEdit	m_Edit2;
	CColorEdit	m_Edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTCOLORDLG_H__FFE80244_724B_4E86_A467_A0FD3AA88020__INCLUDED_)
