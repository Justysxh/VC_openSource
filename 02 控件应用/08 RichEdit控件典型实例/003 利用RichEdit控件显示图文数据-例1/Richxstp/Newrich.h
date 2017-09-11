#if !defined(AFX_NEWRICH_H__D22654AE_9114_4DF1_A6DC_CAC666EBB863__INCLUDED_)
#define AFX_NEWRICH_H__D22654AE_9114_4DF1_A6DC_CAC666EBB863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Newrich.h : header file
//
struct stFace;
/////////////////////////////////////////////////////////////////////////////
// CNewrich window

class CNewrich : public CRichEditCtrl
{
// Construction
public:
	CNewrich();
	void CNewrich::InsertBitmap(CString *pBmpFile);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewrich)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewrich();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNewrich)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWRICH_H__D22654AE_9114_4DF1_A6DC_CAC666EBB863__INCLUDED_)
