// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__E8F42E26_A415_4045_9AAC_6109B1C6938C__INCLUDED_)
#define AFX_SERVERDLG_H__E8F42E26_A415_4045_9AAC_6109B1C6938C__INCLUDED_
#include "winsock2.h";
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	void HanShu();
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET m_server,m_client;
	CString m_serverIP;
// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__E8F42E26_A415_4045_9AAC_6109B1C6938C__INCLUDED_)
