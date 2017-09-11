// WordPathDlg.h : header file
//

#if !defined(AFX_WORDPATHDLG_H__57264AC7_A613_443F_B0D1_F075F3700B06__INCLUDED_)
#define AFX_WORDPATHDLG_H__57264AC7_A613_443F_B0D1_F075F3700B06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWordPathDlg dialog

class CWordPathDlg : public CDialog
{
// Construction
public:
	CWordPathDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWordPathDlg)
	enum { IDD = IDD_WORDPATH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordPathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWordPathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtpath();
	afx_msg void OnBtset();
	afx_msg void OnAddPicPath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDPATHDLG_H__57264AC7_A613_443F_B0D1_F075F3700B06__INCLUDED_)
