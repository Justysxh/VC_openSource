// FileInCallbackDlg.h : header file
//

#if !defined(AFX_FILEINCALLBACKDLG_H__AC765089_DF7B_46E6_8B38_215569DD1F24__INCLUDED_)
#define AFX_FILEINCALLBACKDLG_H__AC765089_DF7B_46E6_8B38_215569DD1F24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileInCallbackDlg dialog

class CFileInCallbackDlg : public CDialog
{
// Construction
public:
	CFileInCallbackDlg(CWnd* pParent = NULL);	// standard constructor
	CString strText;
// Dialog Data
	//{{AFX_DATA(CFileInCallbackDlg)
	enum { IDD = IDD_FILEINCALLBACK_DIALOG };
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileInCallbackDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileInCallbackDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButliulan();
	afx_msg void OnButdelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEINCALLBACKDLG_H__AC765089_DF7B_46E6_8B38_215569DD1F24__INCLUDED_)
