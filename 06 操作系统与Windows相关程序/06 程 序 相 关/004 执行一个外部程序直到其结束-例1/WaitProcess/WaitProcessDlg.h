// WaitProcessDlg.h : header file
//

#if !defined(AFX_WAITPROCESSDLG_H__3FB00019_D890_4734_B418_81E7575987A4__INCLUDED_)
#define AFX_WAITPROCESSDLG_H__3FB00019_D890_4734_B418_81E7575987A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWaitProcessDlg dialog

class CWaitProcessDlg : public CDialog
{
// Construction
public:
	CWaitProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWaitProcessDlg)
	enum { IDD = IDD_WAITPROCESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaitProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWaitProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnExecute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAITPROCESSDLG_H__3FB00019_D890_4734_B418_81E7575987A4__INCLUDED_)
