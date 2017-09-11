// MovieMouse.h : main header file for the MOVIEMOUSE application
//

#if !defined(AFX_MOVIEMOUSE_H__CCA77836_3152_4161_968C_4E6FBA0B52D6__INCLUDED_)
#define AFX_MOVIEMOUSE_H__CCA77836_3152_4161_968C_4E6FBA0B52D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMovieMouseApp:
// See MovieMouse.cpp for the implementation of this class
//

class CMovieMouseApp : public CWinApp
{
public:
	CMovieMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovieMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMovieMouseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVIEMOUSE_H__CCA77836_3152_4161_968C_4E6FBA0B52D6__INCLUDED_)
