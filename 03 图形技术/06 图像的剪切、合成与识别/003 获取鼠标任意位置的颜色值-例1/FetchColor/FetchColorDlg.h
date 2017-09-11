// FetchColorDlg.h : header file
//

#if !defined(AFX_FETCHCOLORDLG_H__8040452F_99EE_4CCE_9B7C_B335335211B3__INCLUDED_)
#define AFX_FETCHCOLORDLG_H__8040452F_99EE_4CCE_9B7C_B335335211B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchColorDlg dialog

class CFetchColorDlg : public CDialog
{
// Construction
public:
	void FetchColor(HWND m_handle,WORD lparam);
	CFetchColorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFetchColorDlg)
	enum { IDD = IDD_FETCHCOLOR_DIALOG };
	CStatic	m_test;
	CStatic	m_image;
	CEdit	m_red;
	CEdit	m_green;
	CEdit	m_blue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchColorDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHCOLORDLG_H__8040452F_99EE_4CCE_9B7C_B335335211B3__INCLUDED_)
