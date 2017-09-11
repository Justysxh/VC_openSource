#if !defined(AFX_COLOUREDIT_H__9103B6D3_BB54_4C70_B8ED_685B5F1CB992__INCLUDED_)
#define AFX_COLOUREDIT_H__9103B6D3_BB54_4C70_B8ED_685B5F1CB992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColourEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColourEdit window

class CColourEdit : public CEdit
{
private:
	COLORREF  m_Colour;
// Construction
public:
	CColourEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColourEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetColour(COLORREF Colour);
	virtual ~CColourEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColourEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOUREDIT_H__9103B6D3_BB54_4C70_B8ED_685B5F1CB992__INCLUDED_)
