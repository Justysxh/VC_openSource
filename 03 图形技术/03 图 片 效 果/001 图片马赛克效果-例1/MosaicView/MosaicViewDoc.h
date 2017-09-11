// MosaicViewDoc.h : interface of the CMosaicViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOSAICVIEWDOC_H__09000F6A_19B4_46F4_822D_2B009D76F26B__INCLUDED_)
#define AFX_MOSAICVIEWDOC_H__09000F6A_19B4_46F4_822D_2B009D76F26B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMosaicViewDoc : public CDocument
{
protected: // create from serialization only
	CMosaicViewDoc();
	DECLARE_DYNCREATE(CMosaicViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMosaicViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMosaicViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMosaicViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOSAICVIEWDOC_H__09000F6A_19B4_46F4_822D_2B009D76F26B__INCLUDED_)
