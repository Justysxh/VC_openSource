// FilePartitionDlg.h : header file
//

#if !defined(AFX_FILEPARTITIONDLG_H__CC51F949_8F05_40FA_B757_28D6BA2A75A8__INCLUDED_)
#define AFX_FILEPARTITIONDLG_H__CC51F949_8F05_40FA_B757_28D6BA2A75A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFilePartitionDlg dialog

class CFilePartitionDlg : public CDialog
{
// Construction
public:
	CFilePartitionDlg(CWnd* pParent = NULL);	// standard constructor
	CString filename;
	CString filenamenoext;
	CString filenameext;
	CString FindPath(CString fullname);
// Dialog Data
	//{{AFX_DATA(CFilePartitionDlg)
	enum { IDD = IDD_FILEPARTITION_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilePartitionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFilePartitionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnAddDir();
	afx_msg void OnPartition();
	afx_msg void OnSelectPart();
	afx_msg void OnOmbin();
	afx_msg void OnChangeEdfilepath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEPARTITIONDLG_H__CC51F949_8F05_40FA_B757_28D6BA2A75A8__INCLUDED_)
