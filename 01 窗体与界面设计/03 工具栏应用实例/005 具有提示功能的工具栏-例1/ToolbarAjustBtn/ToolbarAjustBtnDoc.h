// ToolbarAjustBtnDoc.h : interface of the CToolbarAjustBtnDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARAJUSTBTNDOC_H__A56B4F59_C5F5_418C_9E54_D60644E018A7__INCLUDED_)
#define AFX_TOOLBARAJUSTBTNDOC_H__A56B4F59_C5F5_418C_9E54_D60644E018A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolbarAjustBtnDoc : public CDocument
{
protected: // create from serialization only
	CToolbarAjustBtnDoc();
	DECLARE_DYNCREATE(CToolbarAjustBtnDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbarAjustBtnDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolbarAjustBtnDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolbarAjustBtnDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARAJUSTBTNDOC_H__A56B4F59_C5F5_418C_9E54_D60644E018A7__INCLUDED_)
