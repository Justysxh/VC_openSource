// OPENGLActView.h : interface of the COPENGLActView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLACTVIEW_H__F2A75E21_F555_42B6_AE00_EED450025B5B__INCLUDED_)
#define AFX_OPENGLACTVIEW_H__F2A75E21_F555_42B6_AE00_EED450025B5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"

class COPENGLActView : public CView
{
protected: // create from serialization only
	COPENGLActView();
	DECLARE_DYNCREATE(COPENGLActView)

// Attributes
public:
	COPENGLActDoc* GetDocument();
	CDC* m_pContextDC;
	HGLRC m_hOpenglRC;
	CRect oldrc;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLActView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COPENGLActView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLActView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAct();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OPENGLActView.cpp
inline COPENGLActDoc* COPENGLActView::GetDocument()
   { return (COPENGLActDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLACTVIEW_H__F2A75E21_F555_42B6_AE00_EED450025B5B__INCLUDED_)
