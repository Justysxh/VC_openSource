// GraspBmpDlg.h : header file
//

#if !defined(AFX_GRASPBMPDLG_H__417E4BC0_2DAE_41F2_BD7E_0AAC7035B607__INCLUDED_)
#define AFX_GRASPBMPDLG_H__417E4BC0_2DAE_41F2_BD7E_0AAC7035B607__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGraspBmpDlg dialog

class CGraspBmpDlg : public CDialog
{
// Construction
public:
	void StartGrasp();
	CGraspBmpDlg(CWnd* pParent = NULL);	// standard constructor
	int m_Num;
// Dialog Data
	//{{AFX_DATA(CGraspBmpDlg)
	enum { IDD = IDD_GRASPBMP_DIALOG };
	CHotKeyCtrl	m_HotKey;
	CButton	m_Cursor;
	CEdit	m_Path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraspBmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGraspBmpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButpath();
	afx_msg void OnHotKey(WPARAM wParam,LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnButsave();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRASPBMPDLG_H__417E4BC0_2DAE_41F2_BD7E_0AAC7035B607__INCLUDED_)
