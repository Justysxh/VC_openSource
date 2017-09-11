// FileCopyDlg.h : header file
//

#if !defined(AFX_FILECOPYDLG_H__4020ABB8_298C_4E1E_B48D_79E10A9AA682__INCLUDED_)
#define AFX_FILECOPYDLG_H__4020ABB8_298C_4E1E_B48D_79E10A9AA682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg dialog

class CFileCopyDlg : public CDialog
{
// Construction
public:
	CFileCopyDlg(CWnd* pParent = NULL);	// standard constructor
	CString strname;
	CString fullname;
	CString pathname;
	HGLOBAL hGlobal;
	CFile* writefile;
	CFile* readfile;
	long readlen,poslen,filelen;
	LPVOID pvData;
// Dialog Data
	//{{AFX_DATA(CFileCopyDlg)
	enum { IDD = IDD_FILECOPY_DIALOG };
	CProgressCtrl	m_fileproc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileCopyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileCopyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnPut();
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILECOPYDLG_H__4020ABB8_298C_4E1E_B48D_79E10A9AA682__INCLUDED_)
