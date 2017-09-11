// SQLstockupDlg.h : header file
//

#if !defined(AFX_SQLSTOCKUPDLG_H__8097E83D_1515_4EBF_A99C_1CB421E4635B__INCLUDED_)
#define AFX_SQLSTOCKUPDLG_H__8097E83D_1515_4EBF_A99C_1CB421E4635B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSQLstockupDlg dialog

class CSQLstockupDlg : public CDialog
{
// Construction
public:
	CString strText;
	CSQLstockupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSQLstockupDlg)
	enum { IDD = IDD_SQLSTOCKUP_DIALOG };
	CEdit	m_edit;
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQLstockupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSQLstockupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButlujing();
	virtual void OnOK();
	afx_msg void OnButhf();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLSTOCKUPDLG_H__8097E83D_1515_4EBF_A99C_1CB421E4635B__INCLUDED_)
