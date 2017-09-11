// FingerIdentify.h : main header file for the FINGERIDENTIFY application
//

#if !defined(AFX_FINGERIDENTIFY_H__144C192C_36B8_4EA9_8DF8_C558A8D61F26__INCLUDED_)
#define AFX_FINGERIDENTIFY_H__144C192C_36B8_4EA9_8DF8_C558A8D61F26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFingerIdentifyApp:
// See FingerIdentify.cpp for the implementation of this class
//

class CFingerIdentifyApp : public CWinApp
{
public:
	CFingerIdentifyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFingerIdentifyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFingerIdentifyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINGERIDENTIFY_H__144C192C_36B8_4EA9_8DF8_C558A8D61F26__INCLUDED_)
