// CDAutoRunDlg.h : header file
//

#if !defined(AFX_CDAUTORUNDLG_H__947BA820_E855_4980_9AD3_A13AD9CCD2D0__INCLUDED_)
#define AFX_CDAUTORUNDLG_H__947BA820_E855_4980_9AD3_A13AD9CCD2D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCDAutoRunDlg dialog

class CCDAutoRunDlg : public CDialog
{
// Construction
public:
	CCDAutoRunDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCDAutoRunDlg)
	enum { IDD = IDD_CDAUTORUN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDAutoRunDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCDAutoRunDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnForbid();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDAUTORUNDLG_H__947BA820_E855_4980_9AD3_A13AD9CCD2D0__INCLUDED_)
