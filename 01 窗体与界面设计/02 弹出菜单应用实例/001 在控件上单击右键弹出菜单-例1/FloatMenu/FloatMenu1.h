#if !defined(AFX_FLOATMENU1_H__5A17F370_D834_4727_8703_553311DA21E4__INCLUDED_)
#define AFX_FLOATMENU1_H__5A17F370_D834_4727_8703_553311DA21E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FloatMenu1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFloatMenu window

class CFloatMenu : public CToolBar
{
// Construction
public:
	CFloatMenu();
	int MenuPopIndex;
	CMenu* m_pSubMenu;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatMenu)
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT GetIndexFromPoint(CPoint pot);
	BOOL AddButtonFromMenu(UINT IDresource);
	virtual ~CFloatMenu();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFloatMenu)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATMENU1_H__5A17F370_D834_4727_8703_553311DA21E4__INCLUDED_)
