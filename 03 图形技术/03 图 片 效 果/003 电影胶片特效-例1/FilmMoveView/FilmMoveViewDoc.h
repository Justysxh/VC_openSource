// FilmMoveViewDoc.h : interface of the CFilmMoveViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILMMOVEVIEWDOC_H__CC2C1DCB_60DC_484F_8F0E_A2C3664EC731__INCLUDED_)
#define AFX_FILMMOVEVIEWDOC_H__CC2C1DCB_60DC_484F_8F0E_A2C3664EC731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFilmMoveViewDoc : public CDocument
{
protected: // create from serialization only
	CFilmMoveViewDoc();
	DECLARE_DYNCREATE(CFilmMoveViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilmMoveViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFilmMoveViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFilmMoveViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILMMOVEVIEWDOC_H__CC2C1DCB_60DC_484F_8F0E_A2C3664EC731__INCLUDED_)
