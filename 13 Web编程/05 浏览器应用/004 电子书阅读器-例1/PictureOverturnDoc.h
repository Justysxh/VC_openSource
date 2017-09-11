// PictureOverturnDoc.h : interface of the CPictureOverturnDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTUREOVERTURNDOC_H__D06B3783_D635_4532_B09A_9CA60E45D250__INCLUDED_)
#define AFX_PICTUREOVERTURNDOC_H__D06B3783_D635_4532_B09A_9CA60E45D250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPictureOverturnDoc : public CDocument
{
protected: // create from serialization only
	CPictureOverturnDoc();
	DECLARE_DYNCREATE(CPictureOverturnDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureOverturnDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPictureOverturnDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPictureOverturnDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREOVERTURNDOC_H__D06B3783_D635_4532_B09A_9CA60E45D250__INCLUDED_)
