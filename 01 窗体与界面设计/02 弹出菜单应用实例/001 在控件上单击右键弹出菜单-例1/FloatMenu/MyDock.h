#if !defined(AFX_MYDOCK_H__C12FAAF0_46DD_4CE9_83F9_8B1DC42A7224__INCLUDED_)
#define AFX_MYDOCK_H__C12FAAF0_46DD_4CE9_83F9_8B1DC42A7224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDock window

class CMyDock : public CDialogBar
{
// Construction
public:
	CMyDock();
	enum { IDD = IDD_DIALOG1};
	CMenu* m_pMenu;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDock)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetMenu();
	virtual ~CMyDock();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyDock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDOCK_H__C12FAAF0_46DD_4CE9_83F9_8B1DC42A7224__INCLUDED_)
