// uuuuDlg.h : header file
//

#if !defined(AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_)
#define AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUuuuDlg dialog
#include "ClientSocket.h";
#include "ServerSocket.h"

class CClientSocket;
class CServerSocket;

class CUuuuDlg : public CDialog
{
// Construction
public:
	void ReceiveData(CClientSocket* sock);
	void AcceptConnect();
	CUuuuDlg(CWnd* pParent = NULL);	// standard constructor

	CServerSocket* m_pServerSock;
	CClientSocket* m_pClientSock;
	BOOL           m_IsStop;
	CFile          m_file;
	BOOL           m_IsRead;
	BOOL           m_IsReceived;
// Dialog Data
	//{{AFX_DATA(CUuuuDlg)
	enum { IDD = IDD_UUUU_DIALOG };
	CStatic	m_picture;
	UINT	m_Port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUuuuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUuuuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUUUDLG_H__B55657CD_B0A1_4DC0_8C0C_94BC1A7CE7A6__INCLUDED_)
