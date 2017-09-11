// FolderEncryDlg.h : header file
//

#if !defined(AFX_FOLDERENCRYDLG_H__630002AA_2FC5_4472_BD0B_348D99D11B44__INCLUDED_)
#define AFX_FOLDERENCRYDLG_H__630002AA_2FC5_4472_BD0B_348D99D11B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFolderEncryDlg dialog

class CFolderEncryDlg : public CDialog
{
// Construction
public:
	CFolderEncryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFolderEncryDlg)
	enum { IDD = IDD_FOLDERENCRY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolderEncryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFolderEncryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnEncry();
	afx_msg void OnUnEncry();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLDERENCRYDLG_H__630002AA_2FC5_4472_BD0B_348D99D11B44__INCLUDED_)
