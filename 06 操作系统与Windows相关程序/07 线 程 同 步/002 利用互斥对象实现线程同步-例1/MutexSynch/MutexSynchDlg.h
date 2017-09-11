// MutexSynchDlg.h : header file
//

#if !defined(AFX_MUTEXSYNCHDLG_H__4F82C0CC_2E15_4B8B_B704_5F2FB1EF49AC__INCLUDED_)
#define AFX_MUTEXSYNCHDLG_H__4F82C0CC_2E15_4B8B_B704_5F2FB1EF49AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMutexSynchDlg dialog

class CMutexSynchDlg : public CDialog
{
// Construction
public:
	CMutexSynchDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL bmutex;
// Dialog Data
	//{{AFX_DATA(CMutexSynchDlg)
	enum { IDD = IDD_MUTEXSYNCH_DIALOG };
	CButton	m_mutex;
	CEdit	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMutexSynchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMutexSynchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartOne();
	afx_msg void OnStartTwo();
	afx_msg void OnMutex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUTEXSYNCHDLG_H__4F82C0CC_2E15_4B8B_B704_5F2FB1EF49AC__INCLUDED_)
