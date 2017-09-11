// OPENGLNURBSView.h : interface of the COPENGLNURBSView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLNURBSVIEW_H__1ED8E8CC_7AAF_458F_AD33_799A46EA08C7__INCLUDED_)
#define AFX_OPENGLNURBSVIEW_H__1ED8E8CC_7AAF_458F_AD33_799A46EA08C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"

class COPENGLNURBSView : public CView
{
protected: // create from serialization only
	COPENGLNURBSView();
	DECLARE_DYNCREATE(COPENGLNURBSView)

// Attributes
public:
	COPENGLNURBSDoc* GetDocument();
	CDC* m_pContextDC;
	HGLRC m_hOpenglRC;
	CRect oldrc;
	GLUnurbsObj *nurb;
	GLfloat point[4][4][3];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLNURBSView)
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
	virtual ~COPENGLNURBSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLNURBSView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OPENGLNURBSView.cpp
inline COPENGLNURBSDoc* COPENGLNURBSView::GetDocument()
   { return (COPENGLNURBSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLNURBSVIEW_H__1ED8E8CC_7AAF_458F_AD33_799A46EA08C7__INCLUDED_)
