// FileExistDlg.h : header file
//

#if !defined(AFX_FILEEXISTDLG_H__43FDFF7E_7780_4045_89A3_5990B3F1BFC4__INCLUDED_)
#define AFX_FILEEXISTDLG_H__43FDFF7E_7780_4045_89A3_5990B3F1BFC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileExistDlg dialog

class CFileExistDlg : public CDialog
{
// Construction
public:
	CFileExistDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileExistDlg)
	enum { IDD = IDD_FILEEXIST_DIALOG };
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileExistDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileExistDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButok();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEEXISTDLG_H__43FDFF7E_7780_4045_89A3_5990B3F1BFC4__INCLUDED_)
