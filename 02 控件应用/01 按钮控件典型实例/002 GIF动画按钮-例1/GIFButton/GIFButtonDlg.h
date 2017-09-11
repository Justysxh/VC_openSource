// GIFButtonDlg.h : header file
//

#if !defined(AFX_GIFBUTTONDLG_H__41F8D852_950A_4D84_8E75_93298C715E8F__INCLUDED_)
#define AFX_GIFBUTTONDLG_H__41F8D852_950A_4D84_8E75_93298C715E8F__INCLUDED_
#include "ButtonGif.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGIFButtonDlg dialog

class CGIFButtonDlg : public CDialog
{
// Construction
public:
	CGIFButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGIFButtonDlg)
	enum { IDD = IDD_GIFBUTTON_DIALOG };
	CButtonGif	m_gif;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGIFButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGIFButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GIFBUTTONDLG_H__41F8D852_950A_4D84_8E75_93298C715E8F__INCLUDED_)
