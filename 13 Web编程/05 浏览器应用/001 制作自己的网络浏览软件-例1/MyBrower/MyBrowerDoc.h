// MyBrowerDoc.h : interface of the CMyBrowerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBROWERDOC_H__EA7193EF_8F81_4E90_8721_AC73FE9E12ED__INCLUDED_)
#define AFX_MYBROWERDOC_H__EA7193EF_8F81_4E90_8721_AC73FE9E12ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyBrowerDoc : public CDocument
{
protected: // create from serialization only
	CMyBrowerDoc();
	DECLARE_DYNCREATE(CMyBrowerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyBrowerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyBrowerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyBrowerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBROWERDOC_H__EA7193EF_8F81_4E90_8721_AC73FE9E12ED__INCLUDED_)
