// FetchVisual.h : main header file for the FETCHVISUAL application
//

#if !defined(AFX_FETCHVISUAL_H__038E4E33_2F01_4D6D_A410_633C8DBEA423__INCLUDED_)
#define AFX_FETCHVISUAL_H__038E4E33_2F01_4D6D_A410_633C8DBEA423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFetchVisualApp:
// See FetchVisual.cpp for the implementation of this class
//

class CFetchVisualApp : public CWinApp
{
public:
	CFetchVisualApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFetchVisualApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFetchVisualApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FETCHVISUAL_H__038E4E33_2F01_4D6D_A410_633C8DBEA423__INCLUDED_)
