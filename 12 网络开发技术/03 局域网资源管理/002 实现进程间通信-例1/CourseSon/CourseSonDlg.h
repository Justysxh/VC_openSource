// CourseSonDlg.h : header file
//

#if !defined(AFX_COURSESONDLG_H__F989085B_394B_44C0_89E1_B4C527253D94__INCLUDED_)
#define AFX_COURSESONDLG_H__F989085B_394B_44C0_89E1_B4C527253D94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCourseSonDlg dialog

class CCourseSonDlg : public CDialog
{
// Construction
public:
	CCourseSonDlg(CWnd* pParent = NULL);	// standard constructor
	UINT minMsg,maxMsg,revMsg,closeMsg;
// Dialog Data
	//{{AFX_DATA(CCourseSonDlg)
	enum { IDD = IDD_COURSESON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSonDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCourseSonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESONDLG_H__F989085B_394B_44C0_89E1_B4C527253D94__INCLUDED_)
