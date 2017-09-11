// DetachDlg.h : header file
//

#if !defined(AFX_DETACHDLG_H__2207C5CF_A6C5_4143_BF0B_06450ECD9E3F__INCLUDED_)
#define AFX_DETACHDLG_H__2207C5CF_A6C5_4143_BF0B_06450ECD9E3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDetachDlg dialog

class CDetachDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn();
	CDetachDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CDetachDlg)
	enum { IDD = IDD_DETACH_DIALOG };
	CListBox	m_Database;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetachDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDetachDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETACHDLG_H__2207C5CF_A6C5_4143_BF0B_06450ECD9E3F__INCLUDED_)
