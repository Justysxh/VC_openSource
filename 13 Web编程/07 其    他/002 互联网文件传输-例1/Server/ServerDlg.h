// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__EFCCE8FE_0A0C_4191_B7E7_D980FDFC82CC__INCLUDED_)
#define AFX_SERVERDLG_H__EFCCE8FE_0A0C_4191_B7E7_D980FDFC82CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog
#include "ServerSock.h"


//定义数据包类型，文本和文件
enum PackageType  {PTTEXT, PTFILE};

//文件发送标记，开始发送，发送过程中， 结束发送, 接受文件发送，拒绝接收文件，取消文件发送或接收
enum SendFlag {SFBEGIN, SFSENDING, SFEND, SFACCEPT, SFDENY, SFCANCEL};

//对方对发送文件的回答，接收，拒绝和取消(发送过程中)
enum RequestInfo {RIACCEPT, RIDENY, RICANCEL, RIUNKNOWN};

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


class CServerDlg : public CDialog
{
// Construction
public:
	void ReveiveData();
	void AcceptConnect();
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

	CServerSock	m_ServerSock;
	CServerSock m_ClientSock;
	BOOL		m_bSending;				//文件发送进行中
	HANDLE		m_hSendThread;			//发送文件的线程句柄
	RequestInfo	m_RequestInfo;
	CString		m_szFileName;			//发送的文件名称
// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CProgressCtrl	m_Progress;
	CEdit	m_FileName;
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
	virtual void OnCancel();
	afx_msg void OnBrowse();
	afx_msg void OnSendFile();
	afx_msg void OnSendCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__EFCCE8FE_0A0C_4191_B7E7_D980FDFC82CC__INCLUDED_)
