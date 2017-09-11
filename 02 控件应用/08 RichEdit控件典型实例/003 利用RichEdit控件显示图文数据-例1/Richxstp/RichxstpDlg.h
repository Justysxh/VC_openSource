// RichxstpDlg.h : header file
//

#if !defined(AFX_RICHXSTPDLG_H__BB71A06B_EA4F_4A8C_8E6B_E83153A139BA__INCLUDED_)
#define AFX_RICHXSTPDLG_H__BB71A06B_EA4F_4A8C_8E6B_E83153A139BA__INCLUDED_

#include "Newrich.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRichxstpDlg dialog

class CRichxstpDlg : public CDialog
{
// Construction
public:
	CRichxstpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRichxstpDlg)
	enum { IDD = IDD_RICHXSTP_DIALOG };
	CNewrich m_rich;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichxstpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRichxstpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButinsert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHXSTPDLG_H__BB71A06B_EA4F_4A8C_8E6B_E83153A139BA__INCLUDED_)
