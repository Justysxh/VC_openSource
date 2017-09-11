// HideStartMenuDlg.h : header file
//

#if !defined(AFX_HIDESTARTMENUDLG_H__5A0BB5B3_4B4C_4FF6_8847_A69D95DADEA2__INCLUDED_)
#define AFX_HIDESTARTMENUDLG_H__5A0BB5B3_4B4C_4FF6_8847_A69D95DADEA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideStartMenuDlg dialog

class CHideStartMenuDlg : public CDialog
{
// Construction
public:
	CHideStartMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideStartMenuDlg)
	enum { IDD = IDD_HIDESTARTMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideStartMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHideStartMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHide();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDESTARTMENUDLG_H__5A0BB5B3_4B4C_4FF6_8847_A69D95DADEA2__INCLUDED_)
