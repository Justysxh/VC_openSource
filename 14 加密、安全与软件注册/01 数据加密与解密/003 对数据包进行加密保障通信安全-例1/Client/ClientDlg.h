// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__38944F34_A682_497D_9130_A81AF113AA4F__INCLUDED_)
#define AFX_CLIENTDLG_H__38944F34_A682_497D_9130_A81AF113AA4F__INCLUDED_
#include "Mysocket.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CMysocket;
/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
//
class CClientDlg : public CDialog
{
// Construction
public:
	void ReceiveData();
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
	CMysocket* pMysocket;
	CString Enjcrypt(CString s,WORD k);
	CString Decrypt(CString s,WORD k);
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CListBox	m_list;
	CEdit	m_info;
	CString	m_name;
	CString	m_servername;
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
	afx_msg void OnButtonsend();
	afx_msg void OnButtonjoin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__38944F34_A682_497D_9130_A81AF113AA4F__INCLUDED_)
