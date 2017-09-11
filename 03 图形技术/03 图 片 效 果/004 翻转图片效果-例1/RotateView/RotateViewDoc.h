// RotateViewDoc.h : interface of the CRotateViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATEVIEWDOC_H__D229FF27_8C71_411F_8980_F76C639DFB47__INCLUDED_)
#define AFX_ROTATEVIEWDOC_H__D229FF27_8C71_411F_8980_F76C639DFB47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRotateViewDoc : public CDocument
{
protected: // create from serialization only
	CRotateViewDoc();
	DECLARE_DYNCREATE(CRotateViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRotateViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRotateViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEVIEWDOC_H__D229FF27_8C71_411F_8980_F76C639DFB47__INCLUDED_)
