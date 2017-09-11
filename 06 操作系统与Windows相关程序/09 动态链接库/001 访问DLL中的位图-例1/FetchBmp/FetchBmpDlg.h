// FetchBmpDlg.h : header file
//

#if !defined(AFX_FETCHBMPDLG_H__034AEF68_D21E_4856_B1F1_582F0BD95017__INCLUDED_)
#define AFX_FETCHBMPDLG_H__034AEF68_D21E_4856_B1F1_582F0BD95017__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchBmpDlg dialog

class CFetchBmpDlg : public CDialog
{
// Construction
public:
	CFetchBmpDlg(CWnd* pParent = NULL);	// standard constructor

	HBITMAP m_hBitmap;
// Dialog Data
	//{{AFX_DATA(CFetchBmpDlg)
	enum { IDD = IDD_FETCHBMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchBmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchBmpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHBMPDLG_H__034AEF68_D21E_4856_B1F1_582F0BD95017__INCLUDED_)
