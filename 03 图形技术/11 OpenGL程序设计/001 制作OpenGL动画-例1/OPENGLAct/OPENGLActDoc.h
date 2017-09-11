// OPENGLActDoc.h : interface of the COPENGLActDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLACTDOC_H__A8A971A1_3B91_435C_B6F2_E089CB08466A__INCLUDED_)
#define AFX_OPENGLACTDOC_H__A8A971A1_3B91_435C_B6F2_E089CB08466A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COPENGLActDoc : public CDocument
{
protected: // create from serialization only
	COPENGLActDoc();
	DECLARE_DYNCREATE(COPENGLActDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLActDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COPENGLActDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLActDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLACTDOC_H__A8A971A1_3B91_435C_B6F2_E089CB08466A__INCLUDED_)
