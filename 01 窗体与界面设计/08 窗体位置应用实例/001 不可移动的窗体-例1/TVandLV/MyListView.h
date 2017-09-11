#if !defined(AFX_MYLISTVIEW_H__C491ED63_1A77_40AB_AC08_57B29659DA5E__INCLUDED_)
#define AFX_MYLISTVIEW_H__C491ED63_1A77_40AB_AC08_57B29659DA5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListView.h : header file
//
#include "afxcview.h"
/////////////////////////////////////////////////////////////////////////////
// CMyListView view

class CMyListView : public CListView
{
protected:
	CMyListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyListView)

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTVIEW_H__C491ED63_1A77_40AB_AC08_57B29659DA5E__INCLUDED_)
