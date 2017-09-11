// TVandLVDoc.h : interface of the CTVandLVDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TVANDLVDOC_H__E3E76D67_6868_4F51_8AA0_7901776EE3D4__INCLUDED_)
#define AFX_TVANDLVDOC_H__E3E76D67_6868_4F51_8AA0_7901776EE3D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTVandLVDoc : public CDocument
{
protected: // create from serialization only
	CTVandLVDoc();
	DECLARE_DYNCREATE(CTVandLVDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTVandLVDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTVandLVDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTVandLVDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TVANDLVDOC_H__E3E76D67_6868_4F51_8AA0_7901776EE3D4__INCLUDED_)
