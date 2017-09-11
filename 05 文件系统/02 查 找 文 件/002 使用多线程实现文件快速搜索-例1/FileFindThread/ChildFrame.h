#if !defined(AFX_CHILDFRAME_H__65E9C74A_E96F_4766_AAD5_3A41028A3BA1__INCLUDED_)
#define AFX_CHILDFRAME_H__65E9C74A_E96F_4766_AAD5_3A41028A3BA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChildFrame form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CChildFrame : public CFormView
{
protected:
	CChildFrame();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CChildFrame)

// Form Data
public:
	//{{AFX_DATA(CChildFrame)
	enum { IDD = IDD_ChildFrame };
	CListCtrl	m_list;
	CEdit	m_edit;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CChildFrame)
	afx_msg void OnFindFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRAME_H__65E9C74A_E96F_4766_AAD5_3A41028A3BA1__INCLUDED_)
