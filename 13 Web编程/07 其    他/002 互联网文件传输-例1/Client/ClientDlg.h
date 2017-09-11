// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__FF35012F_F82A_4839_8EF4_C8AB8F60516F__INCLUDED_)
#define AFX_CLIENTDLG_H__FF35012F_F82A_4839_8EF4_C8AB8F60516F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
#include "ClientSock.h"

//定义数据包类型，文本和文件
enum PackageType  {PTTEXT, PTFILE};

//文件发送标记，开始发送，发送过程中， 结束发送, 接受文件发送，拒绝接收文件，取消文件发送或接收
enum SendFlag {SFBEGIN, SFSENDING, SFEND, SFACCEPT, SFDENY, SFCANCEL};



//定义应用层数据包结构
//在文件开始发送时，数据缓冲区中前128个字节用于存储文件名，其后是文件数据, 
//而在文件发送过程中，数据缓冲区中均是文件数据

class  CPackage
{
public:
	PackageType m_Type;						//数据包类型
	SendFlag	m_Flag;						//文件发送标记
	DWORD		m_dwSize;					//数据报结构大小
	DWORD		m_dwFileSize;				//整个文件大小
	DWORD		m_dwData;					//m_Data的大小
	BYTE		m_Data[];					//数据缓冲区
};



class CClientDlg : public CDialog
{
// Construction
public:
	void HandleRecData(CPackage* pPackage);
	void ReceiveData();
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

	CClientSock m_ClientSock;
	HGLOBAL		m_hGlobal;				//全局堆句柄
	BOOL		m_bSending;				//文件是否处于发送过程中

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CEdit	m_ServerIP;
	CEdit	m_Port;
	CProgressCtrl	m_Progress;
	CButton	m_Cancel;
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
	afx_msg void OnExit();
	afx_msg void OnCancelRec();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__FF35012F_F82A_4839_8EF4_C8AB8F60516F__INCLUDED_)
