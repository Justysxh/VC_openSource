// VirtualKeyDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_VIRTUALKEYDLG_H__6E48A12F_8B6A_407B_BD1B_17FED4A4C9A2__INCLUDED_)
#define AFX_VIRTUALKEYDLG_H__6E48A12F_8B6A_407B_BD1B_17FED4A4C9A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVirtualKeyDlg dialog

class CVirtualKeyDlg : public CDialog
{
// Construction
public:
	void OnBtnClick(HWND hButton);
	CVirtualKeyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVirtualKeyDlg)
	enum { IDD = IDD_VIRTUALKEY_DIALOG };
	CEdit	m_Data;
	CAdodc	m_ADODC;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualKeyDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVirtualKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnChangeData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALKEYDLG_H__6E48A12F_8B6A_407B_BD1B_17FED4A4C9A2__INCLUDED_)
