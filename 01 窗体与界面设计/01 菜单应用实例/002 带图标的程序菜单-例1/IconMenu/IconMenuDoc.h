// IconMenuDoc.h : interface of the CIconMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONMENUDOC_H__462A6186_F17E_467F_A5FA_0F61AB618D5F__INCLUDED_)
#define AFX_ICONMENUDOC_H__462A6186_F17E_467F_A5FA_0F61AB618D5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIconMenuDoc : public CDocument
{
protected: // create from serialization only
	CIconMenuDoc();
	DECLARE_DYNCREATE(CIconMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIconMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONMENUDOC_H__462A6186_F17E_467F_A5FA_0F61AB618D5F__INCLUDED_)
