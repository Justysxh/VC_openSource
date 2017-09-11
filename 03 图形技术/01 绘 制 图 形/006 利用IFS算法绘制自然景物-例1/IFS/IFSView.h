// IFSView.h : interface of the CIFSView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFSVIEW_H__D0AD332A_29D2_4AB0_B112_E9101BAAD078__INCLUDED_)
#define AFX_IFSVIEW_H__D0AD332A_29D2_4AB0_B112_E9101BAAD078__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIFSView : public CView
{
protected: // create from serialization only
	CIFSView();
	DECLARE_DYNCREATE(CIFSView)

// Attributes
public:
	CIFSDoc* GetDocument();
	double x,y;int i,k;
	int MaxY;
 	double  a[8],b[8],c[8],d[8],e[8],f[8],p[8];
	COLORREF	m_pColor;
	int drawtrue;
	int m_N;
	int stepx,stepy;
	int totalsteps;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIFSView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIFSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIFSView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IFSView.cpp
inline CIFSDoc* CIFSView::GetDocument()
   { return (CIFSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFSVIEW_H__D0AD332A_29D2_4AB0_B112_E9101BAAD078__INCLUDED_)
