// RenameFileDlg.h : header file
//

#if !defined(AFX_RENAMEFILEDLG_H__DAE21E18_AAB6_4BC2_A940_D007180BE789__INCLUDED_)
#define AFX_RENAMEFILEDLG_H__DAE21E18_AAB6_4BC2_A940_D007180BE789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRenameFileDlg dialog

class CRenameFileDlg : public CDialog
{
// Construction
public:
	CRenameFileDlg(CWnd* pParent = NULL);	// standard constructor
	CString strpathname;
	CString strfilename;
	CString pathofpath;
// Dialog Data
	//{{AFX_DATA(CRenameFileDlg)
	enum { IDD = IDD_RENAMEFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRenameFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRenameFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPathAdd();
	afx_msg void OnNameAdd();
	afx_msg void OnPathSet();
	afx_msg void OnNameSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAMEFILEDLG_H__DAE21E18_AAB6_4BC2_A940_D007180BE789__INCLUDED_)
