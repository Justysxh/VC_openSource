#if !defined(AFX_BUTTONAVI_H__CAE2F5FC_D7DD_4D4C_AF1D_1FC47CDAD317__INCLUDED_)
#define AFX_BUTTONAVI_H__CAE2F5FC_D7DD_4D4C_AF1D_1FC47CDAD317__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonAvi.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CButtonAvi window

class CButtonAvi : public CButton
{
// Construction
public:
	CButtonAvi();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonAvi)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawButton(CDC* pDC,UINT nState,CRect rect);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDraw);
	void LoadAVI(UINT nID);
	CAnimateCtrl m_Animate;
	BOOL m_play;
	int m_id;
	virtual ~CButtonAvi();

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonAvi)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONAVI_H__CAE2F5FC_D7DD_4D4C_AF1D_1FC47CDAD317__INCLUDED_)
