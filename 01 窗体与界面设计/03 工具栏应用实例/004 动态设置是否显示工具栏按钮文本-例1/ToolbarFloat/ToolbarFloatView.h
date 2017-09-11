// ToolbarFloatView.h : interface of the CToolbarFloatView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARFLOATVIEW_H__65613217_750E_4FEA_9A71_AE58A8D029B8__INCLUDED_)
#define AFX_TOOLBARFLOATVIEW_H__65613217_750E_4FEA_9A71_AE58A8D029B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolbarFloatView : public CView
{
protected: // create from serialization only
	CToolbarFloatView();
	DECLARE_DYNCREATE(CToolbarFloatView)

// Attributes
public:
	CToolbarFloatDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarFloatView)
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
	virtual ~CToolbarFloatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolbarFloatView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolbarFloatView.cpp
inline CToolbarFloatDoc* CToolbarFloatView::GetDocument()
   { return (CToolbarFloatDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARFLOATVIEW_H__65613217_750E_4FEA_9A71_AE58A8D029B8__INCLUDED_)
