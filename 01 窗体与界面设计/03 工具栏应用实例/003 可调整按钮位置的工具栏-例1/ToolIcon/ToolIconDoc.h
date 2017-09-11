// ToolIconDoc.h : interface of the CToolIconDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLICONDOC_H__5D50CB38_95CD_4A34_B7CE_68A2B1907FBB__INCLUDED_)
#define AFX_TOOLICONDOC_H__5D50CB38_95CD_4A34_B7CE_68A2B1907FBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolIconDoc : public CDocument
{
protected: // create from serialization only
	CToolIconDoc();
	DECLARE_DYNCREATE(CToolIconDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolIconDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolIconDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolIconDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLICONDOC_H__5D50CB38_95CD_4A34_B7CE_68A2B1907FBB__INCLUDED_)
