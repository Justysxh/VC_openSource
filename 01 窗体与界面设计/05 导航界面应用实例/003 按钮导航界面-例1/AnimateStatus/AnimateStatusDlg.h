// AnimateStatusDlg.h : header file
//

#if !defined(AFX_ANIMATESTATUSDLG_H__4F494A87_90ED_4F36_9883_3D66967FF74B__INCLUDED_)
#define AFX_ANIMATESTATUSDLG_H__4F494A87_90ED_4F36_9883_3D66967FF74B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnimateStatusDlg dialog

class CAnimateStatusDlg : public CDialog
{
// Construction
public:
	CAnimateStatusDlg(CWnd* pParent = NULL);	// standard constructor
	CStatusBar m_StatusBar;
// Dialog Data
	//{{AFX_DATA(CAnimateStatusDlg)
	enum { IDD = IDD_ANIMATESTATUS_DIALOG };
	CAnimateCtrl	m_Animate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnimateStatusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATESTATUSDLG_H__4F494A87_90ED_4F36_9883_3D66967FF74B__INCLUDED_)
