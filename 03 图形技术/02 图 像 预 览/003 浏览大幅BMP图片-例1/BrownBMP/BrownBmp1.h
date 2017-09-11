#if !defined(AFX_BROWNBMP1_H__B7C61A27_CD99_4CF5_B56D_701F5379146F__INCLUDED_)
#define AFX_BROWNBMP1_H__B7C61A27_CD99_4CF5_B56D_701F5379146F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BrownBmp1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBrownBmp window

class CBrownBmp : public CStatic
{
// Construction
public:
	CBrownBmp();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrownBmp)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBrownBmp();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBrownBmp)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWNBMP1_H__B7C61A27_CD99_4CF5_B56D_701F5379146F__INCLUDED_)
