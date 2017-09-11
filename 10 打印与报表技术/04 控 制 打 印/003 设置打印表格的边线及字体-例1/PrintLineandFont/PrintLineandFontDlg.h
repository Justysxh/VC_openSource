// PrintLineandFontDlg.h : header file
//

#if !defined(AFX_PRINTLINEANDFONTDLG_H__CEC7BBCB_7771_46D5_AF68_EEFA4FA08A53__INCLUDED_)
#define AFX_PRINTLINEANDFONTDLG_H__CEC7BBCB_7771_46D5_AF68_EEFA4FA08A53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintLineandFontDlg dialog
#include "Preview.h"
class CPrintLineandFontDlg : public CDialog
{
// Construction
public:
	CPreview dlg;
	CPrintLineandFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintLineandFontDlg)
	enum { IDD = IDD_PRINTLINEANDFONT_DIALOG };
	CListCtrl	m_Grid;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintLineandFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintLineandFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPreview();
	afx_msg void OnSelectFont();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTLINEANDFONTDLG_H__CEC7BBCB_7771_46D5_AF68_EEFA4FA08A53__INCLUDED_)
