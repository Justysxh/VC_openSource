// CriticalSectionSynchDlg.h : header file
//

#if !defined(AFX_CRITICALSECTIONSYNCHDLG_H__7BC854AC_F3D7_499E_99DB_02767E83F53C__INCLUDED_)
#define AFX_CRITICALSECTIONSYNCHDLG_H__7BC854AC_F3D7_499E_99DB_02767E83F53C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionSynchDlg dialog

class CCriticalSectionSynchDlg : public CDialog
{
// Construction
public:
	CCriticalSectionSynchDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL bcritical;
// Dialog Data
	//{{AFX_DATA(CCriticalSectionSynchDlg)
	enum { IDD = IDD_CRITICALSECTIONSYNCH_DIALOG };
	CButton	m_criticl;
	CEdit	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionSynchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCriticalSectionSynchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartOne();
	afx_msg void OnStartTwo();
	afx_msg void OnCriticl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTIONSYNCHDLG_H__7BC854AC_F3D7_499E_99DB_02767E83F53C__INCLUDED_)
