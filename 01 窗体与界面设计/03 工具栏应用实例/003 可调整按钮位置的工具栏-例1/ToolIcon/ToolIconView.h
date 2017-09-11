// ToolIconView.h : interface of the CToolIconView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLICONVIEW_H__8F345BF0_3762_445F_9D86_059B0F8E693F__INCLUDED_)
#define AFX_TOOLICONVIEW_H__8F345BF0_3762_445F_9D86_059B0F8E693F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolIconView : public CView
{
protected: // create from serialization only
	CToolIconView();
	DECLARE_DYNCREATE(CToolIconView)

// Attributes
public:
	CToolIconDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolIconView)
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
	virtual ~CToolIconView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolIconView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolIconView.cpp
inline CToolIconDoc* CToolIconView::GetDocument()
   { return (CToolIconDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLICONVIEW_H__8F345BF0_3762_445F_9D86_059B0F8E693F__INCLUDED_)
