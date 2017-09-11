// AVIButton.h : main header file for the AVIBUTTON application
//

#if !defined(AFX_AVIBUTTON_H__FB9F4791_E52B_4297_91C8_206A9F7168F6__INCLUDED_)
#define AFX_AVIBUTTON_H__FB9F4791_E52B_4297_91C8_206A9F7168F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAVIButtonApp:
// See AVIButton.cpp for the implementation of this class
//

class CAVIButtonApp : public CWinApp
{
public:
	CAVIButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVIButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAVIButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIBUTTON_H__FB9F4791_E52B_4297_91C8_206A9F7168F6__INCLUDED_)
