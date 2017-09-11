// SkinDlg.h : header file
//

#if !defined(AFX_SKINDLG_H__F7514465_C819_4C95_A09C_5797E7EA7557__INCLUDED_)
#define AFX_SKINDLG_H__F7514465_C819_4C95_A09C_5797E7EA7557__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSkinDlg dialog
#include "CustomScroll.h"


class CSkinDlg : public CDialog
{
// Construction
public:
	void DrawColor();
	
	CSkinDlg(CWnd* pParent = NULL);	// standard constructor

	CScrollBar* m_pScroll;

	CCustomScroll m_Red;
	CCustomScroll m_Green;
	CCustomScroll m_Blue;

	BYTE m_Rvalue;
	BYTE m_Gvalue;
	BYTE m_Bvalue;

// Dialog Data
	//{{AFX_DATA(CSkinDlg)
	enum { IDD = IDD_SKIN_DIALOG };
	CStatic	m_Color;
	CString	m_Rtext;
	CString	m_Gtext;
	CString	m_Btext;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSkinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINDLG_H__F7514465_C819_4C95_A09C_5797E7EA7557__INCLUDED_)
