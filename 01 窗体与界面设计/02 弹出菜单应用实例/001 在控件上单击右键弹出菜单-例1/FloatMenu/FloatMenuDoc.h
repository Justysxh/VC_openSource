// FloatMenuDoc.h : interface of the CFloatMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOATMENUDOC_H__33607166_2BF2_4771_B4BA_E6C21EB61B71__INCLUDED_)
#define AFX_FLOATMENUDOC_H__33607166_2BF2_4771_B4BA_E6C21EB61B71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFloatMenuDoc : public CDocument
{
protected: // create from serialization only
	CFloatMenuDoc();
	DECLARE_DYNCREATE(CFloatMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFloatMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFloatMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATMENUDOC_H__33607166_2BF2_4771_B4BA_E6C21EB61B71__INCLUDED_)
