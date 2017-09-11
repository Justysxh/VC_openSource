// CTdrawDoc.h : interface of the CCTdrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTDRAWDOC_H__9D1E4CA7_2159_4088_BCF6_5707F4355D54__INCLUDED_)
#define AFX_CTDRAWDOC_H__9D1E4CA7_2159_4088_BCF6_5707F4355D54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTdrawDoc : public CDocument
{
protected: // create from serialization only
	CCTdrawDoc();
	DECLARE_DYNCREATE(CCTdrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTdrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCTdrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTdrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTDRAWDOC_H__9D1E4CA7_2159_4088_BCF6_5707F4355D54__INCLUDED_)
