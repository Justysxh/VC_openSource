// AddShortcutDlg.h : header file
//

#if !defined(AFX_ADDSHORTCUTDLG_H__8E8D3E63_5911_4BF3_994E_463A7540B96D__INCLUDED_)
#define AFX_ADDSHORTCUTDLG_H__8E8D3E63_5911_4BF3_994E_463A7540B96D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAddShortcutDlg dialog

class CAddShortcutDlg : public CDialog
{
// Construction
public:
	CAddShortcutDlg(CWnd* pParent = NULL);	// standard constructor
	CString pathname;
	CString strname;
// Dialog Data
	//{{AFX_DATA(CAddShortcutDlg)
	enum { IDD = IDD_ADDSHORTCUT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddShortcutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddShortcutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDesktop();
	afx_msg void OnGroup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSHORTCUTDLG_H__8E8D3E63_5911_4BF3_994E_463A7540B96D__INCLUDED_)
