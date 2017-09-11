// FloatMenuView.h : interface of the CFloatMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOATMENUVIEW_H__617D6257_68A6_44A0_A63C_77C7D74C297C__INCLUDED_)
#define AFX_FLOATMENUVIEW_H__617D6257_68A6_44A0_A63C_77C7D74C297C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFloatMenuView : public CView
{
protected: // create from serialization only
	CFloatMenuView();
	DECLARE_DYNCREATE(CFloatMenuView)

// Attributes
public:
	CFloatMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatMenuView)
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
	virtual ~CFloatMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFloatMenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FloatMenuView.cpp
inline CFloatMenuDoc* CFloatMenuView::GetDocument()
   { return (CFloatMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATMENUVIEW_H__617D6257_68A6_44A0_A63C_77C7D74C297C__INCLUDED_)
