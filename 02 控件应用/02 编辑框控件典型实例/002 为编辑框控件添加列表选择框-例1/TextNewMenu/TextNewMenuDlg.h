// TextNewMenuDlg.h : header file
//

#if !defined(AFX_TEXTNEWMENUDLG_H__1E951537_557D_4E9C_BBD3_4B5AC559B7ED__INCLUDED_)
#define AFX_TEXTNEWMENUDLG_H__1E951537_557D_4E9C_BBD3_4B5AC559B7ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextNewMenuDlg dialog

class CTextNewMenuDlg : public CDialog
{
// Construction
public:
	CTextNewMenuDlg(CWnd* pParent = NULL);	// standard constructor
	CMenu menu;
// Dialog Data
	//{{AFX_DATA(CTextNewMenuDlg)
	enum { IDD = IDD_TEXTNEWMENU_DIALOG };
	CEdit	m_mytext;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextNewMenuDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextNewMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnView1();
	afx_msg void OnView2();
	afx_msg void OnView3();
	afx_msg void OnView4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTNEWMENUDLG_H__1E951537_557D_4E9C_BBD3_4B5AC559B7ED__INCLUDED_)
