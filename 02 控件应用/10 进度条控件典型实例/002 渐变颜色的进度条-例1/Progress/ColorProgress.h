#if !defined(AFX_COLORPROGRESS_H__121D84E5_2306_49F0_AFE3_26F50E2AD35D__INCLUDED_)
#define AFX_COLORPROGRESS_H__121D84E5_2306_49F0_AFE3_26F50E2AD35D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorProgress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorProgress window

class CColorProgress : public CProgressCtrl
{
// Construction
public:
	CColorProgress();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorProgress)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CColorProgress();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorProgress)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPROGRESS_H__121D84E5_2306_49F0_AFE3_26F50E2AD35D__INCLUDED_)
