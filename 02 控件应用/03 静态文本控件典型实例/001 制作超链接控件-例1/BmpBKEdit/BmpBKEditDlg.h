// BmpBKEditDlg.h : header file
//

#if !defined(AFX_BMPBKEDITDLG_H__CFA50016_2697_490A_B495_B6C6A05611B3__INCLUDED_)
#define AFX_BMPBKEDITDLG_H__CFA50016_2697_490A_B495_B6C6A05611B3__INCLUDED_
#include "BmpEdit.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpBKEditDlg dialog

class CBmpBKEditDlg : public CDialog
{
// Construction
public:
	CBmpBKEditDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CBmpBKEditDlg)
	enum { IDD = IDD_BMPBKEDIT_DIALOG };
	CBmpEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpBKEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpBKEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBKEDITDLG_H__CFA50016_2697_490A_B495_B6C6A05611B3__INCLUDED_)
