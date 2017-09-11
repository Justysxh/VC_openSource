// SelectIntoDlg.h : header file
//
//{{AFX_INCLUDES()
#include "datagrid.h"
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_SELECTINTODLG_H__9751B164_F0C4_403E_B641_DB7F64597765__INCLUDED_)
#define AFX_SELECTINTODLG_H__9751B164_F0C4_403E_B641_DB7F64597765__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSelectIntoDlg dialog

class CSelectIntoDlg : public CDialog
{
// Construction
public:
	void ExitConnect();
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void OnInitADOConn();
	CSelectIntoDlg(CWnd* pParent = NULL);	// standard constructor

    _ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CSelectIntoDlg)
	enum { IDD = IDD_SELECTINTO_DIALOG };
	CDataGrid	m_datagrid;
	CAdodc	m_adodc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectIntoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSelectIntoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtoncopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTINTODLG_H__9751B164_F0C4_403E_B641_DB7F64597765__INCLUDED_)
