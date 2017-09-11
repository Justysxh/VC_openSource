// DOGDlg.h : header file
//

#if !defined(AFX_DOGDLG_H__71E2EC84_ED5F_47AB_A021_DA9B1AF60A19__INCLUDED_)
#define AFX_DOGDLG_H__71E2EC84_ED5F_47AB_A021_DA9B1AF60A19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDOGDlg dialog
#include "softdog.h"

extern short int DogBytes;
extern short int DogAddr;
extern void * DogData;

class CDOGDlg : public CDialog
{
// Construction
public:
	CDOGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDOGDlg)
	enum { IDD = IDD_DOG_DIALOG };
	CString	m_Data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDOGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDOGDlg)
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

#endif // !defined(AFX_DOGDLG_H__71E2EC84_ED5F_47AB_A021_DA9B1AF60A19__INCLUDED_)
