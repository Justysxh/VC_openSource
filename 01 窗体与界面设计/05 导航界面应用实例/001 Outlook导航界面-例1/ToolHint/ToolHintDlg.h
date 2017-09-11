// ToolHintDlg.h : header file
//

#if !defined(AFX_TOOLHINTDLG_H__80E156D8_A024_4414_9072_89628132F86D__INCLUDED_)
#define AFX_TOOLHINTDLG_H__80E156D8_A024_4414_9072_89628132F86D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CToolHintDlg dialog

class CToolHintDlg : public CDialog
{
// Construction
public:
	CToolHintDlg(CWnd* pParent = NULL);	// standard constructor

	CToolBar m_wndToolBar;
	CString m_ToolText;

// Dialog Data
	//{{AFX_DATA(CToolHintDlg)
	enum { IDD = IDD_TOOLHINT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolHintDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToolHintDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnToolTipNotify( UINT id, NMHDR * pNMHDR, LRESULT * pResult );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLHINTDLG_H__80E156D8_A024_4414_9072_89628132F86D__INCLUDED_)
