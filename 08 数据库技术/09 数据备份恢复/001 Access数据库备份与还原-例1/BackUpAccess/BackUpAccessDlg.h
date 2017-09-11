// BackUpAccessDlg.h : header file
//

#if !defined(AFX_BACKUPACCESSDLG_H__A2ADCD5B_3B60_4BC1_8D14_47CCABBD3D5C__INCLUDED_)
#define AFX_BACKUPACCESSDLG_H__A2ADCD5B_3B60_4BC1_8D14_47CCABBD3D5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBackUpAccessDlg dialog

class CBackUpAccessDlg : public CDialog
{
// Construction
public:
	CBackUpAccessDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL radio;
	CString StrPath;
// Dialog Data
	//{{AFX_DATA(CBackUpAccessDlg)
	enum { IDD = IDD_BACKUPACCESS_DIALOG };
	CButton	m_But2;
	CButton	m_But1;
	CString	m_Edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackUpAccessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBackUpAccessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKUPACCESSDLG_H__A2ADCD5B_3B60_4BC1_8D14_47CCABBD3D5C__INCLUDED_)
