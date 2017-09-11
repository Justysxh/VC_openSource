#if !defined(AFX_COLORCOMBOX_H__C83A6741_0950_41B1_90A7_10E666D45621__INCLUDED_)
#define AFX_COLORCOMBOX_H__C83A6741_0950_41B1_90A7_10E666D45621__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorCombox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorCombox window

class CColorCombox : public CComboBox
{
// Construction
public:
	CColorCombox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorCombox)
	public:
	
	protected:
	//}}AFX_VIRTUAL

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
// Implementation
public:
	COLORREF GetCurColor();
	int AddItem(LPCTSTR lpszText, COLORREF clrValue);
	virtual ~CColorCombox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorCombox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORCOMBOX_H__C83A6741_0950_41B1_90A7_10E666D45621__INCLUDED_)
