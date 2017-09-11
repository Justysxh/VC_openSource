// MultiComboBoxDlg.h : header file
//

#if !defined(AFX_MULTICOMBOBOXDLG_H__D5448EE3_DEAD_4A47_8DBB_0667B097B5F5__INCLUDED_)
#define AFX_MULTICOMBOBOXDLG_H__D5448EE3_DEAD_4A47_8DBB_0667B097B5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "mycombobox.h"
/////////////////////////////////////////////////////////////////////////////
// CMultiComboBoxDlg dialog

class CMultiComboBoxDlg : public CDialog
{
// Construction
public:
	CMultiComboBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiComboBoxDlg)
	enum { IDD = IDD_MULTICOMBOBOX_DIALOG };
	MyComboBox	m_mulcmb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiComboBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiComboBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTICOMBOBOXDLG_H__D5448EE3_DEAD_4A47_8DBB_0667B097B5F5__INCLUDED_)
