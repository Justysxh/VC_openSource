// GetWebSourceDlg.h : header file
//

#if !defined(AFX_GETWEBSOURCEDLG_H__CDA6F86A_0259_4BD7_9708_5650322BC0EF__INCLUDED_)
#define AFX_GETWEBSOURCEDLG_H__CDA6F86A_0259_4BD7_9708_5650322BC0EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetWebSourceDlg dialog

class CGetWebSourceDlg : public CDialog
{
// Construction
public:
	CGetWebSourceDlg(CWnd* pParent = NULL);	// standard constructor
	CString strtime;
// Dialog Data
	//{{AFX_DATA(CGetWebSourceDlg)
	enum { IDD = IDD_GETWEBSOURCE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWebSourceDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetWebSourceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEBSOURCEDLG_H__CDA6F86A_0259_4BD7_9708_5650322BC0EF__INCLUDED_)
