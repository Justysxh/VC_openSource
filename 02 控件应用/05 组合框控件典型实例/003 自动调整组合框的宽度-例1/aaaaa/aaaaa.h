// aaaaa.h : main header file for the AAAAA application
//

#if !defined(AFX_AAAAA_H__C699D9F1_851B_40AA_A4E6_24079C906F7B__INCLUDED_)
#define AFX_AAAAA_H__C699D9F1_851B_40AA_A4E6_24079C906F7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAaaaaApp:
// See aaaaa.cpp for the implementation of this class
//

class CAaaaaApp : public CWinApp
{
public:
	CAaaaaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaaaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAaaaaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAAAA_H__C699D9F1_851B_40AA_A4E6_24079C906F7B__INCLUDED_)
