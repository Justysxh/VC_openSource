// CTdrawView.h : interface of the CCTdrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTDRAWVIEW_H__5D6DE2F9_07A8_4210_82F3_05A742AA06E0__INCLUDED_)
#define AFX_CTDRAWVIEW_H__5D6DE2F9_07A8_4210_82F3_05A742AA06E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTdrawView : public CView
{
protected: // create from serialization only
	CCTdrawView();
	DECLARE_DYNCREATE(CCTdrawView)

// Attributes
public:
	CCTdrawDoc* GetDocument();
	void ResetAllFlags();
	bool m_draw;
	bool m_yuan;
	bool m_juxing;
	CPoint m_start;
	CPoint m_end;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTdrawView)
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
	virtual ~CCTdrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTdrawView)
	afx_msg void OnMenudraw();
	afx_msg void OnUpdateMenudraw(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenujuxing();
	afx_msg void OnMenuyuan();
	afx_msg void OnUpdateMenujuxing(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuyuan(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CTdrawView.cpp
inline CCTdrawDoc* CCTdrawView::GetDocument()
   { return (CCTdrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTDRAWVIEW_H__5D6DE2F9_07A8_4210_82F3_05A742AA06E0__INCLUDED_)
