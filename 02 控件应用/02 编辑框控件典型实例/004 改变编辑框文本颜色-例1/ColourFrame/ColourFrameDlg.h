// ColourFrameDlg.h : header file
//

#if !defined(AFX_COLOURFRAMEDLG_H__C854038D_9004_47B3_9F34_60E07985C50D__INCLUDED_)
#define AFX_COLOURFRAMEDLG_H__C854038D_9004_47B3_9F34_60E07985C50D__INCLUDED_
#include "ColourEdit.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColourFrameDlg dialog

class CColourFrameDlg : public CDialog
{
// Construction
public:
	CColourFrameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColourFrameDlg)
	enum { IDD = IDD_COLOURFRAME_DIALOG };
	CColourEdit	m_edit8;
	CColourEdit	m_edit7;
	CColourEdit	m_edit6;
	CColourEdit	m_edit5;
	CColourEdit	m_edit4;
	CColourEdit	m_edit3;
	CColourEdit	m_edit2;
	CColourEdit	m_edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColourFrameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColourFrameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOURFRAMEDLG_H__C854038D_9004_47B3_9F34_60E07985C50D__INCLUDED_)
