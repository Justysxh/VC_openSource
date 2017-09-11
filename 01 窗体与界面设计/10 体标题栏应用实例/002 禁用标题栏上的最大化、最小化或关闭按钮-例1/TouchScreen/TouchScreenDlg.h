// TouchScreenDlg.h : header file
//
//{{AFX_INCLUDES()
#include "shockwaveflash.h"
//}}AFX_INCLUDES

#if !defined(AFX_TOUCHSCREENDLG_H__03DCE329_AC4F_45F6_BACD_686EE68D2F50__INCLUDED_)
#define AFX_TOUCHSCREENDLG_H__03DCE329_AC4F_45F6_BACD_686EE68D2F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTouchScreenDlg dialog

class CTouchScreenDlg : public CDialog
{
// Construction
public:
	CTouchScreenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTouchScreenDlg)
	enum { IDD = IDD_TOUCHSCREEN_DIALOG };
	CAnimateCtrl	m_Center;
	CAnimateCtrl	m_Navigation;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTouchScreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTouchScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnButton1();
	afx_msg void OnStaticcenter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOUCHSCREENDLG_H__03DCE329_AC4F_45F6_BACD_686EE68D2F50__INCLUDED_)
