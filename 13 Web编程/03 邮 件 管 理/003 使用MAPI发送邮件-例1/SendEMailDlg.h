// SendEMailDlg.h : header file
//

#if !defined(AFX_SENDEMAILDLG_H__48EE34AA_9B8C_4C75_9F91_EF96DDA363E2__INCLUDED_)
#define AFX_SENDEMAILDLG_H__48EE34AA_9B8C_4C75_9F91_EF96DDA363E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendEMailDlg dialog

class CSendEMailDlg : public CDialog
{
// Construction
public:
	CSendEMailDlg(CWnd* pParent = NULL);	// standard constructor
	HMODULE result;
// Dialog Data
	//{{AFX_DATA(CSendEMailDlg)
	enum { IDD = IDD_SENDEMAIL_DIALOG };
	CEdit	m_subject;
	CEdit	m_ReceiverAddr;
	CEdit	m_content;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendEMailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendEMailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDEMAILDLG_H__48EE34AA_9B8C_4C75_9F91_EF96DDA363E2__INCLUDED_)
