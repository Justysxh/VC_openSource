// TrayPopMenuDlg.h : header file
//

#if !defined(AFX_TRAYPOPMENUDLG_H__93ECBEF0_6C45_48DA_AD14_EC6929F35F90__INCLUDED_)
#define AFX_TRAYPOPMENUDLG_H__93ECBEF0_6C45_48DA_AD14_EC6929F35F90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrayPopMenuDlg dialog
#include "IconMenu1.h"
class CTrayPopMenuDlg : public CDialog
{
// Construction
public:
	CTrayPopMenuDlg(CWnd* pParent = NULL);	// standard constructor
	NOTIFYICONDATA m_traydata;
// Dialog Data
	//{{AFX_DATA(CTrayPopMenuDlg)
	enum { IDD = IDD_TRAYPOPMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayPopMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CIconMenu m_menu;
	// Generated message map functions
	//{{AFX_MSG(CTrayPopMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTrayMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnMenuitemexit();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYPOPMENUDLG_H__93ECBEF0_6C45_48DA_AD14_EC6929F35F90__INCLUDED_)
