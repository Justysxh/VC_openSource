// Dijoy.h : main header file for the DIJOY application
//

#if !defined(AFX_DIJOY_H__4F191FCD_F414_44DF_94A0_DF2CA830E26B__INCLUDED_)
#define AFX_DIJOY_H__4F191FCD_F414_44DF_94A0_DF2CA830E26B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDijoyApp:
// See Dijoy.cpp for the implementation of this class
//

class CDijoyApp : public CWinApp
{
public:
	CDijoyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDijoyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDijoyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIJOY_H__4F191FCD_F414_44DF_94A0_DF2CA830E26B__INCLUDED_)
