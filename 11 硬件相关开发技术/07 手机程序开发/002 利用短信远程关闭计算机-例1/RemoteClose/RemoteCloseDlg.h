// RemoteCloseDlg.h : header file
//

#if !defined(AFX_REMOTECLOSEDLG_H__9DE18E68_6B58_45E9_985C_2AC787F37704__INCLUDED_)
#define AFX_REMOTECLOSEDLG_H__9DE18E68_6B58_45E9_985C_2AC787F37704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRemoteCloseDlg dialog
#include "winsock2.h"
#pragma comment (lib,"ws2_32.lib")

#include "dllforvc.h"
#pragma comment (lib,"dllforvc.lib")

class CRemoteCloseDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	BOOL RemoteCloseWindows(LPCSTR remotename ,LPCSTR nameuser,LPCSTR pass,LPCSTR info,DWORD timeout);
	CRemoteCloseDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	//{{AFX_DATA(CRemoteCloseDlg)
	enum { IDD = IDD_REMOTECLOSE_DIALOG };
	CEdit	m_Pass;
	CIPAddressCtrl	m_IP;
	CEdit	m_Delay;
	CString m_Phone;

	BOOL m_IsSucc;  //是否成功关机
	BOOL m_IsSend;  //在关机失败时,防止连续发送短信

	
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemoteCloseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRemoteCloseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTECLOSEDLG_H__9DE18E68_6B58_45E9_985C_2AC787F37704__INCLUDED_)
