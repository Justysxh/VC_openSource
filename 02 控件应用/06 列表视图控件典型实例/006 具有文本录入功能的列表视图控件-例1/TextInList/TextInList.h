// TextInList.h : main header file for the TEXTINLIST application
//

#if !defined(AFX_TEXTINLIST_H__76CDEF9A_8D79_4539_A006_56428C46D1E5__INCLUDED_)
#define AFX_TEXTINLIST_H__76CDEF9A_8D79_4539_A006_56428C46D1E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextInListApp:
// See TextInList.cpp for the implementation of this class
//

class CTextInListApp : public CWinApp
{
public:
	CTextInListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextInListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextInListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTINLIST_H__76CDEF9A_8D79_4539_A006_56428C46D1E5__INCLUDED_)
