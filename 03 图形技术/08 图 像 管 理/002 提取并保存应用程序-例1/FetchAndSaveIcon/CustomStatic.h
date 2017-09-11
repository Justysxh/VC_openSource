#if !defined(AFX_CUSTOMSTATIC_H__0BDB46D4_C22B_422E_8460_05CB7FDF9E20__INCLUDED_)
#define AFX_CUSTOMSTATIC_H__0BDB46D4_C22B_422E_8460_05CB7FDF9E20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomStatic window

class CCustomStatic : public CStatic
{
// Construction
public:
	CCustomStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomStatic)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomStatic)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMSTATIC_H__0BDB46D4_C22B_422E_8460_05CB7FDF9E20__INCLUDED_)
