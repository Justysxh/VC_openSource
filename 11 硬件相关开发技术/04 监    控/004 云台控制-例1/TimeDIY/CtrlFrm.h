#if !defined(AFX_CTRLFRM_H__AD145EAF_1BCC_4E0D_9AE5_312589196C4B__INCLUDED_)
#define AFX_CTRLFRM_H__AD145EAF_1BCC_4E0D_9AE5_312589196C4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CtrlFrm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCtrlFrm dialog
#include "TimeDIYDlg.h"

class CCtrlFrm : public CDialog
{
// Construction
public:
	CCtrlFrm(CWnd* pParent = NULL);   // standard constructor
	CEdit *m_pEdit[8];
	CTimeDIYDlg* m_pMain;

// Dialog Data
	//{{AFX_DATA(CCtrlFrm)
	enum { IDD = IDD_CTRLFRM_DIALOG };
	CEdit	m_Setting;
	CComboBox	m_Port;
	CEdit	m_ByteNum;
	CEdit	m_Byte8;
	CEdit	m_Byte7;
	CEdit	m_Byte6;
	CEdit	m_Byte5;
	CEdit	m_Byte4;
	CEdit	m_Byte3;
	CEdit	m_Byte2;
	CEdit	m_Byte1;
	CComboBox	m_Actions;
	CEdit	m_ActionNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlFrm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCtrlFrm)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnPortset();
	afx_msg void OnCmdset();
	afx_msg void OnQuit();
	afx_msg void OnSelchangeActions();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLFRM_H__AD145EAF_1BCC_4E0D_9AE5_312589196C4B__INCLUDED_)
