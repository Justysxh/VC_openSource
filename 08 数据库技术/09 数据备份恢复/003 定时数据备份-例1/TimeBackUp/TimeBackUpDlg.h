// TimeBackUpDlg.h : header file
//

#if !defined(AFX_TIMEBACKUPDLG_H__30C9977D_0C42_451C_A461_6BDE7D123080__INCLUDED_)
#define AFX_TIMEBACKUPDLG_H__30C9977D_0C42_451C_A461_6BDE7D123080__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimeBackUpDlg dialog

class CTimeBackUpDlg : public CDialog
{
// Construction
public:
	CTimeBackUpDlg(CWnd* pParent = NULL);	// standard constructor
	CString strName;
	int hour,min;

// Dialog Data
	//{{AFX_DATA(CTimeBackUpDlg)
	enum { IDD = IDD_TIMEBACKUP_DIALOG };
	CEdit	m_min;
	CEdit	m_hour;
	CString	m_edit1;
	CString	m_edit2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeBackUpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimeBackUpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButliulan();
	afx_msg void OnButsave();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEBACKUPDLG_H__30C9977D_0C42_451C_A461_6BDE7D123080__INCLUDED_)
