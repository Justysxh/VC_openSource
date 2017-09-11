// ScrollStatusDlg.h : header file
//

#if !defined(AFX_SCROLLSTATUSDLG_H__08A31391_1AC9_456F_BFEC_89E851C4C3A9__INCLUDED_)
#define AFX_SCROLLSTATUSDLG_H__08A31391_1AC9_456F_BFEC_89E851C4C3A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScrollStatusDlg dialog

class CScrollStatusDlg : public CDialog
{
// Construction
public:
	CScrollStatusDlg(CWnd* pParent = NULL);	// standard constructor
	CStatusBar m_StatusBar;
	CRect Rect;
	CRect CurRect;
	CRect rect1;
// Dialog Data
	//{{AFX_DATA(CScrollStatusDlg)
	enum { IDD = IDD_SCROLLSTATUS_DIALOG };
	CStatic	m_Parent;
	CStatic	m_Web;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrollStatusDlg)
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

#endif // !defined(AFX_SCROLLSTATUSDLG_H__08A31391_1AC9_456F_BFEC_89E851C4C3A9__INCLUDED_)
