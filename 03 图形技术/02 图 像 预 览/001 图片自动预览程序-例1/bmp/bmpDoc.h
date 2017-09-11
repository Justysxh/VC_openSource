// bmpDoc.h : interface of the CBmpDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPDOC_H__54AC8EC0_EFD5_455F_A6BA_72C440F04D9A__INCLUDED_)
#define AFX_BMPDOC_H__54AC8EC0_EFD5_455F_A6BA_72C440F04D9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpDoc : public CDocument
{
protected: // create from serialization only
	CBmpDoc();
	DECLARE_DYNCREATE(CBmpDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	HBITMAP GetHandle() const {return (HBITMAP)m_Bitmap.m_hObject;};
	void SelectOldBitmap(CDC *pDCMem) {pDCMem->SelectObject(m_pOldBitmap);};
	void SelectBitmap(CDC *pDCMem)
		{m_pOldBitmap=pDCMem->SelectObject(&m_Bitmap);};
	int GetBitmap(BITMAP* pBitMap) {return m_Bitmap.GetBitmap(pBitMap);};

protected:
	CBitmap m_Bitmap;
	CBitmap* m_pOldBitmap;
// Generated message map functions
protected:
	//{{AFX_MSG(CBmpDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPDOC_H__54AC8EC0_EFD5_455F_A6BA_72C440F04D9A__INCLUDED_)
