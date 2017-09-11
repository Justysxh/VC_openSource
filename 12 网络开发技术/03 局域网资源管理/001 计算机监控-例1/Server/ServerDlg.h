// ServerDlg.h : header file
//
#include "TCPServer.h"
#if !defined(AFX_SERVERDLG_H__BFB854F5_AC41_4EE5_889F_0C9B992F452A__INCLUDED_)
#define AFX_SERVERDLG_H__BFB854F5_AC41_4EE5_889F_0C9B992F452A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog,CTCPServerEvent
{
// Construction
protected:
	BITMAP bitmap;
	int size;
	char * bmpdata;
	void GetScreen();
protected:
	void SendBitData(CSocket *socket);
	void SendBitmap(CSocket *socket);
public:
	CTCPServerSocket serversocket;
	CServerDlg(CWnd* pParent = NULL);	// standard constructor
	virtual void OnReceive(CSocket * socket, int nErrorCode );
// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
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

#endif // !defined(AFX_SERVERDLG_H__BFB854F5_AC41_4EE5_889F_0C9B992F452A__INCLUDED_)
