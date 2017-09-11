// FileEncryDlg.h : header file
//

#if !defined(AFX_FILEENCRYDLG_H__56E53DE0_7E61_42C2_82BD_270574B2BFB5__INCLUDED_)
#define AFX_FILEENCRYDLG_H__56E53DE0_7E61_42C2_82BD_270574B2BFB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileEncryDlg dialog

class CFileEncryDlg : public CDialog
{
// Construction
public:
	CFileEncryDlg(CWnd* pParent = NULL);	// standard constructor
	CString strpathtemp;
// Dialog Data
	//{{AFX_DATA(CFileEncryDlg)
	enum { IDD = IDD_FILEENCRY_DIALOG };
	CStatic	m_filepath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileEncryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileEncryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnEncry();
	afx_msg void OnUnEncry();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEENCRYDLG_H__56E53DE0_7E61_42C2_82BD_270574B2BFB5__INCLUDED_)
