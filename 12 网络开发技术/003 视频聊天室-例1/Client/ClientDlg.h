// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_)
#define AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
#include "ClientSock.h"

//定义数据包类型，文本和图像
enum PackageType  {ptText, ptImage};

//定义应用层数据包结构
class  CPackage
{
public:
	PackageType m_Type;
	DWORD		m_dwSize;	//数据报大小
	DWORD		m_dwContent;//数据包应包含数据大小
	DWORD		m_dwData;	//m_Data的大小
	BYTE		m_Data[];	//数据缓冲区
};



class CClientDlg : public CDialog
{
// Construction
public:
	void HandleRecData(CPackage* pPackage);
	BOOL InitSocket();
	void ReceiveData();
	CClientDlg(CWnd* pParent = NULL);	//standard constructor
	
	CClientSock m_ClientSock;
	HGLOBAL		m_hGlobal;				//全局堆句柄
	CPackage*	m_pPackage;
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CStatic	m_Image;
	CRichEditCtrl	m_InfoList;
	CEdit	m_SendContent;
	CEdit	m_ServerIP;
	CEdit	m_Port;
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
	virtual void OnOK();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__C6B823A7_C2D4_43F5_AA60_300AA6709F16__INCLUDED_)
