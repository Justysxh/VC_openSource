// PrintRemitFormDlg.h : header file
//
//{{AFX_INCLUDES()
#include "animation.h"
//}}AFX_INCLUDES

#if !defined(AFX_PRINTREMITFORMDLG_H__E17E6B7E_0AE5_4DB9_A0E6_B566AD77C531__INCLUDED_)
#define AFX_PRINTREMITFORMDLG_H__E17E6B7E_0AE5_4DB9_A0E6_B566AD77C531__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrintRemitFormDlg dialog
#include "MyStatic.h"

class CPrintRemitFormDlg : public CDialog
{
// Construction
public:
	CPrintRemitFormDlg(CWnd* pParent = NULL);	// standard constructor
	CFont m_font;
// Dialog Data
	//{{AFX_DATA(CPrintRemitFormDlg)
	enum { IDD = IDD_PRINTREMITFORM_DIALOG };
	CMyStatic	m_frame20;
	CMyStatic	m_frame19;
	CMyStatic	m_rename3;
	CMyStatic	m_sendpeople;
	CMyStatic	m_frame18;
	CMyStatic	m_frame17;
	CMyStatic	m_addr2;
	CMyStatic	m_frame16;
	CMyStatic	m_sendperson;
	CMyStatic	m_frame15;
	CMyStatic	m_frame14;
	CMyStatic	m_frame13;
	CMyStatic	m_rename;
	CMyStatic	m_reperson;
	CMyStatic	m_frame12;
	CMyStatic	m_frame11;
	CMyStatic	m_addr;
	CMyStatic	m_receive;
	CMyStatic	m_frame10;
	CStatic	m_money;
	CMyStatic	m_text10;
	CMyStatic	m_text9;
	CMyStatic	m_frame4;
	CMyStatic	m_frame3;
	CMyStatic	m_frame8;
	CMyStatic	m_frame7;
	CMyStatic	m_frame6;
	CMyStatic	m_text6;
	CMyStatic	m_line2;
	CMyStatic	m_frame2;
	CMyStatic	m_frame1;
	CMyStatic	m_title;
	CMyStatic	m_num6;
	CMyStatic	m_num5;
	CMyStatic	m_num4;
	CMyStatic	m_num3;
	CMyStatic	m_num2;
	CMyStatic	m_num1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRemitFormDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrintRemitFormDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTREMITFORMDLG_H__E17E6B7E_0AE5_4DB9_A0E6_B566AD77C531__INCLUDED_)
