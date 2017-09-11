// ReturnPataDlg.h : header file
//

#if !defined(AFX_RETURNPATADLG_H__5F4B0735_DF7A_4417_8F96_47707FC461A1__INCLUDED_)
#define AFX_RETURNPATADLG_H__5F4B0735_DF7A_4417_8F96_47707FC461A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReturnPataDlg dialog

class CReturnPataDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn();
	CReturnPataDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr  m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CReturnPataDlg)
	enum { IDD = IDD_RETURNPATA_DIALOG };
	CListCtrl	m_Grid;
	CString	m_Edit;
	CString	m_Name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnPataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReturnPataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtransfer();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNPATADLG_H__5F4B0735_DF7A_4417_8F96_47707FC461A1__INCLUDED_)
