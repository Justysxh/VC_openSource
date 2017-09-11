// ComboBoxClrDlg.h : header file
//

#if !defined(AFX_COMBOBOXCLRDLG_H__66A49750_057F_4CE8_A8B4_BE128956346F__INCLUDED_)
#define AFX_COMBOBOXCLRDLG_H__66A49750_057F_4CE8_A8B4_BE128956346F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ColorCombox.h"
/////////////////////////////////////////////////////////////////////////////
// CComboBoxClrDlg dialog

class CComboBoxClrDlg : public CDialog
{
// Construction
public:
	CComboBoxClrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComboBoxClrDlg)
	enum { IDD = IDD_COMBOBOXCLR_DIALOG };
	CStatic	m_Demo;
	CColorCombox	m_ColorBox;
	//}}AFX_DATA

	COLORREF  m_clrColor; 
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxClrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CComboBoxClrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void OnOK();
	afx_msg void OnSelchangeColorbox();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXCLRDLG_H__66A49750_057F_4CE8_A8B4_BE128956346F__INCLUDED_)
