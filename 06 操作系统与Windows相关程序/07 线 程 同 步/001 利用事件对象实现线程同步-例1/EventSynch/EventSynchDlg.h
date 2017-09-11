// EventSynchDlg.h : header file
//

#if !defined(AFX_EVENTSYNCHDLG_H__60C3EB9C_B3C1_44D5_ABAE_976525DB8CE6__INCLUDED_)
#define AFX_EVENTSYNCHDLG_H__60C3EB9C_B3C1_44D5_ABAE_976525DB8CE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEventSynchDlg dialog

class CEventSynchDlg : public CDialog
{
// Construction
public:
	CEventSynchDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CEventSynchDlg)
	enum { IDD = IDD_EVENTSYNCH_DIALOG };
	CEdit	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventSynchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEventSynchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartOne();
	afx_msg void OnStartTwo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EVENTSYNCHDLG_H__60C3EB9C_B3C1_44D5_ABAE_976525DB8CE6__INCLUDED_)
