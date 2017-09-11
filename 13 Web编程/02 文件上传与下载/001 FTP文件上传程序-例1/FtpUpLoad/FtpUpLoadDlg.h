// FtpUpLoadDlg.h : header file
//

#if !defined(AFX_FTPUPLOADDLG_H__FEC78DF5_3950_48C2_B00F_B7AC6BB77DE9__INCLUDED_)
#define AFX_FTPUPLOADDLG_H__FEC78DF5_3950_48C2_B00F_B7AC6BB77DE9__INCLUDED_

#if _MSC_VER > 1000
#endif // _MSC_VER > 1000

#pragma once
/////////////////////////////////////////////////////////////////////////////
// CFtpUpLoadDlg dialog

class CFtpUpLoadDlg : public CDialog
{
// Construction
public:
	CFtpUpLoadDlg(CWnd* pParent = NULL);	// standard constructor
	CString strusr;
	CString strpwd;
	CString strip;
	CString strport;
	BOOL bconnect;
	CInternetSession *pInternetSession;
	CFtpConnection *pFtpConnection;
// Dialog Data
	//{{AFX_DATA(CFtpUpLoadDlg)
	enum { IDD = IDD_FTPUPLOAD_DIALOG };
	CListBox	m_ftpfilelst;
	CButton	m_noname;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpUpLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFtpUpLoadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnUPLoad();
	afx_msg void OnNoname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPUPLOADDLG_H__FEC78DF5_3950_48C2_B00F_B7AC6BB77DE9__INCLUDED_)
