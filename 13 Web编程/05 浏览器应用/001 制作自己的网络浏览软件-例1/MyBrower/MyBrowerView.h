// MyBrowerView.h : interface of the CMyBrowerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBROWERVIEW_H__41DD8E9F_150E_400E_9E74_88F7C9D378EA__INCLUDED_)
#define AFX_MYBROWERVIEW_H__41DD8E9F_150E_400E_9E74_88F7C9D378EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyBrowerView : public CHtmlView
{
protected: // create from serialization only
	CMyBrowerView();
	DECLARE_DYNCREATE(CMyBrowerView)

// Attributes
public:
	CMyBrowerDoc* GetDocument();
	CString strsite;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyBrowerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyBrowerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyBrowerView)
	afx_msg void OnButtonsite();
	afx_msg void OnButtonback();
	afx_msg void OnButtonfroward();
	afx_msg void OnButtonstop();
	afx_msg void OnButtonrefresh();
	afx_msg void OnChangeEdaddress();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyBrowerView.cpp
inline CMyBrowerDoc* CMyBrowerView::GetDocument()
   { return (CMyBrowerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBROWERVIEW_H__41DD8E9F_150E_400E_9E74_88F7C9D378EA__INCLUDED_)
