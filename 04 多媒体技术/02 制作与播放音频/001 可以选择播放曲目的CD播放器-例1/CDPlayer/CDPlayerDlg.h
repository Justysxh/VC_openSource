// CDPlayerDlg.h : header file
//

#if !defined(AFX_CDPLAYERDLG_H__BD15284B_7922_4EB2_A9C9_B907F9C40139__INCLUDED_)
#define AFX_CDPLAYERDLG_H__BD15284B_7922_4EB2_A9C9_B907F9C40139__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCDPlayerDlg dialog

class CCDPlayerDlg : public CDialog
{
// Construction
public:
	CCDPlayerDlg(CWnd* pParent = NULL);	// standard constructor
	UINT m_wDeviceID;
// Dialog Data
	//{{AFX_DATA(CCDPlayerDlg)
	enum { IDD = IDD_CDPLAYER_DIALOG };
	CListCtrl	m_cdcata;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDPlayerDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCDPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTray(WPARAM wParam,LPARAM lParam);
	afx_msg void OnPlay();
	afx_msg void OnStop();
	afx_msg void OnExit();
	afx_msg void OnDblclkCdcata(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDPLAYERDLG_H__BD15284B_7922_4EB2_A9C9_B907F9C40139__INCLUDED_)
