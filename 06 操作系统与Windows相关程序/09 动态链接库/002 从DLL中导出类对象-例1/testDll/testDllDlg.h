// testDllDlg.h : header file
//

#if !defined(AFX_TESTDLLDLG_H__5F294F58_1DD1_4146_8122_329813C300B7__INCLUDED_)
#define AFX_TESTDLLDLG_H__5F294F58_1DD1_4146_8122_329813C300B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDllDlg dialog

class CTestDllDlg : public CDialog
{
// Construction
public:
	CMath m_math;
	CTestDllDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDllDlg)
	enum { IDD = IDD_TESTDLL_DIALOG };
	CEdit	m_value2;
	CEdit	m_value1;
	CEdit	m_d;
	CEdit	m_c;
	CEdit	m_b;
	CEdit	m_a;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDllDlg)
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

#endif // !defined(AFX_TESTDLLDLG_H__5F294F58_1DD1_4146_8122_329813C300B7__INCLUDED_)
