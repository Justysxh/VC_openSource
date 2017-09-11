// BrownBMPDlg.h : header file
//

#if !defined(AFX_BROWNBMPDLG_H__82AD5396_CCDA_4E41_A38E_2FCC498C4119__INCLUDED_)
#define AFX_BROWNBMPDLG_H__82AD5396_CCDA_4E41_A38E_2FCC498C4119__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BmpDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CBrownBMPDlg dialog

class CBrownBMPDlg : public CDialog
{
// Construction
public:
	CBrownBMPDlg(CWnd* pParent = NULL);	// standard constructor
	
	CBmpDlg m_BrownDlg;

// Dialog Data
	//{{AFX_DATA(CBrownBMPDlg)
	enum { IDD = IDD_BROWNBMP_DIALOG };
	CStatic	m_Frame;
	CStatic	m_Bmp;
	CString	m_Path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrownBMPDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBrownBMPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrown();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWNBMPDLG_H__82AD5396_CCDA_4E41_A38E_2FCC498C4119__INCLUDED_)
