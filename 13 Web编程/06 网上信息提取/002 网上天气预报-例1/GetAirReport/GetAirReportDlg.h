// GetAirReportDlg.h : header file
//

#if !defined(AFX_GETAIRREPORTDLG_H__5236F521_34E2_45C8_9281_4CAF3618BD71__INCLUDED_)
#define AFX_GETAIRREPORTDLG_H__5236F521_34E2_45C8_9281_4CAF3618BD71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetAirReportDlg dialog

class CGetAirReportDlg : public CDialog
{
// Construction
public:
	CGetAirReportDlg(CWnd* pParent = NULL);	// standard constructor
	CString address; //ÍøÒ³µÄµØÖ·
	CString addressfront;
	CString strweather,strtemperature,strwind;
	CString strtmp1,strtmp2,strtmp3;
// Dialog Data
	//{{AFX_DATA(CGetAirReportDlg)
	enum { IDD = IDD_GETAIRREPORT_DIALOG };
	CListCtrl	m_reportlist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetAirReportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetAirReportDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETAIRREPORTDLG_H__5236F521_34E2_45C8_9281_4CAF3618BD71__INCLUDED_)
