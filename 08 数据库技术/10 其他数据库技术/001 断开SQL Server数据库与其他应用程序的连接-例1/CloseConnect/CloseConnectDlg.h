// CloseConnectDlg.h : header file
//

#if !defined(AFX_CLOSECONNECTDLG_H__52409D93_7A2A_4852_9A04_07EBD2B3744A__INCLUDED_)
#define AFX_CLOSECONNECTDLG_H__52409D93_7A2A_4852_9A04_07EBD2B3744A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCloseConnectDlg dialog

class CCloseConnectDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void ExecuteSQL(_bstr_t bstrSQL);
	void OnInitADOConn();
	CCloseConnectDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CCloseConnectDlg)
	enum { IDD = IDD_CLOSECONNECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCloseConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCloseConnectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButclose();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSECONNECTDLG_H__52409D93_7A2A_4852_9A04_07EBD2B3744A__INCLUDED_)
