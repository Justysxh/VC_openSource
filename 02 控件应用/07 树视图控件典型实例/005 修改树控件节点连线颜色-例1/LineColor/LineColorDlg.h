// LineColorDlg.h : header file
//

#if !defined(AFX_LINECOLORDLG_H__E46BDD6C_E1D4_4FC2_8135_45D245487604__INCLUDED_)
#define AFX_LINECOLORDLG_H__E46BDD6C_E1D4_4FC2_8135_45D245487604__INCLUDED_
#include "LineTree.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLineColorDlg dialog

class CLineColorDlg : public CDialog
{
// Construction
public:
	CLineColorDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CLineColorDlg)
	enum { IDD = IDD_LINECOLOR_DIALOG };
	CLineTree	m_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLineColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECOLORDLG_H__E46BDD6C_E1D4_4FC2_8135_45D245487604__INCLUDED_)
