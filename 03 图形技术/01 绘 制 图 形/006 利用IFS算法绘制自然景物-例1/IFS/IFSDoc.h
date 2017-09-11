// IFSDoc.h : interface of the CIFSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFSDOC_H__7FCF5E2A_A65D_4EF0_AD1E_F7AC3F9776CD__INCLUDED_)
#define AFX_IFSDOC_H__7FCF5E2A_A65D_4EF0_AD1E_F7AC3F9776CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIFSDoc : public CDocument
{
protected: // create from serialization only
	CIFSDoc();
	DECLARE_DYNCREATE(CIFSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIFSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIFSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIFSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFSDOC_H__7FCF5E2A_A65D_4EF0_AD1E_F7AC3F9776CD__INCLUDED_)
