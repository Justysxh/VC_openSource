// dtcjviewDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_DTCJVIEWDLG_H__4A7AC173_3ECD_42D0_81C3_2482C6FB6CD4__INCLUDED_)
#define AFX_DTCJVIEWDLG_H__4A7AC173_3ECD_42D0_81C3_2482C6FB6CD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDtcjviewDlg dialog

class CDtcjviewDlg : public CDialog
{
// Construction
public:
	CDtcjviewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDtcjviewDlg)
	enum { IDD = IDD_DTCJVIEW_DIALOG };
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDtcjviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDtcjviewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DTCJVIEWDLG_H__4A7AC173_3ECD_42D0_81C3_2482C6FB6CD4__INCLUDED_)
