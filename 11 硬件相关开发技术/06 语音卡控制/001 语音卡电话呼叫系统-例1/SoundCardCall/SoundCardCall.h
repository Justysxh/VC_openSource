// SoundCardCall.h : main header file for the SOUNDCARDCALL application
//

#if !defined(AFX_SOUNDCARDCALL_H__1D00AF56_3B53_4EC8_84E0_B0B420B6613A__INCLUDED_)
#define AFX_SOUNDCARDCALL_H__1D00AF56_3B53_4EC8_84E0_B0B420B6613A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSoundCardCallApp:
// See SoundCardCall.cpp for the implementation of this class
//

class CSoundCardCallApp : public CWinApp
{
public:
	CSoundCardCallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundCardCallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSoundCardCallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDCARDCALL_H__1D00AF56_3B53_4EC8_84E0_B0B420B6613A__INCLUDED_)
