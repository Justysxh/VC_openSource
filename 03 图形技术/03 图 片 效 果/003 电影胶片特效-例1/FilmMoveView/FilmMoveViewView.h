// FilmMoveViewView.h : interface of the CFilmMoveViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILMMOVEVIEWVIEW_H__94A26399_CC7E_46B2_B109_C207905ECE23__INCLUDED_)
#define AFX_FILMMOVEVIEWVIEW_H__94A26399_CC7E_46B2_B109_C207905ECE23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vfw.h"
class CFilmMoveViewView : public CView
{
protected: // create from serialization only
	CFilmMoveViewView();
	DECLARE_DYNCREATE(CFilmMoveViewView)

// Attributes
public:
	CFilmMoveViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilmMoveViewView)
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
	virtual ~CFilmMoveViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
		HBITMAP m_bmpSrc;
		COLORREF*m_clrSrc;
		CSize m_size;
		HDRAWDIB m_hDrawDib;
		BITMAP bm;
// Generated message map functions
protected:
	//{{AFX_MSG(CFilmMoveViewView)
	afx_msg void OnView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FilmMoveViewView.cpp
inline CFilmMoveViewDoc* CFilmMoveViewView::GetDocument()
   { return (CFilmMoveViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILMMOVEVIEWVIEW_H__94A26399_CC7E_46B2_B109_C207905ECE23__INCLUDED_)
