// TreeNaviDoc.h : interface of the CTreeNaviDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREENAVIDOC_H__FFFDB9D3_0C96_4B96_AB41_05615D0865CB__INCLUDED_)
#define AFX_TREENAVIDOC_H__FFFDB9D3_0C96_4B96_AB41_05615D0865CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTreeNaviDoc : public CDocument
{
protected: // create from serialization only
	CTreeNaviDoc();
	DECLARE_DYNCREATE(CTreeNaviDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeNaviDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeNaviDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeNaviDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREENAVIDOC_H__FFFDB9D3_0C96_4B96_AB41_05615D0865CB__INCLUDED_)
