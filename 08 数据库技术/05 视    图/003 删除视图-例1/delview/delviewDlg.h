// delviewDlg.h : header file
//

#if !defined(AFX_DELVIEWDLG_H__FC7910D9_DB6A_4EAA_90EE_46C8123B705E__INCLUDED_)
#define AFX_DELVIEWDLG_H__FC7910D9_DB6A_4EAA_90EE_46C8123B705E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDelviewDlg dialog

class CDelviewDlg : public CDialog
{
// Construction
public:
	CDelviewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDelviewDlg)
	enum { IDD = IDD_DELVIEW_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDelviewDlg)
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

#endif // !defined(AFX_DELVIEWDLG_H__FC7910D9_DB6A_4EAA_90EE_46C8123B705E__INCLUDED_)
