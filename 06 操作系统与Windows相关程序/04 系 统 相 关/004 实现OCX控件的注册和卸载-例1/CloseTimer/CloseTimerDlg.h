// CloseTimerDlg.h : header file
//

#if !defined(AFX_CLOSETIMERDLG_H__66898F65_E1A5_4F68_8B56_9D3A5E9B2900__INCLUDED_)
#define AFX_CLOSETIMERDLG_H__66898F65_E1A5_4F68_8B56_9D3A5E9B2900__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCloseTimerDlg dialog

class CCloseTimerDlg : public CDialog
{
// Construction
public:
	CCloseTimerDlg(CWnd* pParent = NULL);	// standard constructor
	CString m_Skey;		//×¢²á±í¼üÖµ
	HICON m_Icon;				//ÍÐÅÌÍ¼±ê
// Dialog Data
	//{{AFX_DATA(CCloseTimerDlg)
	enum { IDD = IDD_CLOSETIMER_DIALOG };
	CButton	m_Check;
	COleDateTime	m_Time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseTimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCloseTimerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonset();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTray(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSETIMERDLG_H__66898F65_E1A5_4F68_8B56_9D3A5E9B2900__INCLUDED_)
