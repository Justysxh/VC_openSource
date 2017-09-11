// TextInListDlg.h : header file
//

#if !defined(AFX_TEXTINLISTDLG_H__9E21DA9E_DCBD_4FC9_9561_5CDF01620B5F__INCLUDED_)
#define AFX_TEXTINLISTDLG_H__9E21DA9E_DCBD_4FC9_9561_5CDF01620B5F__INCLUDED_
#include "GridList.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextInListDlg dialog

class CTextInListDlg : public CDialog
{
// Construction
public:
	CTextInListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTextInListDlg)
	enum { IDD = IDD_TEXTINLIST_DIALOG };
	CGridList	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextInListDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextInListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButsave();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTINLISTDLG_H__9E21DA9E_DCBD_4FC9_9561_5CDF01620B5F__INCLUDED_)
