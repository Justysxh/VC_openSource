// SQLframeDlg.h : header file
//

#if !defined(AFX_SQLFRAMEDLG_H__E9A7F933_F15C_4893_9698_A1C1CAD61118__INCLUDED_)
#define AFX_SQLFRAMEDLG_H__E9A7F933_F15C_4893_9698_A1C1CAD61118__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSQLframeDlg dialog

class CSQLframeDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn(CString strsjk);
	CSQLframeDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CString str,strname;
// Dialog Data
	//{{AFX_DATA(CSQLframeDlg)
	enum { IDD = IDD_SQLFRAME_DIALOG };
	CListCtrl	m_grid;
	CListBox	m_list;
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQLframeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSQLframeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButconn();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLFRAMEDLG_H__E9A7F933_F15C_4893_9698_A1C1CAD61118__INCLUDED_)
