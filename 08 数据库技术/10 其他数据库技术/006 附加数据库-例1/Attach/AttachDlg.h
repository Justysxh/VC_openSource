// AttachDlg.h : header file
//

#if !defined(AFX_ATTACHDLG_H__C67D856B_1788_4539_AA0A_C8631C7ED929__INCLUDED_)
#define AFX_ATTACHDLG_H__C67D856B_1788_4539_AA0A_C8631C7ED929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAttachDlg dialog

class CAttachDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn();
	CAttachDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CString strText;
	CString strName;
	CString str,strmdf,strlog;
// Dialog Data
	//{{AFX_DATA(CAttachDlg)
	enum { IDD = IDD_ATTACH_DIALOG };
	CListCtrl	m_Grid;
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttachDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAttachDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTACHDLG_H__C67D856B_1788_4539_AA0A_C8631C7ED929__INCLUDED_)
