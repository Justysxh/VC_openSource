// ICCardDlg.h : header file
//

#if !defined(AFX_ICCARDDLG_H__AAC73A08_DAD7_4BF8_BF87_B68040799920__INCLUDED_)
#define AFX_ICCARDDLG_H__AAC73A08_DAD7_4BF8_BF87_B68040799920__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CICCardDlg dialog
#include "ColorLabel.h"
class CICCardDlg : public CDialog
{
// Construction
public:
	CICCardDlg(CWnd* pParent = NULL);	// standard constructor
	HANDLE icdev; //Éè±¸¾ä±ú

// Dialog Data
	//{{AFX_DATA(CICCardDlg)
	enum { IDD = IDD_ICCARD_DIALOG };
	CColorLabel	m_Hint;
	CEdit	m_ICData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CICCardDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICCARDDLG_H__AAC73A08_DAD7_4BF8_BF87_B68040799920__INCLUDED_)
