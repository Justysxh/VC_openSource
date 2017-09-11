// ShutWindowDlg.h : header file
//

#if !defined(AFX_SHUTWINDOWDLG_H__C4FA08A7_0FDF_4A8C_B4D9_9911B7B68AC7__INCLUDED_)
#define AFX_SHUTWINDOWDLG_H__C4FA08A7_0FDF_4A8C_B4D9_9911B7B68AC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShutWindowDlg dialog

class CShutWindowDlg : public CDialog
{
// Construction
public:
	CShutWindowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShutWindowDlg)
	enum { IDD = IDD_SHUTWINDOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutWindowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShutWindowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnReset();
	afx_msg void OnLogout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTWINDOWDLG_H__C4FA08A7_0FDF_4A8C_B4D9_9911B7B68AC7__INCLUDED_)
