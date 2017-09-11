// FXtreeDlg.h : header file
//

#if !defined(AFX_FXTREEDLG_H__A068FA04_88D0_483A_BD8B_6E64EEFA23A1__INCLUDED_)
#define AFX_FXTREEDLG_H__A068FA04_88D0_483A_BD8B_6E64EEFA23A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFXtreeDlg dialog

class CFXtreeDlg : public CDialog
{
// Construction
public:
	CString str;
	CFXtreeDlg(CWnd* pParent = NULL);	// standard constructor
	void AddtoTree(HTREEITEM m_node,int UPID);//自定义函数
	HTREEITEM m_root;
	CImageList m_treeImageList;
	CStringArray a_id;
	CStringArray a_upid;
	CStringArray a_lx;
	CStringArray a_name;
	void Load_dep();
	void OuttoTree(HTREEITEM m_node);
// Dialog Data
	//{{AFX_DATA(CFXtreeDlg)
	enum { IDD = IDD_FXTREE_DIALOG };
	CRichEditCtrl	m_rich;
	CTreeCtrl	m_tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFXtreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFXtreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FXTREEDLG_H__A068FA04_88D0_483A_BD8B_6E64EEFA23A1__INCLUDED_)
