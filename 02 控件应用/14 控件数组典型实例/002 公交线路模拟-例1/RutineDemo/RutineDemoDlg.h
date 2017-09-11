// RutineDemoDlg.h : header file
//

#if !defined(AFX_RUTINEDEMODLG_H__7801839B_41EF_47B7_BCC4_ED110AD00429__INCLUDED_)
#define AFX_RUTINEDEMODLG_H__7801839B_41EF_47B7_BCC4_ED110AD00429__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRutineDemoDlg dialog
#include "MyStatic.h"
class CRutineDemoDlg : public CDialog
{
// Construction
public:
	void DemoCircuitry();
	CRutineDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CStatic m_buses [5];
	BOOL iscreated;
// Dialog Data
	//{{AFX_DATA(CRutineDemoDlg)
	enum { IDD = IDD_RUTINEDEMO_DIALOG };
	CMyStatic	m_title;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRutineDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRutineDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUTINEDEMODLG_H__7801839B_41EF_47B7_BCC4_ED110AD00429__INCLUDED_)
