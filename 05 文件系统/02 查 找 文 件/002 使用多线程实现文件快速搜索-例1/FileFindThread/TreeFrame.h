#if !defined(AFX_TREEFRAME_H__9861DE33_6129_4F33_A185_888DC43B1D20__INCLUDED_)
#define AFX_TREEFRAME_H__9861DE33_6129_4F33_A185_888DC43B1D20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TreeFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTreeFrame view
#include <afxcview.h>

class CTreeFrame : public CTreeView
{	
protected:
	CTreeFrame();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTreeFrame)
private:
	HTREEITEM TreeItemRoot;
protected:
	void InitTree();
	void GetLogicalDrives(HTREEITEM hParent);
	void AddSubDirectory( HTREEITEM hParent,BOOL All = true);
	CString GetFullPath( HTREEITEM hItem);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeFrame)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTreeFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTreeFrame)
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEFRAME_H__9861DE33_6129_4F33_A185_888DC43B1D20__INCLUDED_)
