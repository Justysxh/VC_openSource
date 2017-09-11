// DeleteFolderDlg.h : header file
//

#if !defined(AFX_DELETEFOLDERDLG_H__A5670942_C5C7_4254_A069_E662ABBBB279__INCLUDED_)
#define AFX_DELETEFOLDERDLG_H__A5670942_C5C7_4254_A069_E662ABBBB279__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeleteFolderDlg dialog

class CDeleteFolderDlg : public CDialog
{
// Construction
public:
	void DelFolder(CString path);
	CDeleteFolderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteFolderDlg)
	enum { IDD = IDD_DELETEFOLDER_DIALOG };
	CEdit	m_path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteFolderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDeleteFolderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButdelete();
	afx_msg void OnButliulan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEFOLDERDLG_H__A5670942_C5C7_4254_A069_E662ABBBB279__INCLUDED_)
