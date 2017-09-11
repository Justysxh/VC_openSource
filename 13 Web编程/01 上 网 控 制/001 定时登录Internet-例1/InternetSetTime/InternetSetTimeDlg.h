// InternetSetTimeDlg.h : header file
//

#if !defined(AFX_INTERNETSETTIMEDLG_H__38953729_2B90_4E00_8BEC_E4366B2462AC__INCLUDED_)
#define AFX_INTERNETSETTIMEDLG_H__38953729_2B90_4E00_8BEC_E4366B2462AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInternetSetTimeDlg dialog

class CInternetSetTimeDlg : public CDialog
{
// Construction
public:
	CInternetSetTimeDlg(CWnd* pParent = NULL);	// standard constructor
	CString straddress,strtime;
// Dialog Data
	//{{AFX_DATA(CInternetSetTimeDlg)
	enum { IDD = IDD_INTERNETSETTIME_DIALOG };
	CComboBox	m_minu;
	CComboBox	m_hour;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetSetTimeDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CInternetSetTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnter();
	afx_msg void OnClose();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTray(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETSETTIMEDLG_H__38953729_2B90_4E00_8BEC_E4366B2462AC__INCLUDED_)
