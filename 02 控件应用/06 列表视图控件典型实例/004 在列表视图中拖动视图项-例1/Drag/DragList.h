#if !defined(AFX_DRAGLIST_H__5AE865A8_718C_4420_A8D9_3459668D9750__INCLUDED_)
#define AFX_DRAGLIST_H__5AE865A8_718C_4420_A8D9_3459668D9750__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DragList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDragList window

class CDragList : public CListCtrl
{
// Construction
public:
	CDragList();
	int			m_ItmIndex;
	CImageList*	m_pDrgImg;
	BOOL		m_Drag;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDragList)
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGLIST_H__5AE865A8_718C_4420_A8D9_3459668D9750__INCLUDED_)
