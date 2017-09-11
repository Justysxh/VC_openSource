// FtpDownDlg.h : header file
//

#if !defined(AFX_FTPDOWNDLG_H__A2D146D3_434C_4F1A_87B3_05A8159434E1__INCLUDED_)
#define AFX_FTPDOWNDLG_H__A2D146D3_434C_4F1A_87B3_05A8159434E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFtpDownDlg dialog
#include <afxmt.h>
#include <afxinet.h>
#pragma comment (lib,"wininet.lib")

class CFtpDownDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	CFtpDownDlg(CWnd* pParent = NULL);	// standard constructor
	
	UINT    m_ThreadCount; //线程数量
	DWORD   m_PerFileSize; //每个线程下载的文件大小
	DWORD   m_EndFileSize; //最后一个线程下载的文件大小

	HANDLE* m_pHthread;    //线程句柄 
	
	void**  m_pData;       //每个线程序下载数据的缓冲区,在每个线程均下载完成后合成一个完整的文件
	CEvent* m_pEvent;      //事件对象,用于线程同步

// Dialog Data
	//{{AFX_DATA(CFtpDownDlg)
	enum { IDD = IDD_FTPDOWN_DIALOG };
	CListCtrl	m_List;
	CString	m_Dir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpDownDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFtpDownDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPDOWNDLG_H__A2D146D3_434C_4F1A_87B3_05A8159434E1__INCLUDED_)
