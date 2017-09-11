// SmoothnessDlg.h : header file
//

#if !defined(AFX_SMOOTHNESSDLG_H__1A840A25_A94E_4A31_9FD8_217B806F5E9D__INCLUDED_)
#define AFX_SMOOTHNESSDLG_H__1A840A25_A94E_4A31_9FD8_217B806F5E9D__INCLUDED_
#include "FrameDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSmoothnessDlg dialog

class CSmoothnessDlg : public CDialog
{
// Construction
public:
	CSmoothnessDlg(CWnd* pParent = NULL);	// standard constructor
	CFrameDlg dlg;
	HBITMAP m_hBitmap;
// Dialog Data
	//{{AFX_DATA(CSmoothnessDlg)
	enum { IDD = IDD_SMOOTHNESS_DIALOG };
	CSliderCtrl	m_slider;
	CStatic	m_picture;
	CStatic	m_frame;
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmoothnessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSmoothnessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButopen();
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButdraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMOOTHNESSDLG_H__1A840A25_A94E_4A31_9FD8_217B806F5E9D__INCLUDED_)
