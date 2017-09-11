// CutImage.h : main header file for the CUTIMAGE application
//

#if !defined(AFX_CUTIMAGE_H__1E01D660_B993_4A63_8291_BCD41F25A7FA__INCLUDED_)
#define AFX_CUTIMAGE_H__1E01D660_B993_4A63_8291_BCD41F25A7FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCutImageApp:
// See CutImage.cpp for the implementation of this class
//

class CCutImageApp : public CWinApp
{
public:
	CCutImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCutImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTIMAGE_H__1E01D660_B993_4A63_8291_BCD41F25A7FA__INCLUDED_)
