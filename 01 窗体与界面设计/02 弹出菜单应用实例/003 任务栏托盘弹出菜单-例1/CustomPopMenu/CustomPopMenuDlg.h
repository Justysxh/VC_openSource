// CustomPopMenuDlg.h : header file
//

#if !defined(AFX_CUSTOMPOPMENUDLG_H__EF2DBB0B_6294_47DA_A1C7_2C35FBC7E7A8__INCLUDED_)
#define AFX_CUSTOMPOPMENUDLG_H__EF2DBB0B_6294_47DA_A1C7_2C35FBC7E7A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IconMenu1.h"
/////////////////////////////////////////////////////////////////////////////
// CCustomPopMenuDlg dialog

class CCustomPopMenuDlg : public CDialog
{
// Construction
public:
	CCustomPopMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomPopMenuDlg)
	enum { IDD = IDD_CUSTOMPOPMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomPopMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CIconMenu* m_submenu;
	CIconMenu m_menu;
	// Generated message map functions
	//{{AFX_MSG(CCustomPopMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnMenuitem32771();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMPOPMENUDLG_H__EF2DBB0B_6294_47DA_A1C7_2C35FBC7E7A8__INCLUDED_)
