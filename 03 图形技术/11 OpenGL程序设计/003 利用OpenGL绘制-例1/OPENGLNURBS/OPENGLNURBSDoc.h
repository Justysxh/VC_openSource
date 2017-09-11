// OPENGLNURBSDoc.h : interface of the COPENGLNURBSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLNURBSDOC_H__BB666C77_624B_4116_A86F_FE4285CA338C__INCLUDED_)
#define AFX_OPENGLNURBSDOC_H__BB666C77_624B_4116_A86F_FE4285CA338C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COPENGLNURBSDoc : public CDocument
{
protected: // create from serialization only
	COPENGLNURBSDoc();
	DECLARE_DYNCREATE(COPENGLNURBSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLNURBSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COPENGLNURBSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLNURBSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLNURBSDOC_H__BB666C77_624B_4116_A86F_FE4285CA338C__INCLUDED_)
