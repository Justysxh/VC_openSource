#if !defined(AFX_CUSTOMGROUP_H__1AFBC903_1011_4729_A6DF_C15973B035D7__INCLUDED_)
#define AFX_CUSTOMGROUP_H__1AFBC903_1011_4729_A6DF_C15973B035D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomGroup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomGroup window

class CCustomGroup : public CStatic
{
// Construction
public:
	CCustomGroup();
	UINT     m_LeftMargin;  //文本左边距
	COLORREF m_FrameColor;  //边框颜色
	COLORREF m_clText;		//文本颜色
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomGroup)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomGroup();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomGroup)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMGROUP_H__1AFBC903_1011_4729_A6DF_C15973B035D7__INCLUDED_)
