// ShutterView.h : interface of the CShutterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHUTTERVIEW_H__A863F4E3_ABBB_474A_BDE2_190EE67340E2__INCLUDED_)
#define AFX_SHUTTERVIEW_H__A863F4E3_ABBB_474A_BDE2_190EE67340E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vfw.h"
class CShutterView : public CView
{
protected: // create from serialization only
	CShutterView();
	DECLARE_DYNCREATE(CShutterView)
	BOOL bstart;
// Attributes
public:
	CShutterDoc* GetDocument();

// Operations
public:
HBITMAP m_bmpSrc;
COLORREF*m_clrSrc;
CSize m_size;
HDRAWDIB m_hDrawDib;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutterView)
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
	virtual ~CShutterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShutterView)
	afx_msg void OnView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShutterView.cpp
inline CShutterDoc* CShutterView::GetDocument()
   { return (CShutterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTTERVIEW_H__A863F4E3_ABBB_474A_BDE2_190EE67340E2__INCLUDED_)
