// BitmapButtonDlg.h : header file
//

#if !defined(AFX_BITMAPBUTTONDLG_H__1ABD82DD_1AB0_4FE1_9725_58548700264D__INCLUDED_)
#define AFX_BITMAPBUTTONDLG_H__1ABD82DD_1AB0_4FE1_9725_58548700264D__INCLUDED_
#include "ButtonHot.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDlg dialog

class CBitmapButtonDlg : public CDialog
{
// Construction
public:
	CBitmapButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBitmapButtonDlg)
	enum { IDD = IDD_BITMAPBUTTON_DIALOG };
	CButtonHot	m_Hot;
	CButtonHot	m_Mrkj;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBitmapButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBUTTONDLG_H__1ABD82DD_1AB0_4FE1_9725_58548700264D__INCLUDED_)
