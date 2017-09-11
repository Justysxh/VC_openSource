// PrintResume.h : main header file for the PRINTRESUME application
//

#if !defined(AFX_PRINTRESUME_H__31F714E2_67A7_410A_9A64_E391504BF0BF__INCLUDED_)
#define AFX_PRINTRESUME_H__31F714E2_67A7_410A_9A64_E391504BF0BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintResumeApp:
// See PrintResume.cpp for the implementation of this class
//

class CPrintResumeApp : public CWinApp
{
public:
	CPrintResumeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintResumeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintResumeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTRESUME_H__31F714E2_67A7_410A_9A64_E391504BF0BF__INCLUDED_)
