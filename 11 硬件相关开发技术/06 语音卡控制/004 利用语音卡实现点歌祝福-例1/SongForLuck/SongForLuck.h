// SongForLuck.h : main header file for the SONGFORLUCK application
//

#if !defined(AFX_SONGFORLUCK_H__2D3E771E_E091_4820_B506_7ECFB138814D__INCLUDED_)
#define AFX_SONGFORLUCK_H__2D3E771E_E091_4820_B506_7ECFB138814D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSongForLuckApp:
// See SongForLuck.cpp for the implementation of this class
//

class CSongForLuckApp : public CWinApp
{
public:
	CSongForLuckApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSongForLuckApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSongForLuckApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SONGFORLUCK_H__2D3E771E_E091_4820_B506_7ECFB138814D__INCLUDED_)
