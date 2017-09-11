// ReceiveMailDlg.h : header file
//

#if !defined(AFX_RECEIVEMAILDLG_H__CD9E96FC_56D3_4948_A440_FE97CDEDE4BC__INCLUDED_)
#define AFX_RECEIVEMAILDLG_H__CD9E96FC_56D3_4948_A440_FE97CDEDE4BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReceiveMailDlg dialog

class CReceiveMailDlg : public CDialog
{
// Construction
public:
	CReceiveMailDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReceiveMailDlg)
	enum { IDD = IDD_RECEIVEMAIL_DIALOG };
	CListCtrl	m_recelst;
	CListBox	m_maillst;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveMailDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReceiveMailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRece();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEMAILDLG_H__CD9E96FC_56D3_4948_A440_FE97CDEDE4BC__INCLUDED_)
