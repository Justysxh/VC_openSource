// MosaicViewView.h : interface of the CMosaicViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOSAICVIEWVIEW_H__F2F09177_BF7D_48FF_914E_35B1E7D719AA__INCLUDED_)
#define AFX_MOSAICVIEWVIEW_H__F2F09177_BF7D_48FF_914E_35B1E7D719AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "vfw.h"

class CMosaicViewView : public CView
{
protected: // create from serialization only
	CMosaicViewView();
	DECLARE_DYNCREATE(CMosaicViewView)
	BITMAP bm;
	HBITMAP m_bmpSrc;
	COLORREF*m_clrSrc;
	CSize m_size;
	HDRAWDIB m_hDrawDib;
// Attributes
public:
	CMosaicViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMosaicViewView)
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
	virtual ~CMosaicViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


// Generated message map functions
protected:
	//{{AFX_MSG(CMosaicViewView)
	afx_msg void OnView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MosaicViewView.cpp
inline CMosaicViewDoc* CMosaicViewView::GetDocument()
   { return (CMosaicViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOSAICVIEWVIEW_H__F2F09177_BF7D_48FF_914E_35B1E7D719AA__INCLUDED_)
