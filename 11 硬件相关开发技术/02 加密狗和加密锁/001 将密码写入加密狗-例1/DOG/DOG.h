// DOG.h : main header file for the DOG application
//

#if !defined(AFX_DOG_H__EC230F0A_19D9_4559_B942_668F0531EF94__INCLUDED_)
#define AFX_DOG_H__EC230F0A_19D9_4559_B942_668F0531EF94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDOGApp:
// See DOG.cpp for the implementation of this class
//

class CDOGApp : public CWinApp
{
public:
	CDOGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDOGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDOGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOG_H__EC230F0A_19D9_4559_B942_668F0531EF94__INCLUDED_)
