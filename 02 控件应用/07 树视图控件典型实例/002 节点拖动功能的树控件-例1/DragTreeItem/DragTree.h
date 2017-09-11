#if !defined(AFX_DRAGTREE_H__3015F03F_045E_4531_A436_E2A890F23540__INCLUDED_)
#define AFX_DRAGTREE_H__3015F03F_045E_4531_A436_E2A890F23540__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DragTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDragTree window

class CDragTree : public CTreeCtrl
{
// Construction
public:
	CDragTree();
	
	CImageList*  m_pDragImages;	//拖动的图像列表
	BOOL m_bDrag;				//是否进行拖动
	HTREEITEM  m_hBeginDrag;	//拖动的起点
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	void CopyNodes(HTREEITEM hDesItem, HTREEITEM hSrcItem);
	virtual ~CDragTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDragTree)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGTREE_H__3015F03F_045E_4531_A436_E2A890F23540__INCLUDED_)
