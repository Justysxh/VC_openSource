// GifPlayer.h : main header file for the GIFPLAYER application
//

#if !defined(AFX_GIFPLAYER_H__758FA66A_25B6_475D_8088_24B74B9EC449__INCLUDED_)
#define AFX_GIFPLAYER_H__758FA66A_25B6_475D_8088_24B74B9EC449__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGifPlayerApp:
// See GifPlayer.cpp for the implementation of this class
//

class CGifPlayerApp : public CWinApp
{
public:
	CGifPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGifPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGifPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GIFPLAYER_H__758FA66A_25B6_475D_8088_24B74B9EC449__INCLUDED_)
