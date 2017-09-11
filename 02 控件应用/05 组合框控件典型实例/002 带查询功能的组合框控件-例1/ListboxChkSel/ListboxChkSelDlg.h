// ListboxChkSelDlg.h : header file
//

#if !defined(AFX_LISTBOXCHKSELDLG_H__8E8B885A_AA21_4635_B95D_365FA3FFFCC4__INCLUDED_)
#define AFX_LISTBOXCHKSELDLG_H__8E8B885A_AA21_4635_B95D_365FA3FFFCC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListboxChkSelDlg dialog

class CListboxChkSelDlg : public CDialog
{
// Construction
public:
	CListboxChkSelDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListboxChkSelDlg)
	enum { IDD = IDD_LISTBOXCHKSEL_DIALOG };
	CCheckListBox	m_chklist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListboxChkSelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListboxChkSelDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOper();
	afx_msg void OnDblclkChklist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXCHKSELDLG_H__8E8B885A_AA21_4635_B95D_365FA3FFFCC4__INCLUDED_)
