// TelephoneDlg.h : header file
//

#if !defined(AFX_TELEPHONEDLG_H__033373FA_6AA8_48CA_AE71_F7FCCDE80450__INCLUDED_)
#define AFX_TELEPHONEDLG_H__033373FA_6AA8_48CA_AE71_F7FCCDE80450__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "tapi.h"
/////////////////////////////////////////////////////////////////////////////
// CTelephoneDlg dialog

class CTelephoneDlg : public CDialog
{
// Construction
public:
	CTelephoneDlg(CWnd* pParent = NULL);	// standard constructor

	HLINEAPP m_hApp;
	DWORD  m_tNum;
	DWORD  m_Reversion;
	HLINE  m_hLine;
// Dialog Data
	//{{AFX_DATA(CTelephoneDlg)
	enum { IDD = IDD_TELEPHONE_DIALOG };
	CEdit	m_Number;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTelephoneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTelephoneDlg)
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

#endif // !defined(AFX_TELEPHONEDLG_H__033373FA_6AA8_48CA_AE71_F7FCCDE80450__INCLUDED_)
