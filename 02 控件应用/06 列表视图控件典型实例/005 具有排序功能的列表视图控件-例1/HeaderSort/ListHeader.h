#if !defined(AFX_LISTHEADER_H__0D2411C6_A5E3_40CF_9EE5_2BCA5BF30EF9__INCLUDED_)
#define AFX_LISTHEADER_H__0D2411C6_A5E3_40CF_9EE5_2BCA5BF30EF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListHeader.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListHeader window

class CListHeader : public CHeaderCtrl
{
// Construction
public:
	CListHeader();
	int		m_nSortColumn;	//ÅÅÐòÁÐ
	BOOL	m_bAscend;		//ÊÇ·ñÎªÉýÐò
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListHeader)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void SetSortColomn(int nColumn,BOOL bAscend);
	virtual ~CListHeader();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListHeader)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTHEADER_H__0D2411C6_A5E3_40CF_9EE5_2BCA5BF30EF9__INCLUDED_)
