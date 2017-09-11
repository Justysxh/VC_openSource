// ClearGarbageDlg.h : header file
//

#if !defined(AFX_CLEARGARBAGEDLG_H__4454AB0C_F001_429A_B99A_716A6BEEA81B__INCLUDED_)
#define AFX_CLEARGARBAGEDLG_H__4454AB0C_F001_429A_B99A_716A6BEEA81B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClearGarbageDlg dialog
#include "afxtempl.h" 


class CClearGarbageDlg : public CDialog
{
// Construction
public:
	BOOL IsTmpFile(CString szFileName);
	void ResearchFile(CString szPath);
	void GetTmpExtendedName();
	void EnumDisks();
	CClearGarbageDlg(CWnd* pParent = NULL);	// standard constructor
	CList<CString ,CString&> m_FilterList;		//临时文件扩展名
	HANDLE		m_hThread;
	BOOL		m_bFinding;						//查找进行中
	BOOL		m_bStopFind;
	CString		m_szScaneDisk;					//当前扫描的磁盘
// Dialog Data
	//{{AFX_DATA(CClearGarbageDlg)
	enum { IDD = IDD_CLEARGARBAGE_DIALOG };
	CListBox	m_DeleteLog;
	CStatic	m_FindProgress;
	CListCtrl	m_ScaneInfo;
	CComboBox	m_Disk;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClearGarbageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClearGarbageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSelectall();
	afx_msg void OnCancelSelAll();
	afx_msg void OnBeginScane();
	afx_msg void OnStopScane();
	afx_msg void OnDeleteAll();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEARGARBAGEDLG_H__4454AB0C_F001_429A_B99A_716A6BEEA81B__INCLUDED_)
