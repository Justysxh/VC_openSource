// ToolTipControlDlg.h : header file
//

#if !defined(AFX_TOOLTIPCONTROLDLG_H__D6441D32_7045_42D2_8729_68E7363462F8__INCLUDED_)
#define AFX_TOOLTIPCONTROLDLG_H__D6441D32_7045_42D2_8729_68E7363462F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CToolTipControlDlg dialog

class CToolTipControlDlg : public CDialog
{
// Construction
public:
	CToolTipControlDlg(CWnd* pParent = NULL);	// standard constructor
	CToolTipCtrl m_ToolTip;
// Dialog Data
	//{{AFX_DATA(CToolTipControlDlg)
	enum { IDD = IDD_TOOLTIPCONTROL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolTipControlDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToolTipControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLTIPCONTROLDLG_H__D6441D32_7045_42D2_8729_68E7363462F8__INCLUDED_)
