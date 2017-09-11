// PagesPreviewDlg.h : header file
//

#if !defined(AFX_PAGESPREVIEWDLG_H__12B257C1_13F5_4EA4_A4BD_31BF5934054C__INCLUDED_)
#define AFX_PAGESPREVIEWDLG_H__12B257C1_13F5_4EA4_A4BD_31BF5934054C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PreView.h"
/////////////////////////////////////////////////////////////////////////////
// CPagesPreviewDlg dialog

class CPagesPreviewDlg : public CDialog
{
// Construction
protected:
	CPreView preview;
public:
	CPagesPreviewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPagesPreviewDlg)
	enum { IDD = IDD_PAGESPREVIEW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPagesPreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPagesPreviewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPREVIEWDLG_H__12B257C1_13F5_4EA4_A4BD_31BF5934054C__INCLUDED_)
