// DJtreeDlg.h : header file
//

#if !defined(AFX_DJTREEDLG_H__F3503B81_4D20_4318_AA19_7CFE3E66462D__INCLUDED_)
#define AFX_DJTREEDLG_H__F3503B81_4D20_4318_AA19_7CFE3E66462D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDJtreeDlg dialog

class CDJtreeDlg : public CDialog
{
// Construction
public:
	CDJtreeDlg(CWnd* pParent = NULL);	// standard constructor
	void AddtoTree(HTREEITEM m_node,int UPID);//自定义函数
	HTREEITEM m_root;
	CStringArray a_id;
	CStringArray a_upid;
	CStringArray a_lx;
	CStringArray a_name;

	void Load_dep();
	CImageList m_treeImageList;
// Dialog Data
	//{{AFX_DATA(CDJtreeDlg)
	enum { IDD = IDD_DJTREE_DIALOG };
	CTreeCtrl	m_tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDJtreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDJtreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DJTREEDLG_H__F3503B81_4D20_4318_AA19_7CFE3E66462D__INCLUDED_)
