// SolGameDlg.h : header file
//

#if !defined(AFX_SOLGAMEDLG_H__EA342D05_2BFE_40B5_A45F_A1961DE12344__INCLUDED_)
#define AFX_SOLGAMEDLG_H__EA342D05_2BFE_40B5_A45F_A1961DE12344__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSolGameDlg dialog

class CSolGameDlg : public CDialog
{
// Construction
public:
	CSolGameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSolGameDlg)
	enum { IDD = IDD_SOLGAME_DIALOG };
	CButton	m_sound;
	CButton	m_movie;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSolGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnEnter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLGAMEDLG_H__EA342D05_2BFE_40B5_A45F_A1961DE12344__INCLUDED_)
