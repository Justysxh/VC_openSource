#if !defined(AFX_TEXTPROGRESS1_H__C1EBDD13_15B8_43BC_8463_F881C2AD5BEB__INCLUDED_)
#define AFX_TEXTPROGRESS1_H__C1EBDD13_15B8_43BC_8463_F881C2AD5BEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextProgress1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextProgress window

class CTextProgress : public CProgressCtrl
{
// Construction
public:
	CTextProgress();
	COLORREF m_crText;		//文本颜色
	COLORREF m_crProgress;	//进度颜色
	COLORREF m_crBlank;		//空白区域颜色
	
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextProgress)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextProgress();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTextProgress)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPROGRESS1_H__C1EBDD13_15B8_43BC_8463_F881C2AD5BEB__INCLUDED_)
