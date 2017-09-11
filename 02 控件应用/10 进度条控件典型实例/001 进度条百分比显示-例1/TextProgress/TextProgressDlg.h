// TextProgressDlg.h : header file
//

#if !defined(AFX_TEXTPROGRESSDLG_H__9A763F8D_C66D_41CA_9173_34C581908F9E__INCLUDED_)
#define AFX_TEXTPROGRESSDLG_H__9A763F8D_C66D_41CA_9173_34C581908F9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextProgressDlg dialog
#include "TextProgress1.h"


class CTextProgressDlg : public CDialog
{
// Construction
public:
	CTextProgressDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTextProgressDlg)
	enum { IDD = IDD_TEXTPROGRESS_DIALOG };
	CTextProgress	m_Progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextProgressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPROGRESSDLG_H__9A763F8D_C66D_41CA_9173_34C581908F9E__INCLUDED_)
