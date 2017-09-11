// DragTreeItemDlg.h : header file
//

#if !defined(AFX_DRAGTREEITEMDLG_H__A4854AC1_DF3C_41F4_8B5E_61C45BDA61EC__INCLUDED_)
#define AFX_DRAGTREEITEMDLG_H__A4854AC1_DF3C_41F4_8B5E_61C45BDA61EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDragTreeItemDlg dialog
#include "DragTree.h"
class CDragTreeItemDlg : public CDialog
{
// Construction
public:
	CDragTreeItemDlg(CWnd* pParent = NULL);	// standard constructor

	CImageList m_ImageList; 
	

// Dialog Data
	//{{AFX_DATA(CDragTreeItemDlg)
	enum { IDD = IDD_DRAGTREEITEM_DIALOG };
	CDragTree	m_DragTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragTreeItemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDragTreeItemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGTREEITEMDLG_H__A4854AC1_DF3C_41F4_8B5E_61C45BDA61EC__INCLUDED_)
