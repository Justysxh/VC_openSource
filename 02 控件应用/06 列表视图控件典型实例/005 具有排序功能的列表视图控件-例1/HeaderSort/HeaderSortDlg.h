// HeaderSortDlg.h : header file
//

#if !defined(AFX_HEADERSORTDLG_H__2D070621_A6EF_4FCC_A9A3_AE5C61B2EA04__INCLUDED_)
#define AFX_HEADERSORTDLG_H__2D070621_A6EF_4FCC_A9A3_AE5C61B2EA04__INCLUDED_
#include "ListHeaderCtrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHeaderSortDlg dialog

class CHeaderSortDlg : public CDialog
{
// Construction
public:
	CHeaderSortDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHeaderSortDlg)
	enum { IDD = IDD_HEADERSORT_DIALOG };
	CListHeaderCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHeaderSortDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHeaderSortDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEADERSORTDLG_H__2D070621_A6EF_4FCC_A9A3_AE5C61B2EA04__INCLUDED_)
