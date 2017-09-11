// TransStaticDlg.h : header file
//

#if !defined(AFX_TRANSSTATICDLG_H__980080E0_A7AE_4042_8434_7B554B7DEECD__INCLUDED_)
#define AFX_TRANSSTATICDLG_H__980080E0_A7AE_4042_8434_7B554B7DEECD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransStaticDlg dialog

class CTransStaticDlg : public CDialog
{
// Construction
public:
	CTransStaticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransStaticDlg)
	enum { IDD = IDD_TRANSSTATIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransStaticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTransStaticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSSTATICDLG_H__980080E0_A7AE_4042_8434_7B554B7DEECD__INCLUDED_)
