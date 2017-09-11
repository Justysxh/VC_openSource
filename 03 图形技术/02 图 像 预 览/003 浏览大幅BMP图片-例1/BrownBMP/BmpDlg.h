#if !defined(AFX_BMPDLG_H__701312CF_5CB2_404A_B34D_F590191647EF__INCLUDED_)
#define AFX_BMPDLG_H__701312CF_5CB2_404A_B34D_F590191647EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BmpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBmpDlg dialog

class CBmpDlg : public CDialog
{
// Construction
public:
	CBmpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpDlg)
	enum { IDD = IDD_BMPDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(CBmpDlg)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPDLG_H__701312CF_5CB2_404A_B34D_F590191647EF__INCLUDED_)
