// PeripheryCommandDlg.h : header file
//

#if !defined(AFX_PERIPHERYCOMMANDDLG_H__900B60A4_4C9A_44B9_BF8A_3AA0C584C407__INCLUDED_)
#define AFX_PERIPHERYCOMMANDDLG_H__900B60A4_4C9A_44B9_BF8A_3AA0C584C407__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPeripheryCommandDlg dialog

class CPeripheryCommandDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn();
	CPeripheryCommandDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CString strName;
// Dialog Data
	//{{AFX_DATA(CPeripheryCommandDlg)
	enum { IDD = IDD_PERIPHERYCOMMAND_DIALOG };
	CString	m_Edit1;
	CString	m_Edit2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeripheryCommandDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPeripheryCommandDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButcopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERIPHERYCOMMANDDLG_H__900B60A4_4C9A_44B9_BF8A_3AA0C584C407__INCLUDED_)
