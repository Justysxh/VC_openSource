// StartIEDlg.h : header file
//

#if !defined(AFX_STARTIEDLG_H__9CDEDB8C_4953_44DA_ADFB_B4085FD2D5A3__INCLUDED_)
#define AFX_STARTIEDLG_H__9CDEDB8C_4953_44DA_ADFB_B4085FD2D5A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStartIEDlg dialog

class CStartIEDlg : public CDialog
{
// Construction
public:
	CStartIEDlg(CWnd* pParent = NULL);	// standard constructor
	CString strcomd;
// Dialog Data
	//{{AFX_DATA(CStartIEDlg)
	enum { IDD = IDD_STARTIE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartIEDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStartIEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTray(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTIEDLG_H__9CDEDB8C_4953_44DA_ADFB_B4085FD2D5A3__INCLUDED_)
