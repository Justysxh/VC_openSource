// EditShowDlg.h : header file
//

#if !defined(AFX_EDITSHOWDLG_H__6A219D0D_9E59_4798_93D1_465B51EB7931__INCLUDED_)
#define AFX_EDITSHOWDLG_H__6A219D0D_9E59_4798_93D1_465B51EB7931__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEditShowDlg dialog

class CEditShowDlg : public CDialog
{
// Construction
public:
	CEditShowDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CEditShowDlg)
	enum { IDD = IDD_EDITSHOW_DIALOG };
	CRichEditCtrl	m_RichEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEditShowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButfont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITSHOWDLG_H__6A219D0D_9E59_4798_93D1_465B51EB7931__INCLUDED_)
