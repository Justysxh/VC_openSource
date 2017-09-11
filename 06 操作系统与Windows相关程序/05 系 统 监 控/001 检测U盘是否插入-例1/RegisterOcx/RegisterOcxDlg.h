// RegisterOcxDlg.h : header file
//

#if !defined(AFX_REGISTEROCXDLG_H__925CCAF7_1032_4833_9954_79EBFA7A1873__INCLUDED_)
#define AFX_REGISTEROCXDLG_H__925CCAF7_1032_4833_9954_79EBFA7A1873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegisterOcxDlg dialog

class CRegisterOcxDlg : public CDialog
{
// Construction
public:
	CRegisterOcxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterOcxDlg)
	enum { IDD = IDD_REGISTEROCX_DIALOG };
	CEdit	m_Path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterOcxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegisterOcxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButpath();
	afx_msg void OnButregocx();
	afx_msg void OnButunregocx();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTEROCXDLG_H__925CCAF7_1032_4833_9954_79EBFA7A1873__INCLUDED_)
