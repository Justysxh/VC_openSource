// TabCtrlDlg.h : header file
//

#if !defined(AFX_TABCTRLDLG_H__5DBD418A_B091_4B55_8634_8A40F0672F58__INCLUDED_)
#define AFX_TABCTRLDLG_H__5DBD418A_B091_4B55_8634_8A40F0672F58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTabCtrlDlg dialog
#include "NetTabCtrl.h"
#include "IndexDlg.h"



class CTabCtrlDlg : public CDialog
{
// Construction
public:
	CTabCtrlDlg(CWnd* pParent = NULL);	// standard constructor

	CImageList m_ImageList;
	CIndexDlg m_IndexDlg;

// Dialog Data
	//{{AFX_DATA(CTabCtrlDlg)
	enum { IDD = IDD_TABCTRL_DIALOG };
	CNetTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CTabCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCTRLDLG_H__5DBD418A_B091_4B55_8634_8A40F0672F58__INCLUDED_)
