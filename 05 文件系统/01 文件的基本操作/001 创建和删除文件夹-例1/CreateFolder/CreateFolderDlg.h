// CreateFolderDlg.h : header file
//

#if !defined(AFX_CREATEFOLDERDLG_H__04FBDF16_F7F7_456B_99FA_1FB673FBB4C4__INCLUDED_)
#define AFX_CREATEFOLDERDLG_H__04FBDF16_F7F7_456B_99FA_1FB673FBB4C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateFolderDlg dialog

class CCreateFolderDlg : public CDialog
{
// Construction
public:
	CString name;
	CCreateFolderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateFolderDlg)
	enum { IDD = IDD_CREATEFOLDER_DIALOG };
	CEdit	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateFolderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateFolderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButcreate();
	afx_msg void OnButdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEFOLDERDLG_H__04FBDF16_F7F7_456B_99FA_1FB673FBB4C4__INCLUDED_)
