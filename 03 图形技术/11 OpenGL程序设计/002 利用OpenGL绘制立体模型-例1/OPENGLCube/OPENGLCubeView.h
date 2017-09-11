// OPENGLCubeView.h : interface of the COPENGLCubeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLCUBEVIEW_H__68DC917F_5E08_490B_B74C_C86D6DDA1710__INCLUDED_)
#define AFX_OPENGLCUBEVIEW_H__68DC917F_5E08_490B_B74C_C86D6DDA1710__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"

class COPENGLCubeView : public CView
{
protected: // create from serialization only
	COPENGLCubeView();
	DECLARE_DYNCREATE(COPENGLCubeView)

// Attributes
public:
	COPENGLCubeDoc* GetDocument();
	CDC* m_pContextDC;
	HGLRC m_hOpenglRC;
	CRect oldrc;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLCubeView)
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
	virtual ~COPENGLCubeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLCubeView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OPENGLCubeView.cpp
inline COPENGLCubeDoc* COPENGLCubeView::GetDocument()
   { return (COPENGLCubeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLCUBEVIEW_H__68DC917F_5E08_490B_B74C_C86D6DDA1710__INCLUDED_)
