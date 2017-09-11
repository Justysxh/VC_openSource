// FileRelatDlg.h : header file
//

#if !defined(AFX_FILERELATDLG_H__03E2B5DF_BF52_4CC1_8639_6C75B71EDCDF__INCLUDED_)
#define AFX_FILERELATDLG_H__03E2B5DF_BF52_4CC1_8639_6C75B71EDCDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileRelatDlg dialog

class CFileRelatDlg : public CDialog
{
// Construction
public:
	CFileRelatDlg(CWnd* pParent = NULL);	// standard constructor
	CString strname;
// Dialog Data
	//{{AFX_DATA(CFileRelatDlg)
	enum { IDD = IDD_FILERELAT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileRelatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileRelatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddicon();
	afx_msg void OnRel();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILERELATDLG_H__03E2B5DF_BF52_4CC1_8639_6C75B71EDCDF__INCLUDED_)
