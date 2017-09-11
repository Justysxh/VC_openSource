// SerialInterfaceDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_SERIALINTERFACEDLG_H__8AB87660_F850_47B4_9225_36F4BD644C77__INCLUDED_)
#define AFX_SERIALINTERFACEDLG_H__8AB87660_F850_47B4_9225_36F4BD644C77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSerialInterfaceDlg dialog

class CSerialInterfaceDlg : public CDialog
{
// Construction
public:
	CSerialInterfaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSerialInterfaceDlg)
	enum { IDD = IDD_SERIALINTERFACE_DIALOG };
	CEdit	m_Edit;
	CMSComm	m_msc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialInterfaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSerialInterfaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButobtain();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALINTERFACEDLG_H__8AB87660_F850_47B4_9225_36F4BD644C77__INCLUDED_)
