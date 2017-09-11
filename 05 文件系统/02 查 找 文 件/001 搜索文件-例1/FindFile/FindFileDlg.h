// FindFileDlg.h : header file
//

#if !defined(AFX_FINDFILEDLG_H__B8E89DBE_3C68_44F5_988D_56C2316F9BCC__INCLUDED_)
#define AFX_FINDFILEDLG_H__B8E89DBE_3C68_44F5_988D_56C2316F9BCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFindFileDlg dialog

class CFindFileDlg : public CDialog
{
// Construction
public:
	CFindFileDlg(CWnd* pParent = NULL);	// standard constructor
	void FindFile(CString strPath);
// Dialog Data
	//{{AFX_DATA(CFindFileDlg)
	enum { IDD = IDD_FINDFILE_DIALOG };
	CStatic	m_curfilename;
	CListBox	m_filelist;
	CString strfilename;
	BOOL bstop;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFindFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnFind();
	afx_msg void OnBtstop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDFILEDLG_H__B8E89DBE_3C68_44F5_988D_56C2316F9BCC__INCLUDED_)
