// bmpView.h : interface of the CBmpView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPVIEW_H__F18A048A_E376_495F_A829_AE35F45ECB42__INCLUDED_)
#define AFX_BMPVIEW_H__F18A048A_E376_495F_A829_AE35F45ECB42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpView : public CView
{
protected: // create from serialization only
	CBmpView();
	DECLARE_DYNCREATE(CBmpView)

// Attributes
public:
	CBmpDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpView)
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
	char buffer[1000];
	CString Search(CString curstr);
	virtual ~CBmpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpView)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in bmpView.cpp
inline CBmpDoc* CBmpView::GetDocument()
   { return (CBmpDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPVIEW_H__F18A048A_E376_495F_A829_AE35F45ECB42__INCLUDED_)
