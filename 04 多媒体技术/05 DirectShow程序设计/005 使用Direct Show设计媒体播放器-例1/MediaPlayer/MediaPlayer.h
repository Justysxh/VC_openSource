// MediaPlayer.h : main header file for the MEDIAPLAYER application
//

#if !defined(AFX_MEDIAPLAYER_H__DD28B937_EB9B_488B_A312_D09C4143D902__INCLUDED_)
#define AFX_MEDIAPLAYER_H__DD28B937_EB9B_488B_A312_D09C4143D902__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerApp:
// See MediaPlayer.cpp for the implementation of this class
//

class CMediaPlayerApp : public CWinApp
{
public:
	CMediaPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMediaPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYER_H__DD28B937_EB9B_488B_A312_D09C4143D902__INCLUDED_)
