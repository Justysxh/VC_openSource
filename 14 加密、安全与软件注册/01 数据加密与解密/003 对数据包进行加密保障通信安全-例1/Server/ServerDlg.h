// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__EED171E5_03A5_4268_9368_D7C93F4CD789__INCLUDED_)
#define AFX_SERVERDLG_H__EED171E5_03A5_4268_9368_D7C93F4CD789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ServerSocket.h"
#include "ClientSocket.h"

const int BUFFERSIZE = 200;
/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerSocket;
class CClientSocket;
class CServerDlg : public CDialog
{
// Construction
public:
	void ReceiveData(CClientSocket* socket);
	void AcceptConnect();
	void OnClose(CClientSocket * socket);
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

	CServerSocket* m_pSocket;
	CClientSocket* m_pClient;

	CPtrList m_socketlist;
	
// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CStatic	m_name;
	CStatic	m_port;
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
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__EED171E5_03A5_4268_9368_D7C93F4CD789__INCLUDED_)
