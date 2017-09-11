#if !defined(AFX_LISTHEADERCTRL_H__588AE827_C422_445B_ACA1_B7EA5D7A10EE__INCLUDED_)
#define AFX_LISTHEADERCTRL_H__588AE827_C422_445B_ACA1_B7EA5D7A10EE__INCLUDED_
#include "ListHeader.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListHeaderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListHeaderCtrl window

class CListHeaderCtrl : public CListCtrl
{
// Construction
public:
	CListHeaderCtrl();
	CListHeader		m_ctlHeader;				//列头
	int				m_nNumColumns;				//列数
	int				m_nSortColumn;				//排序列
	BOOL			m_bAscend;					//是否升序排列
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListHeaderCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetColumnNum(int num);
	BOOL SetItemDataList(int iItem, LPTSTR *pchTexts);
	int AddItem( LPCTSTR pszText, ... );
	static int CALLBACK SortFunction( LPARAM lParam1, LPARAM lParam2, LPARAM lParamData );
	void Sort(int iColumn, BOOL bAscending);
	virtual ~CListHeaderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListHeaderCtrl)
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTHEADERCTRL_H__588AE827_C422_445B_ACA1_B7EA5D7A10EE__INCLUDED_)
