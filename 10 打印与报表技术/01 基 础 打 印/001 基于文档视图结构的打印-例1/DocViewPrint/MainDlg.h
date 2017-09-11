#if !defined(AFX_MAINDLG_H__43E6A418_F8EA_4F35_B5AA_7025F4728A3E__INCLUDED_)
#define AFX_MAINDLG_H__43E6A418_F8EA_4F35_B5AA_7025F4728A3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	virtual void OnCancel();
	CMainDlg(CWnd* pParent = NULL);   // standard constructor

	BOOL IsPreview;
// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAINDLG_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual void OnOK();
	afx_msg void OnPrint();
	afx_msg void OnQuit();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__43E6A418_F8EA_4F35_B5AA_7025F4728A3E__INCLUDED_)
