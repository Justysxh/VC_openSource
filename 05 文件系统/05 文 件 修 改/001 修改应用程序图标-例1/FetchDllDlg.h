// FetchDllDlg.h : header file
//

#if !defined(AFX_FETCHDLLDLG_H__7F1BEA9A_F94D_4F2C_B6E2_6F45E604339A__INCLUDED_)
#define AFX_FETCHDLLDLG_H__7F1BEA9A_F94D_4F2C_B6E2_6F45E604339A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFetchDllDlg dialog

class CFetchDllDlg : public CDialog
{
// Construction
public:
	CFetchDllDlg(CWnd* pParent = NULL);	// standard constructor

	unsigned  char* pIconRes;

	char*  m_pIconData;
// Dialog Data
	//{{AFX_DATA(CFetchDllDlg)
	enum { IDD = IDD_FETCHDLL_DIALOG };
	CStatic	m_Icon;
	CListBox	m_List;
	CString	m_FileName;
	CString	m_IconFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFetchDllDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrown();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnIconbrown();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHDLLDLG_H__7F1BEA9A_F94D_4F2C_B6E2_6F45E604339A__INCLUDED_)
