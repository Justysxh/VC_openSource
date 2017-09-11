// WriteLockDlg.h : header file
//

#if !defined(AFX_WRITELOCKDLG_H__8808CE1F_B867_4650_A7FA_4AFD97140168__INCLUDED_)
#define AFX_WRITELOCKDLG_H__8808CE1F_B867_4650_A7FA_4AFD97140168__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWriteLockDlg dialog

class CWriteLockDlg : public CDialog
{
// Construction
public:
	CWriteLockDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWriteLockDlg)
	enum { IDD = IDD_WRITELOCK_DIALOG };
	CString	m_Data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWriteLockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWriteLockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButwrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRITELOCKDLG_H__8808CE1F_B867_4650_A7FA_4AFD97140168__INCLUDED_)
