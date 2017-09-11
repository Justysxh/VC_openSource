// SendMailWithAddDlg.h : header file
//

#if !defined(AFX_SENDMAILWITHADDDLG_H__4149E893_AD99_440A_96C9_2202FBA94FB6__INCLUDED_)
#define AFX_SENDMAILWITHADDDLG_H__4149E893_AD99_440A_96C9_2202FBA94FB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendMailWithAddDlg dialog

class CSendMailWithAddDlg : public CDialog
{
// Construction
public:
	CSendMailWithAddDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendMailWithAddDlg)
	enum { IDD = IDD_SENDMAILWITHADD_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendMailWithAddDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendMailWithAddDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnBtsend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDMAILWITHADDDLG_H__4149E893_AD99_440A_96C9_2202FBA94FB6__INCLUDED_)
