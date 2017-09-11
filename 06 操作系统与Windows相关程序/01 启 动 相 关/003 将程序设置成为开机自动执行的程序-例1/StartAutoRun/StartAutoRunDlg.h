// StartAutoRunDlg.h : header file
//

#if !defined(AFX_STARTAUTORUNDLG_H__56A79CC0_80AD_46D8_B671_F8611883F8A0__INCLUDED_)
#define AFX_STARTAUTORUNDLG_H__56A79CC0_80AD_46D8_B671_F8611883F8A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStartAutoRunDlg dialog

class CStartAutoRunDlg : public CDialog
{
// Construction
public:
	CStartAutoRunDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStartAutoRunDlg)
	enum { IDD = IDD_STARTAUTORUN_DIALOG };
	CButton	m_chset;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartAutoRunDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStartAutoRunDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTAUTORUNDLG_H__56A79CC0_80AD_46D8_B671_F8611883F8A0__INCLUDED_)
