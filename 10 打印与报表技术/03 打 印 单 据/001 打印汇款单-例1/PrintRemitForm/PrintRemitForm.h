// PrintRemitForm.h : main header file for the PRINTREMITFORM application
//

#if !defined(AFX_PRINTREMITFORM_H__E018E293_6BC2_4679_ACF5_051E1DCCCA21__INCLUDED_)
#define AFX_PRINTREMITFORM_H__E018E293_6BC2_4679_ACF5_051E1DCCCA21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintRemitFormApp:
// See PrintRemitForm.cpp for the implementation of this class
//

class CPrintRemitFormApp : public CWinApp
{
public:
	CPrintRemitFormApp();



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRemitFormApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintRemitFormApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTREMITFORM_H__E018E293_6BC2_4679_ACF5_051E1DCCCA21__INCLUDED_)
