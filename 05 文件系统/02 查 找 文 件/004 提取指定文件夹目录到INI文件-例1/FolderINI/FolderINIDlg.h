// FolderINIDlg.h : header file
//

#if !defined(AFX_FOLDERINIDLG_H__4DBE5B9A_854C_4A40_8F11_436833F8E3A0__INCLUDED_)
#define AFX_FOLDERINIDLG_H__4DBE5B9A_854C_4A40_8F11_436833F8E3A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFolderINIDlg dialog

class CFolderINIDlg : public CDialog
{
// Construction
public:
	CString Path;
	char buf[256];
	CString strName;
	CString folder;
	CFolderINIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFolderINIDlg)
	enum { IDD = IDD_FOLDERINI_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderINIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFolderINIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButselect();
	afx_msg void OnButdistill();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERINIDLG_H__4DBE5B9A_854C_4A40_8F11_436833F8E3A0__INCLUDED_)
