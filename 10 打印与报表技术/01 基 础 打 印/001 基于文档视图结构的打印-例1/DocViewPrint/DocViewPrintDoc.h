// DocViewPrintDoc.h : interface of the CDocViewPrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCVIEWPRINTDOC_H__870BFC52_8C68_430A_9CEF_E1B1491C6E79__INCLUDED_)
#define AFX_DOCVIEWPRINTDOC_H__870BFC52_8C68_430A_9CEF_E1B1491C6E79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDocViewPrintDoc : public CDocument
{
protected: // create from serialization only
	CDocViewPrintDoc();
	DECLARE_DYNCREATE(CDocViewPrintDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocViewPrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDocViewPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDocViewPrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCVIEWPRINTDOC_H__870BFC52_8C68_430A_9CEF_E1B1491C6E79__INCLUDED_)
