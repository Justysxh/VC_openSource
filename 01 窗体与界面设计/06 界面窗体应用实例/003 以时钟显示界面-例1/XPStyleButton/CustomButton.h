#if !defined(AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_)
#define AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomButton window
//定义按钮状态
enum ButtonState  {bsNormal,bsHot,bsDown};//正常状态，热点状态、按下状态

class CCustomButton : public CButton
{
// Construction
public:
	CCustomButton();
	int         m_State;           //按钮当前状态
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomButton)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMBUTTON_H__676681A3_AC3E_4FC4_8D70_0D1B1A5E776A__INCLUDED_)
