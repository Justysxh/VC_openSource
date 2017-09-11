// ElectronClockDlg.h : header file
//

#if !defined(AFX_ELECTRONCLOCKDLG_H__C8A175BD_A7F6_4C1F_83A1_A52A7E1E9C4E__INCLUDED_)
#define AFX_ELECTRONCLOCKDLG_H__C8A175BD_A7F6_4C1F_83A1_A52A7E1E9C4E__INCLUDED_
#include "NumberCtrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CElectronClockDlg dialog

class CElectronClockDlg : public CDialog
{
// Construction
public:
	CElectronClockDlg(CWnd* pParent = NULL);	// standard constructor
	CNumberCtrl m_Clock;
// Dialog Data
	//{{AFX_DATA(CElectronClockDlg)
	enum { IDD = IDD_ELECTRONCLOCK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElectronClockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CElectronClockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELECTRONCLOCKDLG_H__C8A175BD_A7F6_4C1F_83A1_A52A7E1E9C4E__INCLUDED_)
