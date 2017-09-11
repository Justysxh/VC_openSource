// PrintBarcodeDlg.h : header file
//
//{{AFX_INCLUDES()
#include "barcodectrl.h"
//}}AFX_INCLUDES

#if !defined(AFX_PRINTBARCODEDLG_H__E3185525_CEF0_4C48_A712_BED8D23B0FC7__INCLUDED_)
#define AFX_PRINTBARCODEDLG_H__E3185525_CEF0_4C48_A712_BED8D23B0FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintBarcodeDlg dialog
#include <math.h>
class CPrintBarcodeDlg : public CDialog
{
// Construction
public:
	CPrintBarcodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintBarcodeDlg)
	enum { IDD = IDD_PRINTBARCODE_DIALOG };
	CListCtrl	m_List;
	CBarCodeCtrl	m_Barcode;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintBarcodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintBarcodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPrint();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTBARCODEDLG_H__E3185525_CEF0_4C48_A712_BED8D23B0FC7__INCLUDED_)
