// EncryptLockDlg.h : header file
//

#if !defined(AFX_ENCRYPTLOCKDLG_H__6BE366A2_CFBF_4EB9_BE90_5B19468B5036__INCLUDED_)
#define AFX_ENCRYPTLOCKDLG_H__6BE366A2_CFBF_4EB9_BE90_5B19468B5036__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEncryptLockDlg dialog

class CEncryptLockDlg : public CDialog
{
// Construction
public:
	CEncryptLockDlg(CWnd* pParent = NULL);	// standard constructor
//	CString strtext,Data;

// Dialog Data
	//{{AFX_DATA(CEncryptLockDlg)
	enum { IDD = IDD_ENCRYPTLOCK_DIALOG };
	CButton	m_Login;
	CEdit	m_Data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncryptLockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEncryptLockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButlogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTLOCKDLG_H__6BE366A2_CFBF_4EB9_BE90_5B19468B5036__INCLUDED_)
