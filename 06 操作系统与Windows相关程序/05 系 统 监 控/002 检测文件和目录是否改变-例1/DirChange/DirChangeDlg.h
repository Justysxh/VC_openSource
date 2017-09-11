// DirChangeDlg.h : header file
//

#if !defined(AFX_DIRCHANGEDLG_H__D5D6A149_974F_48DB_8C39_11F45D9607AE__INCLUDED_)
#define AFX_DIRCHANGEDLG_H__D5D6A149_974F_48DB_8C39_11F45D9607AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDirChangeDlg dialog

class CDirChangeDlg : public CDialog
{
// Construction
public:
	CString m_strWatchedDir;
	HANDLE m_hThread;//线程句柄
    HANDLE hDir;//文件目录名柄
	char* m_szi;
	int m_i;
	static DWORD WINAPI ThreadProc( LPVOID lParam ) ; //线程函数，用来监视
	bool StartThread();
	bool EndThread();
	bool OpenDir(char *pStartPath);
	CDirChangeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDirChangeDlg)
	enum { IDD = IDD_DIRCHANGE_DIALOG };
	CEdit	m_path;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirChangeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDirChangeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStrart();
	afx_msg void OnClose();
	afx_msg void OnSelectDir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRCHANGEDLG_H__D5D6A149_974F_48DB_8C39_11F45D9607AE__INCLUDED_)
