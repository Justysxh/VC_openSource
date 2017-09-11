// SSdbtlDlg.h : header file
//

#if !defined(AFX_SSDBTLDLG_H__43CF3B7A_5B90_433F_A921_604098EB9184__INCLUDED_)
#define AFX_SSDBTLDLG_H__43CF3B7A_5B90_433F_A921_604098EB9184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSSdbtlDlg dialog

class CSSdbtlDlg : public CDialog
{
// Construction
public:
	CSSdbtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSSdbtlDlg)
	enum { IDD = IDD_SSDBTL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSSdbtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSSdbtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSDBTLDLG_H__43CF3B7A_5B90_433F_A921_604098EB9184__INCLUDED_)
