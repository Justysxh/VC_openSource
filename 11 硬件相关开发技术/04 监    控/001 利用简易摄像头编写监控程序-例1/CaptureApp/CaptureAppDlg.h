// CaptureAppDlg.h : header file
//

#if !defined(AFX_CAPTUREAPPDLG_H__4B8F77FE_1814_4725_B502_A09DEA345C47__INCLUDED_)
#define AFX_CAPTUREAPPDLG_H__4B8F77FE_1814_4725_B502_A09DEA345C47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCaptureAppDlg dialog
#include "vfw.h"
#pragma comment(lib,"vfw32.lib")
#include <afxmt.h>

class CCaptureAppDlg : public CDialog
{
// Construction
public:
	CCaptureAppDlg(CWnd* pParent = NULL);	// standard constructor
	HWND m_hVideoWnd;

	CEvent m_Event;	
	static UINT ThreadFun( LPVOID lpParam );


// Dialog Data
	//{{AFX_DATA(CCaptureAppDlg)
	enum { IDD = IDD_CAPTUREAPP_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCaptureAppDlg)
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

#endif // !defined(AFX_CAPTUREAPPDLG_H__4B8F77FE_1814_4725_B502_A09DEA345C47__INCLUDED_)
