// VirtualKey.h : main header file for the VIRTUALKEY application
//

#if !defined(AFX_VIRTUALKEY_H__02653EAF_C124_440B_84D2_0120C2269BFA__INCLUDED_)
#define AFX_VIRTUALKEY_H__02653EAF_C124_440B_84D2_0120C2269BFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVirtualKeyApp:
// See VirtualKey.cpp for the implementation of this class
//

class CVirtualKeyApp : public CWinApp
{
public:
	CVirtualKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVirtualKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALKEY_H__02653EAF_C124_440B_84D2_0120C2269BFA__INCLUDED_)
