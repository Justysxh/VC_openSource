// TreeNaviView.h : interface of the CTreeNaviView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREENAVIVIEW_H__9FA6EA80_B74B_48E1_96A3_C5E545B4902E__INCLUDED_)
#define AFX_TREENAVIVIEW_H__9FA6EA80_B74B_48E1_96A3_C5E545B4902E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "treenavidoc.h"
class CTreeNaviView : public CView
{
protected: // create from serialization only
	CTreeNaviView();
	DECLARE_DYNCREATE(CTreeNaviView)

// Attributes
public:
	CTreeNaviDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeNaviView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeNaviView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeNaviView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TreeNaviView.cpp
inline CTreeNaviDoc* CTreeNaviView::GetDocument()
   { return (CTreeNaviDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREENAVIVIEW_H__9FA6EA80_B74B_48E1_96A3_C5E545B4902E__INCLUDED_)
