// ImageTextDlg.h : header file
//

#if !defined(AFX_IMAGETEXTDLG_H__A0ED2AD9_89A9_4DD1_84A8_5ED951DAAEC1__INCLUDED_)
#define AFX_IMAGETEXTDLG_H__A0ED2AD9_89A9_4DD1_84A8_5ED951DAAEC1__INCLUDED_
#include "ImageButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CImageTextDlg dialog

class CImageTextDlg : public CDialog
{
// Construction
public:
	CImageTextDlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_images;
// Dialog Data
	//{{AFX_DATA(CImageTextDlg)
	enum { IDD = IDD_IMAGETEXT_DIALOG };
	ImageButton	m_button4;
	ImageButton	m_button3;
	ImageButton	m_button2;
	ImageButton	m_button1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageTextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CImageTextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETEXTDLG_H__A0ED2AD9_89A9_4DD1_84A8_5ED951DAAEC1__INCLUDED_)
