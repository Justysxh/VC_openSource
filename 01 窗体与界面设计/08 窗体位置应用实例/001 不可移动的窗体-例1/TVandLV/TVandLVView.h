// TVandLVView.h : interface of the CTVandLVView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TVANDLVVIEW_H__81313E0B_E848_431F_B784_37089DF4E402__INCLUDED_)
#define AFX_TVANDLVVIEW_H__81313E0B_E848_431F_B784_37089DF4E402__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTVandLVView : public CView
{
protected: // create from serialization only
	CTVandLVView();
	DECLARE_DYNCREATE(CTVandLVView)

// Attributes
public:
	CTVandLVDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTVandLVView)
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
	virtual ~CTVandLVView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTVandLVView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TVandLVView.cpp
inline CTVandLVDoc* CTVandLVView::GetDocument()
   { return (CTVandLVDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TVANDLVVIEW_H__81313E0B_E848_431F_B784_37089DF4E402__INCLUDED_)
