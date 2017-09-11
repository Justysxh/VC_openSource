// SinusoidView.h : interface of the CSinusoidView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINUSOIDVIEW_H__D196F096_2CC9_4243_A5D1_25A6EF45A949__INCLUDED_)
#define AFX_SINUSOIDVIEW_H__D196F096_2CC9_4243_A5D1_25A6EF45A949__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinusoidView : public CView
{
protected: // create from serialization only
	CSinusoidView();
	DECLARE_DYNCREATE(CSinusoidView)

// Attributes
public:
	CSinusoidDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinusoidView)
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
	virtual ~CSinusoidView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinusoidView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SinusoidView.cpp
inline CSinusoidDoc* CSinusoidView::GetDocument()
   { return (CSinusoidDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINUSOIDVIEW_H__D196F096_2CC9_4243_A5D1_25A6EF45A949__INCLUDED_)
