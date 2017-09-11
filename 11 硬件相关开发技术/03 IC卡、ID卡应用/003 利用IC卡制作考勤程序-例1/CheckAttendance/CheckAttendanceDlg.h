// CheckAttendanceDlg.h : header file
//

#if !defined(AFX_CHECKATTENDANCEDLG_H__25662703_984B_408A_99B2_8EFA70B17D88__INCLUDED_)
#define AFX_CHECKATTENDANCEDLG_H__25662703_984B_408A_99B2_8EFA70B17D88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCheckAttendanceDlg dialog
#include "Mwic_32.h"
#pragma comment (lib,"mwic_32.lib")
#include "CardID.h"

class CCheckAttendanceDlg : public CDialog
{
// Construction
public:
	CCheckAttendanceDlg(CWnd* pParent = NULL);	// standard constructor

	HANDLE icdev;
	CToolBar m_wndToolbar;
// Dialog Data
	//{{AFX_DATA(CCheckAttendanceDlg)
	enum { IDD = IDD_CHECKATTENDANCE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckAttendanceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCheckAttendanceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCartset();
	afx_msg void OnMenuadd();
	afx_msg void OnMenucheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKATTENDANCEDLG_H__25662703_984B_408A_99B2_8EFA70B17D88__INCLUDED_)
