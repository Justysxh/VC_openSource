// HeaderSort.h : main header file for the HEADERSORT application
//

#if !defined(AFX_HEADERSORT_H__45D1BE0C_B4D0_45AF_83A5_91248FED9CD7__INCLUDED_)
#define AFX_HEADERSORT_H__45D1BE0C_B4D0_45AF_83A5_91248FED9CD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHeaderSortApp:
// See HeaderSort.cpp for the implementation of this class
//

class CHeaderSortApp : public CWinApp
{
public:
	CHeaderSortApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHeaderSortApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHeaderSortApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEADERSORT_H__45D1BE0C_B4D0_45AF_83A5_91248FED9CD7__INCLUDED_)
