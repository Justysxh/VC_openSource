// FileInCallback.h : main header file for the FILEINCALLBACK application
//

#if !defined(AFX_FILEINCALLBACK_H__3E4D8BDF_C40C_4E5A_9846_A4EAE9B3F541__INCLUDED_)
#define AFX_FILEINCALLBACK_H__3E4D8BDF_C40C_4E5A_9846_A4EAE9B3F541__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileInCallbackApp:
// See FileInCallback.cpp for the implementation of this class
//

class CFileInCallbackApp : public CWinApp
{
public:
	CFileInCallbackApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileInCallbackApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileInCallbackApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEINCALLBACK_H__3E4D8BDF_C40C_4E5A_9846_A4EAE9B3F541__INCLUDED_)
