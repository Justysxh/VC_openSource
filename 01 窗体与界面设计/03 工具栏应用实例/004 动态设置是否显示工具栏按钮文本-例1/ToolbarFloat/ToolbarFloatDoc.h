// ToolbarFloatDoc.h : interface of the CToolbarFloatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARFLOATDOC_H__21A7253F_4F41_4200_B84D_70593C5F1F97__INCLUDED_)
#define AFX_TOOLBARFLOATDOC_H__21A7253F_4F41_4200_B84D_70593C5F1F97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolbarFloatDoc : public CDocument
{
protected: // create from serialization only
	CToolbarFloatDoc();
	DECLARE_DYNCREATE(CToolbarFloatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarFloatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolbarFloatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolbarFloatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARFLOATDOC_H__21A7253F_4F41_4200_B84D_70593C5F1F97__INCLUDED_)
