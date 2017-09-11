// SendMsgDlg.h : header file
//

#if !defined(AFX_SENDMSGDLG_H__3D511E36_89AC_4307_83F0_2A9FAC259687__INCLUDED_)
#define AFX_SENDMSGDLG_H__3D511E36_89AC_4307_83F0_2A9FAC259687__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendMsgDlg dialog
#include "dllforvc.h"
#pragma comment (lib,"dllforvc.lib")

class CSendMsgDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	CSendMsgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendMsgDlg)
	enum { IDD = IDD_SENDMSG_DIALOG };
	CString	m_Baud;
	CString	m_MerID;
	CString	m_Accredit;
	CString	m_Port;
	CString	m_ReceiverID;
	CString	m_Content;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnGetinfo();
	afx_msg void OnSendinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDMSGDLG_H__3D511E36_89AC_4307_83F0_2A9FAC259687__INCLUDED_)
