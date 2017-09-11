// DijoyDlg.h : header file
//

#if !defined(AFX_DIJOYDLG_H__8F2FD32F_DCBA_47EE_ADE5_E1BE742C6D3E__INCLUDED_)
#define AFX_DIJOYDLG_H__8F2FD32F_DCBA_47EE_ADE5_E1BE742C6D3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDijoyDlg dialog

class CDijoyDlg : public CDialog
{
// Construction
public:
	int nX,nY;
	int bButton;
	CDijoyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDijoyDlg)
	enum { IDD = IDD_DIJOY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDijoyDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDijoyDlg)
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

#endif // !defined(AFX_DIJOYDLG_H__8F2FD32F_DCBA_47EE_ADE5_E1BE742C6D3E__INCLUDED_)
