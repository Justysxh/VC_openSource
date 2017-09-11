// duotjpx.h : main header file for the DUOTJPX application
//

#if !defined(AFX_DUOTJPX_H__D30C7726_4E57_464E_9009_B276A5AE3107__INCLUDED_)
#define AFX_DUOTJPX_H__D30C7726_4E57_464E_9009_B276A5AE3107__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDuotjpxApp:
// See duotjpx.cpp for the implementation of this class
//

class CDuotjpxApp : public CWinApp
{
public:
	CDuotjpxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDuotjpxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDuotjpxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUOTJPX_H__D30C7726_4E57_464E_9009_B276A5AE3107__INCLUDED_)
