// GifPlayerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_GIFPLAYERDLG_H__0AA208A9_25C0_4840_BF0B_8BD3C57E3A98__INCLUDED_)
#define AFX_GIFPLAYERDLG_H__0AA208A9_25C0_4840_BF0B_8BD3C57E3A98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGifPlayerDlg dialog

class CGifPlayerDlg : public CDialog
{
// Construction
public:
	CGifPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGifPlayerDlg)
	enum { IDD = IDD_GIFPLAYER_DIALOG };
	CWebBrowser2	m_gifplayer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGifPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGifPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GIFPLAYERDLG_H__0AA208A9_25C0_4840_BF0B_8BD3C57E3A98__INCLUDED_)
