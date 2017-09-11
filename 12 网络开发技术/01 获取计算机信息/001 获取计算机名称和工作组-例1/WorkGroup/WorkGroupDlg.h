// WorkGroupDlg.h : header file
//

#if !defined(AFX_WORKGROUPDLG_H__E359443E_1E6A_484F_B649_075A40FA4762__INCLUDED_)
#define AFX_WORKGROUPDLG_H__E359443E_1E6A_484F_B649_075A40FA4762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWorkGroupDlg dialog

class CWorkGroupDlg : public CDialog
{
// Construction
public:
	CWorkGroupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkGroupDlg)
	enum { IDD = IDD_WORKGROUP_DIALOG };
	CEdit	m_edit;
	CListCtrl	m_grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWorkGroupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKGROUPDLG_H__E359443E_1E6A_484F_B649_075A40FA4762__INCLUDED_)
