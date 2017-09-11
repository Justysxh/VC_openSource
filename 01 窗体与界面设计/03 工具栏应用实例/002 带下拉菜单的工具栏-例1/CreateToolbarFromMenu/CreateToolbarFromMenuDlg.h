// CreateToolbarFromMenuDlg.h : header file
//

#if !defined(AFX_CREATETOOLBARFROMMENUDLG_H__27237251_0087_46F5_991B_E9FD83479CA7__INCLUDED_)
#define AFX_CREATETOOLBARFROMMENUDLG_H__27237251_0087_46F5_991B_E9FD83479CA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateToolbarFromMenuDlg dialog

class CCreateToolbarFromMenuDlg : public CDialog
{
// Construction
public:
	CCreateToolbarFromMenuDlg(CWnd* pParent = NULL);	// standard constructor
	CToolBarCtrl m_toolbar;
	CImageList m_imagelist;
// Dialog Data
	//{{AFX_DATA(CCreateToolbarFromMenuDlg)
	enum { IDD = IDD_CREATETOOLBARFROMMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateToolbarFromMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateToolbarFromMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuClick(UINT nID);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETOOLBARFROMMENUDLG_H__27237251_0087_46F5_991B_E9FD83479CA7__INCLUDED_)
