// ThreadSynchDlg.h : header file
//

#if !defined(AFX_THREADSYNCHDLG_H__DF66B5D6_AEC8_4F47_8FFF_F7B4D855906F__INCLUDED_)
#define AFX_THREADSYNCHDLG_H__DF66B5D6_AEC8_4F47_8FFF_F7B4D855906F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadSynchDlg dialog

class CThreadSynchDlg : public CDialog
{
// Construction
public:
	CThreadSynchDlg(CWnd* pParent = NULL);	// standard constructor
	CString path;
	CString str;
// Dialog Data
	//{{AFX_DATA(CThreadSynchDlg)
	enum { IDD = IDD_THREADSYNCH_DIALOG };
	CProgressCtrl	m_posg;
	CProgressCtrl	m_posf;
	CProgressCtrl	m_pose;
	CProgressCtrl	m_posd;
	CProgressCtrl	m_posc;
	CProgressCtrl	m_posb;
	CProgressCtrl	m_posa;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadSynchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWriteA();
	afx_msg void OnWriteB();
	afx_msg void OnWriteC();
	afx_msg void OnWriteD();
	afx_msg void OnWriteE();
	afx_msg void OnWriteF();
	afx_msg void OnWriteG();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNCHDLG_H__DF66B5D6_AEC8_4F47_8FFF_F7B4D855906F__INCLUDED_)
