// AffairDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_AFFAIRDLG_H__77B2C050_6362_4297_B35F_831BB49040B0__INCLUDED_)
#define AFX_AFFAIRDLG_H__77B2C050_6362_4297_B35F_831BB49040B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAffairDlg dialog

class CAffairDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	void OnInitADOConn();
	CAffairDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CAffairDlg)
	enum { IDD = IDD_AFFAIR_DIALOG };
	CAdodc	m_Adodc;
	CString	m_Name;
	CString	m_Laborage;
	CString	m_Id;
	CString	m_Dep;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAffairDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAffairDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonmod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFFAIRDLG_H__77B2C050_6362_4297_B35F_831BB49040B0__INCLUDED_)
