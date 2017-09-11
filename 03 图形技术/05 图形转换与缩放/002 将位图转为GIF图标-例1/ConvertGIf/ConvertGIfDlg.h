// ConvertGIfDlg.h : header file
//
//{{AFX_INCLUDES()
#include "gif.h"
//}}AFX_INCLUDES

#if !defined(AFX_CONVERTGIFDLG_H__E041F4AB_FB24_4168_885F_35B5C0FA5697__INCLUDED_)
#define AFX_CONVERTGIFDLG_H__E041F4AB_FB24_4168_885F_35B5C0FA5697__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CConvertGIfDlg dialog

class CConvertGIfDlg : public CDialog
{
// Construction
public:
	CConvertGIfDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CConvertGIfDlg)
	enum { IDD = IDD_CONVERTGIF_DIALOG };
	CStatic	m_Image;
	CString	m_FileName;
	CGIF	m_Gif;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertGIfDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConvertGIfDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrown();
	afx_msg void OnConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTGIFDLG_H__E041F4AB_FB24_4168_885F_35B5C0FA5697__INCLUDED_)
