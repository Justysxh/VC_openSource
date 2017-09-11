#if !defined(AFX_IMAGEPANEL_H__F0E527D1_07E6_4F09_BB01_8395451F674D__INCLUDED_)
#define AFX_IMAGEPANEL_H__F0E527D1_07E6_4F09_BB01_8395451F674D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImagePanel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImagePanel dialog

class CImagePanel : public CDialog
{
// Construction
public:
	CImagePanel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImagePanel)
	enum { IDD = IDD_IMAGEPANEL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagePanel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(CImagePanel)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPANEL_H__F0E527D1_07E6_4F09_BB01_8395451F674D__INCLUDED_)
