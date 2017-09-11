// ScrollPreviewDlg.h : header file
//

#if !defined(AFX_SCROLLPREVIEWDLG_H__EC18D2D0_B0E8_489D_AD2E_D87BACB2D513__INCLUDED_)
#define AFX_SCROLLPREVIEWDLG_H__EC18D2D0_B0E8_489D_AD2E_D87BACB2D513__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PreviewDialog.h"
/////////////////////////////////////////////////////////////////////////////
// CScrollPreviewDlg dialog

class CScrollPreviewDlg : public CDialog
{
// Construction
protected: 
	//打印预览窗口对象
	CPreviewDialog PreviewDlg;

public:
	CScrollPreviewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollPreviewDlg)
	enum { IDD = IDD_SCROLLPREVIEW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollPreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrollPreviewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLPREVIEWDLG_H__EC18D2D0_B0E8_489D_AD2E_D87BACB2D513__INCLUDED_)
