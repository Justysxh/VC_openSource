// updatedatasDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
//}}AFX_INCLUDES

#if !defined(AFX_UPDATEDATASDLG_H__90A11B22_26CE_48DA_9EED_4091C267F5EF__INCLUDED_)
#define AFX_UPDATEDATASDLG_H__90A11B22_26CE_48DA_9EED_4091C267F5EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUpdatedatasDlg dialog

class CUpdatedatasDlg : public CDialog
{
// Construction
public:
	CUpdatedatasDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdatedatasDlg)
	enum { IDD = IDD_UPDATEDATAS_DIALOG };
	CAdodc	m_adodc;
	int		m_laborage1;
	int		m_laborage2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdatedatasDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUpdatedatasDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEDATASDLG_H__90A11B22_26CE_48DA_9EED_4091C267F5EF__INCLUDED_)
