// PrintLeaveDlg.h : header file
//

#if !defined(AFX_PRINTLEAVEDLG_H__47DB6D94_A846_4DB8_9B9E_87BF164946BC__INCLUDED_)
#define AFX_PRINTLEAVEDLG_H__47DB6D94_A846_4DB8_9B9E_87BF164946BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintLeaveDlg dialog

class CPrintLeaveDlg : public CDialog
{
// Construction
public:
	CPrintLeaveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintLeaveDlg)
	enum { IDD = IDD_PRINTLEAVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintLeaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintLeaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTLEAVEDLG_H__47DB6D94_A846_4DB8_9B9E_87BF164946BC__INCLUDED_)
