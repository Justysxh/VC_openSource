// TopWindowDlg.h : header file
//

#if !defined(AFX_TOPWINDOWDLG_H__E45FABBA_211E_42DC_96BA_F336A9525BA0__INCLUDED_)
#define AFX_TOPWINDOWDLG_H__E45FABBA_211E_42DC_96BA_F336A9525BA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTopWindowDlg dialog

class CTopWindowDlg : public CDialog
{
// Construction
public:
	CTopWindowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTopWindowDlg)
	enum { IDD = IDD_TOPWINDOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopWindowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTopWindowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPWINDOWDLG_H__E45FABBA_211E_42DC_96BA_F336A9525BA0__INCLUDED_)
