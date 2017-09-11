// SinusoidDoc.h : interface of the CSinusoidDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINUSOIDDOC_H__0363A513_F6F3_43DA_8651_2A6FC3DEBBD5__INCLUDED_)
#define AFX_SINUSOIDDOC_H__0363A513_F6F3_43DA_8651_2A6FC3DEBBD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinusoidDoc : public CDocument
{
protected: // create from serialization only
	CSinusoidDoc();
	DECLARE_DYNCREATE(CSinusoidDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinusoidDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinusoidDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinusoidDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINUSOIDDOC_H__0363A513_F6F3_43DA_8651_2A6FC3DEBBD5__INCLUDED_)
