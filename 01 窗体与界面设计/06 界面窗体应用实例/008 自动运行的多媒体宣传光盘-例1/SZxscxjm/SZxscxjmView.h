// SZxscxjmView.h : interface of the CSZxscxjmView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SZXSCXJMVIEW_H__08896415_E761_407C_912A_A4E0313C4538__INCLUDED_)
#define AFX_SZXSCXJMVIEW_H__08896415_E761_407C_912A_A4E0313C4538__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSZxscxjmView : public CView
{
protected: // create from serialization only
	CSZxscxjmView();
	DECLARE_DYNCREATE(CSZxscxjmView)

// Attributes
public:
	CSZxscxjmDoc* GetDocument();
	CTime time;
	int hour,min,sec;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSZxscxjmView)
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
	virtual ~CSZxscxjmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSZxscxjmView)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SZxscxjmView.cpp
inline CSZxscxjmDoc* CSZxscxjmView::GetDocument()
   { return (CSZxscxjmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SZXSCXJMVIEW_H__08896415_E761_407C_912A_A4E0313C4538__INCLUDED_)
