#if !defined(AFX_MYSTATIC_H__98E2D694_E860_4674_8F5F_4A8EF383B9E4__INCLUDED_)
#define AFX_MYSTATIC_H__98E2D694_E860_4674_8F5F_4A8EF383B9E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyStatic window

class CMyStatic : public CStatic
{
// Construction
public:
	CMyStatic();
	BOOL islined;  //是否有下划线
	BOOL isframed; //是否有边框

	BOOL isLeft;   //是否有左边线
	BOOL isRight;  //是否有右边线
	BOOL isTop;    //是否有上边线
	BOOL isBottom; //是否有下边线

	COLORREF m_color;      //文本颜色
	COLORREF m_framecolor; //边框颜色
	UINT     m_lindwidth;  //边线宽度
	UINT     align;        //文本对齐方式

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyStatic)
	afx_msg void OnPaint();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTATIC_H__98E2D694_E860_4674_8F5F_4A8EF383B9E4__INCLUDED_)
