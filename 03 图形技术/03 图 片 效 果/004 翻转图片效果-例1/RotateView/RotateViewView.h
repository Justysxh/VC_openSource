// RotateViewView.h : interface of the CRotateViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATEVIEWVIEW_H__009944DE_A6D2_4FB8_94CB_AEE854710200__INCLUDED_)
#define AFX_ROTATEVIEWVIEW_H__009944DE_A6D2_4FB8_94CB_AEE854710200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vfw.h"
class CRotateViewView : public CView
{
protected: // create from serialization only
	CRotateViewView();
	DECLARE_DYNCREATE(CRotateViewView)

// Attributes
public:
	CRotateViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateViewView)
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
	virtual ~CRotateViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HBITMAP m_bmpSrc;
	COLORREF*m_clrSrc;
	CSize m_sizeSrc;
	HBITMAP m_bmpDst;
	COLORREF *m_clrDst;
	CSize m_sizeDst;
	HDRAWDIB m_hDrawDib;
	int m_nType;
	BITMAP bm;
// Generated message map functions
protected:
	//{{AFX_MSG(CRotateViewView)
	afx_msg void OnView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RotateViewView.cpp
inline CRotateViewDoc* CRotateViewView::GetDocument()
   { return (CRotateViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEVIEWVIEW_H__009944DE_A6D2_4FB8_94CB_AEE854710200__INCLUDED_)
