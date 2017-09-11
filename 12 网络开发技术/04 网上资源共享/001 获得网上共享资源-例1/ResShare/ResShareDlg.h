// ResShareDlg.h : header file
//

#if !defined(AFX_RESSHAREDLG_H__C5526DB8_FEC7_498B_9B42_33BAB94903C7__INCLUDED_)
#define AFX_RESSHAREDLG_H__C5526DB8_FEC7_498B_9B42_33BAB94903C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CResShareDlg dialog

class CResShareDlg : public CDialog
{
// Construction
public:
	CResShareDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_imagelist;
	HTREEITEM m_Root,m_Group,m_Name;
// Dialog Data
	//{{AFX_DATA(CResShareDlg)
	enum { IDD = IDD_RESSHARE_DIALOG };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResShareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CResShareDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESSHAREDLG_H__C5526DB8_FEC7_498B_9B42_33BAB94903C7__INCLUDED_)
