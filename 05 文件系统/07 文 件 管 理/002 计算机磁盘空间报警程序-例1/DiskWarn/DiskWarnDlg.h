// DiskWarnDlg.h : header file
//

#if !defined(AFX_DISKWARNDLG_H__613338A7_BD6B_49A7_B236_7FC3B1C72619__INCLUDED_)
#define AFX_DISKWARNDLG_H__613338A7_BD6B_49A7_B236_7FC3B1C72619__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskWarnDlg dialog

class CDiskWarnDlg : public CDialog
{
// Construction
public:
	CDiskWarnDlg(CWnd* pParent = NULL);	// standard constructor
	int sel;
	CString strwarn;
	CString strfreespace;
	ULARGE_INTEGER totalsize;
	ULARGE_INTEGER freesize;
	ULARGE_INTEGER availablesize;
// Dialog Data
	//{{AFX_DATA(CDiskWarnDlg)
	enum { IDD = IDD_DISKWARN_DIALOG };
	CComboBox	m_space;
	CListCtrl	m_disklist;
	CImageList imglist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskWarnDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskWarnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	afx_msg void OnTray(WPARAM wParam,LPARAM lParam);
	afx_msg void OnExit();
	afx_msg void OnSelchangeCmbspace();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKWARNDLG_H__613338A7_BD6B_49A7_B236_7FC3B1C72619__INCLUDED_)
