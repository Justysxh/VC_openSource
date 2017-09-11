// TreeTipDlg.h : header file
//

#if !defined(AFX_TREETIPDLG_H__BD34EB08_3D27_45BC_AF4E_E4E9F7B9E454__INCLUDED_)
#define AFX_TREETIPDLG_H__BD34EB08_3D27_45BC_AF4E_E4E9F7B9E454__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "tipwnd.h"
/////////////////////////////////////////////////////////////////////////////
// CTreeTipDlg dialog

class CTreeTipDlg : public CDialog
{
// Construction
public:
	CTreeTipDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeTipDlg)
	enum { IDD = IDD_TREETIP_DIALOG };
	treetipedit	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeTipDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreeTipDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREETIPDLG_H__BD34EB08_3D27_45BC_AF4E_E4E9F7B9E454__INCLUDED_)
