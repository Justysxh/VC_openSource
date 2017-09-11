#if !defined(AFX_CUSTOMBUTTON_H__2F23D057_062F_4148_8EDF_24B9BFF68538__INCLUDED_)
#define AFX_CUSTOMBUTTON_H__2F23D057_062F_4148_8EDF_24B9BFF68538__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomButton window

class CCustomButton : public CButton
{	
// Construction
public:
	CCustomButton();
	int m_num;
	BOOL m_result;
	COLORREF m_color;
	CPoint arrays[6];
	BOOL IsPressed; //按钮是否被按下
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetResult(BOOL result,COLORREF color);
	void SetPolygon(int num);
	virtual ~CCustomButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMBUTTON_H__2F23D057_062F_4148_8EDF_24B9BFF68538__INCLUDED_)
