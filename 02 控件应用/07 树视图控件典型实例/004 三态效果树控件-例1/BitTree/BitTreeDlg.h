// BitTreeDlg.h : header file
//

#if !defined(AFX_BITTREEDLG_H__89B67E97_F3DA_4614_A73C_406F14F621AB__INCLUDED_)
#define AFX_BITTREEDLG_H__89B67E97_F3DA_4614_A73C_406F14F621AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBitTreeDlg dialog
#include "BitTreeCtl.h"
class CBitTreeDlg : public CDialog
{
// Construction
public:
	CBitTreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBitTreeDlg)
	enum { IDD = IDD_BITTREE_DIALOG };
	CBitTreeCtl	m_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CImageList m_ImageList;
	CImageList m_StateList;

	// Generated message map functions
	//{{AFX_MSG(CBitTreeDlg)
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

#endif // !defined(AFX_BITTREEDLG_H__89B67E97_F3DA_4614_A73C_406F14F621AB__INCLUDED_)
