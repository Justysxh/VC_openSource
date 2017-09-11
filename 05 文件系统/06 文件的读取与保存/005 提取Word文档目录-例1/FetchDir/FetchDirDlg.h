// FetchDirDlg.h : header file
//

#if !defined(AFX_FETCHDIRDLG_H__87D99B2E_B993_4823_A700_D751AAFAE5DA__INCLUDED_)
#define AFX_FETCHDIRDLG_H__87D99B2E_B993_4823_A700_D751AAFAE5DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchDirDlg dialog

class CFetchDirDlg : public CDialog
{
// Construction
public:
	CFetchDirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFetchDirDlg)
	enum { IDD = IDD_FETCHDIR_DIALOG };
	CListBox	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchDirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFetch();
	afx_msg void OnSaveToFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHDIRDLG_H__87D99B2E_B993_4823_A700_D751AAFAE5DA__INCLUDED_)
