#if !defined(AFX_BITTREECTL_H__BFA4307D_EA6E_459E_94DA_60905BFF738D__INCLUDED_)
#define AFX_BITTREECTL_H__BFA4307D_EA6E_459E_94DA_60905BFF738D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitTreeCtl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitTreeCtl window

class CBitTreeCtl : public CTreeCtrl
{
// Construction
public:
	CBitTreeCtl();
	UINT m_Flags;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitTreeCtl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void RansackParentAndChild(HTREEITEM hItem,UINT State);

	void RansackChild(HTREEITEM hItem,UINT State);
	BOOL SetItemState(HTREEITEM hItem, UINT State, UINT StateMask, BOOL IsSearch=TRUE);
	virtual ~CBitTreeCtl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBitTreeCtl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITTREECTL_H__BFA4307D_EA6E_459E_94DA_60905BFF738D__INCLUDED_)
