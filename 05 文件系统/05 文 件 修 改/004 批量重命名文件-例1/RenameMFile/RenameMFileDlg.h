// RenameMFileDlg.h : header file
//

#if !defined(AFX_RENAMEMFILEDLG_H__8C038EDC_DE99_4E95_BAB7_F846C277DDF0__INCLUDED_)
#define AFX_RENAMEMFILEDLG_H__8C038EDC_DE99_4E95_BAB7_F846C277DDF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRenameMFileDlg dialog

class CRenameMFileDlg : public CDialog
{
// Construction
public:
	CRenameMFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRenameMFileDlg)
	enum { IDD = IDD_RENAMEMFILE_DIALOG };
	CListCtrl	m_filelist;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRenameMFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRenameMFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddFile();
	afx_msg void OnReName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAMEMFILEDLG_H__8C038EDC_DE99_4E95_BAB7_F846C277DDF0__INCLUDED_)
