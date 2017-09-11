// ScreenProtectDlg.h : header file
//

#if !defined(AFX_SCREENPROTECTDLG_H__B270C815_4D5A_4AEF_B0E7_7AEE4AC35AAD__INCLUDED_)
#define AFX_SCREENPROTECTDLG_H__B270C815_4D5A_4AEF_B0E7_7AEE4AC35AAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScreenProtectDlg dialog

class CScreenProtectDlg : public CDialog
{
// Construction
public:
	CScreenProtectDlg(CWnd* pParent = NULL);	// standard constructor
	CPoint pOint;
	int i,j;
// Dialog Data
	//{{AFX_DATA(CScreenProtectDlg)
	enum { IDD = IDD_SCREENPROTECT_DIALOG };
	CStatic	m_picture;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenProtectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScreenProtectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENPROTECTDLG_H__B270C815_4D5A_4AEF_B0E7_7AEE4AC35AAD__INCLUDED_)
