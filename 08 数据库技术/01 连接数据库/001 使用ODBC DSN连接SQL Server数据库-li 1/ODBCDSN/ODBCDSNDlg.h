// ODBCDSNDlg.h : header file
//

#if !defined(AFX_ODBCDSNDLG_H__A844AB3C_5426_4126_859B_A732C327359B__INCLUDED_)
#define AFX_ODBCDSNDLG_H__A844AB3C_5426_4126_859B_A732C327359B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CODBCDSNDlg dialog

class CODBCDSNDlg : public CDialog
{
// Construction
public:
	CODBCDSNDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CODBCDSNDlg)
	enum { IDD = IDD_ODBCDSN_DIALOG };
	CListCtrl	m_Grid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDSNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CODBCDSNDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDSNDLG_H__A844AB3C_5426_4126_859B_A732C327359B__INCLUDED_)
