// ToolbarAjustBtnView.h : interface of the CToolbarAjustBtnView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARAJUSTBTNVIEW_H__F4282388_F6F5_44F7_96F1_00E09F00D573__INCLUDED_)
#define AFX_TOOLBARAJUSTBTNVIEW_H__F4282388_F6F5_44F7_96F1_00E09F00D573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolbarAjustBtnView : public CView
{
protected: // create from serialization only
	CToolbarAjustBtnView();
	DECLARE_DYNCREATE(CToolbarAjustBtnView)

// Attributes
public:
	CToolbarAjustBtnDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarAjustBtnView)
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
	virtual ~CToolbarAjustBtnView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolbarAjustBtnView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolbarAjustBtnView.cpp
inline CToolbarAjustBtnDoc* CToolbarAjustBtnView::GetDocument()
   { return (CToolbarAjustBtnDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARAJUSTBTNVIEW_H__F4282388_F6F5_44F7_96F1_00E09F00D573__INCLUDED_)
