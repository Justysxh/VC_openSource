// EditToolDoc.h : interface of the CEditToolDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITTOOLDOC_H__6CAE9A35_2308_4B3C_A36B_A4C2EC3984BB__INCLUDED_)
#define AFX_EDITTOOLDOC_H__6CAE9A35_2308_4B3C_A36B_A4C2EC3984BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEditToolDoc : public CDocument
{
protected: // create from serialization only
	CEditToolDoc();
	DECLARE_DYNCREATE(CEditToolDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditToolDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEditToolDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITTOOLDOC_H__6CAE9A35_2308_4B3C_A36B_A4C2EC3984BB__INCLUDED_)
