// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__F42F2875_14BF_46D3_97B8_765B7844CF33__INCLUDED_)
#define AFX_CLIENTDLG_H__F42F2875_14BF_46D3_97B8_765B7844CF33__INCLUDED_
#include "winsock2.h";
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	void LianJie();
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET m_client;
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButhide();
	afx_msg void OnButshow();
	afx_msg void OnButlogout();
	afx_msg void OnButclose();
	afx_msg void OnButreboot();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__F42F2875_14BF_46D3_97B8_765B7844CF33__INCLUDED_)
