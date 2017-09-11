#if !defined(AFX_MYCOMBOBOX_H__8B2D6701_5BD6_4ABF_A076_F37706535D01__INCLUDED_)
#define AFX_MYCOMBOBOX_H__8B2D6701_5BD6_4ABF_A076_F37706535D01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyComboBox window

class MyComboBox : public CComboBox
{
// Construction
public:
	MyComboBox();
void init();
int AddString(LPCTSTR lpszString);
int	AddItem(CString strItem,int nCol,int nRow,
		int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM,
		int nFmt = LVCFMT_LEFT);
// Attributes
public:
	UINT totalcol;
	CStringList* ItemList;
	CString item[512];
	CStringList litem[5];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyComboBox)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(MyComboBox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMBOBOX_H__8B2D6701_5BD6_4ABF_A076_F37706535D01__INCLUDED_)
