// ReadCard.h : main header file for the READCARD application
//

#if !defined(AFX_READCARD_H__0531B6DA_7EAF_4472_84E5_9C0460312308__INCLUDED_)
#define AFX_READCARD_H__0531B6DA_7EAF_4472_84E5_9C0460312308__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadCardApp:
// See ReadCard.cpp for the implementation of this class
//

class CReadCardApp : public CWinApp
{
public:
	CReadCardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadCardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadCardApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READCARD_H__0531B6DA_7EAF_4472_84E5_9C0460312308__INCLUDED_)
