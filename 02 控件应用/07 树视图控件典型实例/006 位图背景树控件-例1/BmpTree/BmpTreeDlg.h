// BmpTreeDlg.h : header file
//

#if !defined(AFX_BMPTREEDLG_H__4A0C605E_1945_43BD_935D_BF1EC3CCC7FE__INCLUDED_)
#define AFX_BMPTREEDLG_H__4A0C605E_1945_43BD_935D_BF1EC3CCC7FE__INCLUDED_
#include "BitmapTree.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpTreeDlg dialog

class CBmpTreeDlg : public CDialog
{
// Construction
public:
	CBmpTreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpTreeDlg)
	enum { IDD = IDD_BMPTREE_DIALOG };
	CBitmapTree	m_Tree;
	CString	m_Source;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPTREEDLG_H__4A0C605E_1945_43BD_935D_BF1EC3CCC7FE__INCLUDED_)
