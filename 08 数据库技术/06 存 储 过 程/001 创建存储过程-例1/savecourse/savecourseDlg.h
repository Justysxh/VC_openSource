// savecourseDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_SAVECOURSEDLG_H__F3172DCF_DF57_477F_B81D_31973BB88FB6__INCLUDED_)
#define AFX_SAVECOURSEDLG_H__F3172DCF_DF57_477F_B81D_31973BB88FB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSavecourseDlg dialog

class CSavecourseDlg : public CDialog
{
// Construction
public:
	CSavecourseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSavecourseDlg)
	enum { IDD = IDD_SAVECOURSE_DIALOG };
	CAdodc	m_adodc;
	CString	m_edit1;
	CString	m_edit2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSavecourseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSavecourseDlg)
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

#endif // !defined(AFX_SAVECOURSEDLG_H__F3172DCF_DF57_477F_B81D_31973BB88FB6__INCLUDED_)
