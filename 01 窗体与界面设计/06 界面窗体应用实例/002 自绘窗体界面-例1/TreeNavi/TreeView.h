#if !defined(AFX_TREEVIEW_H__7B18CAEE_3268_4D7C_A265_DE6386D15865__INCLUDED_)
#define AFX_TREEVIEW_H__7B18CAEE_3268_4D7C_A265_DE6386D15865__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TreeView.h : header file
//
#include "afxcview.h"
/////////////////////////////////////////////////////////////////////////////
// TreeView view

class TreeView : public CTreeView
{
protected:
	TreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(TreeView)

// Attributes
public:

// Operations
public:
		CImageList list;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~TreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(TreeView)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEVIEW_H__7B18CAEE_3268_4D7C_A265_DE6386D15865__INCLUDED_)
