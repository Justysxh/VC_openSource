#if !defined(AFX_NETTABCTRL_H__22524779_B84E_45F5_8D02_7BD8EFE6820D__INCLUDED_)
#define AFX_NETTABCTRL_H__22524779_B84E_45F5_8D02_7BD8EFE6820D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NetTabCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNetTabCtrl window

class CNetTabCtrl : public CTabCtrl
{
// Construction
public:
	CNetTabCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetTabCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawItemFrame(DRAWITEMSTRUCT* lpDrawItem);
	void DrawTabBorder(CDC* pDC, CRect &TabRC);
	virtual ~CNetTabCtrl();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	// Generated message map functions
protected:
	//{{AFX_MSG(CNetTabCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETTABCTRL_H__22524779_B84E_45F5_8D02_7BD8EFE6820D__INCLUDED_)
