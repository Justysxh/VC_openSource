#if !defined(AFX_COLOREDIT_H__DFDA23F7_DEDD_43DA_A0F4_23D02556CC4C__INCLUDED_)
#define AFX_COLOREDIT_H__DFDA23F7_DEDD_43DA_A0F4_23D02556CC4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorEdit window

class CColorEdit : public CEdit
{
// Construction
public:
	CColorEdit();
	COLORREF m_Color;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetColor(COLORREF color);
	virtual ~CColorEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREDIT_H__DFDA23F7_DEDD_43DA_A0F4_23D02556CC4C__INCLUDED_)
