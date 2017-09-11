// Catface.h : main header file for the CATFACE application
//

#if !defined(AFX_CATFACE_H__BEBBF7AB_C5C7_4521_B14D_C06483C99CFB__INCLUDED_)
#define AFX_CATFACE_H__BEBBF7AB_C5C7_4521_B14D_C06483C99CFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCatfaceApp:
// See Catface.cpp for the implementation of this class
//

class CCatfaceApp : public CWinApp
{
public:
	CCatfaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatfaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCatfaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATFACE_H__BEBBF7AB_C5C7_4521_B14D_C06483C99CFB__INCLUDED_)
