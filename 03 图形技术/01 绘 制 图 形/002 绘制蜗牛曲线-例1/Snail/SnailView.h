// SnailView.h : interface of the CSnailView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAILVIEW_H__28802BCA_CCD0_4580_9C51_EE94262F91FA__INCLUDED_)
#define AFX_SNAILVIEW_H__28802BCA_CCD0_4580_9C51_EE94262F91FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnailView : public CView
{
protected: // create from serialization only
	CSnailView();
	DECLARE_DYNCREATE(CSnailView)
	double pi;
// Attributes
public:
	CSnailDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnailView)
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
	virtual ~CSnailView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnailView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnailView.cpp
inline CSnailDoc* CSnailView::GetDocument()
   { return (CSnailDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAILVIEW_H__28802BCA_CCD0_4580_9C51_EE94262F91FA__INCLUDED_)
