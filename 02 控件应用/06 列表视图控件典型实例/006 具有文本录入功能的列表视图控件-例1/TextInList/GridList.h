#if !defined(AFX_GRIDLIST_H__19BFD941_2C8D_47A1_9D5D_1BC794AE10F6__INCLUDED_)
#define AFX_GRIDLIST_H__19BFD941_2C8D_47A1_9D5D_1BC794AE10F6__INCLUDED_
#include "ListEdit.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GridList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGridList window

class CGridList : public CListCtrl
{
// Construction
public:
	CGridList();

	CListEdit edit;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGridList)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL DisposeEdit();
	int row,col;
	void ShowEdit();
	virtual ~CGridList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGridList)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRIDLIST_H__19BFD941_2C8D_47A1_9D5D_1BC794AE10F6__INCLUDED_)
