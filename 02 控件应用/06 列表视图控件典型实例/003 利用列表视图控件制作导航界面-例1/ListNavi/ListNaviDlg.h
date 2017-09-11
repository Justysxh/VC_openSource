// ListNaviDlg.h : header file
//

#if !defined(AFX_LISTNAVIDLG_H__2679271E_E0B6_474A_9AED_26A2EF4E749A__INCLUDED_)
#define AFX_LISTNAVIDLG_H__2679271E_E0B6_474A_9AED_26A2EF4E749A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListNaviDlg dialog

class CListNaviDlg : public CDialog
{
// Construction
public:
	CListNaviDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListNaviDlg)
	enum { IDD = IDD_LISTNAVI_DIALOG };
	CListCtrl	m_mylist;
	CImageList m_imglst;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListNaviDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListNaviDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkImagelst(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTNAVIDLG_H__2679271E_E0B6_474A_9AED_26A2EF4E749A__INCLUDED_)
