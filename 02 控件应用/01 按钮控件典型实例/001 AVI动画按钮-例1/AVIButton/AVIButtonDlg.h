// AVIButtonDlg.h : header file
//

#if !defined(AFX_AVIBUTTONDLG_H__D5E83654_89DA_4381_83F7_576E0F3991AB__INCLUDED_)
#define AFX_AVIBUTTONDLG_H__D5E83654_89DA_4381_83F7_576E0F3991AB__INCLUDED_
#include "ButtonAvi.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAVIButtonDlg dialog

class CAVIButtonDlg : public CDialog
{
// Construction
public:
	CAVIButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAVIButtonDlg)
	enum { IDD = IDD_AVIBUTTON_DIALOG };
	CButtonAvi	m_avib;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVIButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAVIButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIBUTTONDLG_H__D5E83654_89DA_4381_83F7_576E0F3991AB__INCLUDED_)
