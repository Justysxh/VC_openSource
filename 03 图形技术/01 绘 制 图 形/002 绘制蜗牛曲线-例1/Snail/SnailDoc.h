// SnailDoc.h : interface of the CSnailDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAILDOC_H__C9C67BA7_03A4_4B90_9EC8_4E8EE98E3EAC__INCLUDED_)
#define AFX_SNAILDOC_H__C9C67BA7_03A4_4B90_9EC8_4E8EE98E3EAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSnailDoc : public CDocument
{
protected: // create from serialization only
	CSnailDoc();
	DECLARE_DYNCREATE(CSnailDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnailDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnailDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnailDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAILDOC_H__C9C67BA7_03A4_4B90_9EC8_4E8EE98E3EAC__INCLUDED_)
