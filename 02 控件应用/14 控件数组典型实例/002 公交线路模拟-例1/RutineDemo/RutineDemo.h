// RutineDemo.h : main header file for the RUTINEDEMO application
//

#if !defined(AFX_RUTINEDEMO_H__D763DCBE_4068_4E1F_8D9C_DF997B083E96__INCLUDED_)
#define AFX_RUTINEDEMO_H__D763DCBE_4068_4E1F_8D9C_DF997B083E96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRutineDemoApp:
// See RutineDemo.cpp for the implementation of this class
//

class CRutineDemoApp : public CWinApp
{
public:
	CRutineDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRutineDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRutineDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RUTINEDEMO_H__D763DCBE_4068_4E1F_8D9C_DF997B083E96__INCLUDED_)
