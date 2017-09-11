// LogFileDlg.h : header file
//

#if !defined(AFX_LOGFILEDLG_H__0D4D2E0A_970E_4D51_A715_CBBD84FDD378__INCLUDED_)
#define AFX_LOGFILEDLG_H__0D4D2E0A_970E_4D51_A715_CBBD84FDD378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLogFileDlg dialog

class CLogFileDlg : public CDialog
{
// Construction
public:
	CLogFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLogFileDlg)
	enum { IDD = IDD_LOGFILE_DIALOG };
	CEdit	m_edlog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLogFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWrite();
	afx_msg void OnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGFILEDLG_H__0D4D2E0A_970E_4D51_A715_CBBD84FDD378__INCLUDED_)
