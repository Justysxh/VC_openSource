#if !defined(AFX_LISTBUTTON_H__73821457_3B52_490E_9277_B4928080ED20__INCLUDED_)
#define AFX_LISTBUTTON_H__73821457_3B52_490E_9277_B4928080ED20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListButton window

class CListButton : public CButton
{
// Construction
public:
	CListButton();
	UINT		m_Index;		//导航按钮索引
	BOOL		m_Toped;		//按钮是否在列表上方
	CStringList m_ButtonItems;	//按钮关联的图像列表项
	CStringList m_ButtonIndex;	//按钮关联的图像索引

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBUTTON_H__73821457_3B52_490E_9277_B4928080ED20__INCLUDED_)
