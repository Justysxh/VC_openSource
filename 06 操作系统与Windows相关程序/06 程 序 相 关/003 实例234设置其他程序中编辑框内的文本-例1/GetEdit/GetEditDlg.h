// GetEditDlg.h : header file
//

#if !defined(AFX_GETEDITDLG_H__8122B685_0126_436B_85CE_A83C01013CA5__INCLUDED_)
#define AFX_GETEDITDLG_H__8122B685_0126_436B_85CE_A83C01013CA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetEditDlg dialog

class CGetEditDlg : public CDialog
{
// Construction
public:
	CGetEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetEditDlg)
	enum { IDD = IDD_GETEDIT_DIALOG };
	CEdit	m_Content;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetEditDlg)
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

#endif // !defined(AFX_GETEDITDLG_H__8122B685_0126_436B_85CE_A83C01013CA5__INCLUDED_)
