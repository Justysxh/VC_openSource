// SizeStatusbarDlg.h : header file
//

#if !defined(AFX_SIZESTATUSBARDLG_H__96F6DC5E_52AD_486A_9A4B_756F0CC3F7BA__INCLUDED_)
#define AFX_SIZESTATUSBARDLG_H__96F6DC5E_52AD_486A_9A4B_756F0CC3F7BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSizeStatusbarDlg dialog

class CSizeStatusbarDlg : public CDialog
{
// Construction
public:
	CSizeStatusbarDlg(CWnd* pParent = NULL);	// standard constructor

	CStatusBar  m_StatusBar;
// Dialog Data
	//{{AFX_DATA(CSizeStatusbarDlg)
	enum { IDD = IDD_SIZESTATUSBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeStatusbarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSizeStatusbarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZESTATUSBARDLG_H__96F6DC5E_52AD_486A_9A4B_756F0CC3F7BA__INCLUDED_)
