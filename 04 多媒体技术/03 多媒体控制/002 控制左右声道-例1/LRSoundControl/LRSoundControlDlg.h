// LRSoundControlDlg.h : header file
//

#if !defined(AFX_LRSOUNDCONTROLDLG_H__134FA1D9_8157_45FA_9416_69F568982B4E__INCLUDED_)
#define AFX_LRSOUNDCONTROLDLG_H__134FA1D9_8157_45FA_9416_69F568982B4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLRSoundControlDlg dialog

class CLRSoundControlDlg : public CDialog
{
// Construction
public:
	CLRSoundControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLRSoundControlDlg)
	enum { IDD = IDD_LRSOUNDCONTROL_DIALOG };
	CSliderCtrl	m_right;
	CSliderCtrl	m_left;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLRSoundControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLRSoundControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LRSOUNDCONTROLDLG_H__134FA1D9_8157_45FA_9416_69F568982B4E__INCLUDED_)
