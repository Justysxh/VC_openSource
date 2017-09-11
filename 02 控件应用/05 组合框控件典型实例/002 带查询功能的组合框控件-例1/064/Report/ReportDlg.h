// ReportDlg.h : header file
//

#if !defined(AFX_REPORTDLG_H__D2A6E5A3_DFAF_45B5_A946_6519A6F8BD9A__INCLUDED_)
#define AFX_REPORTDLG_H__D2A6E5A3_DFAF_45B5_A946_6519A6F8BD9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog

class CReportDlg : public CDialog
{
// Construction
public:
	CReportDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReportDlg)
	enum { IDD = IDD_REPORT_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReportDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORTDLG_H__D2A6E5A3_DFAF_45B5_A946_6519A6F8BD9A__INCLUDED_)
