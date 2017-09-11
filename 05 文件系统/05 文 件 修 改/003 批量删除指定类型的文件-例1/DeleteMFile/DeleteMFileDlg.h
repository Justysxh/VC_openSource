// DeleteMFileDlg.h : header file
//

#if !defined(AFX_DELETEMFILEDLG_H__446ED519_D5BB_482D_A478_55A3AD371441__INCLUDED_)
#define AFX_DELETEMFILEDLG_H__446ED519_D5BB_482D_A478_55A3AD371441__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeleteMFileDlg dialog

class CDeleteMFileDlg : public CDialog
{
// Construction
public:
	CDeleteMFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteMFileDlg)
	enum { IDD = IDD_DELETEMFILE_DIALOG };
	CListCtrl	m_filelist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteMFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDeleteMFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEMFILEDLG_H__446ED519_D5BB_482D_A478_55A3AD371441__INCLUDED_)
