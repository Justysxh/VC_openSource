// IconMenuView.h : interface of the CIconMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONMENUVIEW_H__5A9BFC43_8AED_4412_AB79_537B78E0B358__INCLUDED_)
#define AFX_ICONMENUVIEW_H__5A9BFC43_8AED_4412_AB79_537B78E0B358__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIconMenuView : public CView
{
protected: // create from serialization only
	CIconMenuView();
	DECLARE_DYNCREATE(CIconMenuView)

// Attributes
public:
	CIconMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconMenuView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIconMenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IconMenuView.cpp
inline CIconMenuDoc* CIconMenuView::GetDocument()
   { return (CIconMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONMENUVIEW_H__5A9BFC43_8AED_4412_AB79_537B78E0B358__INCLUDED_)
