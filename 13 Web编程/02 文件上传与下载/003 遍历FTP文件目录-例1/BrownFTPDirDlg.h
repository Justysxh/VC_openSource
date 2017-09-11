// BrownFTPDirDlg.h : header file
//

#if !defined(AFX_BROWNFTPDIRDLG_H__8B177E92_68E6_4158_9C20_E497E063E715__INCLUDED_)
#define AFX_BROWNFTPDIRDLG_H__8B177E92_68E6_4158_9C20_E497E063E715__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxinet.h>
/////////////////////////////////////////////////////////////////////////////
// CBrownFTPDirDlg dialog

class CBrownFTPDirDlg : public CDialog
{
// Construction
public:
	void ListDir(CString dir,HTREEITEM hParent);
	CBrownFTPDirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBrownFTPDirDlg)
	enum { IDD = IDD_BROWNFTPDIR_DIALOG };
	CTreeCtrl	m_TreeInfo;
	CEdit	m_Port;
	CEdit	m_User;
	CEdit	m_Server;
	CEdit	m_Pass;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrownFTPDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBrownFTPDirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWNFTPDIRDLG_H__8B177E92_68E6_4158_9C20_E497E063E715__INCLUDED_)
