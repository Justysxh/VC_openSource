// PrintLineandFont.h : main header file for the PRINTLINEANDFONT application
//

#if !defined(AFX_PRINTLINEANDFONT_H__FEACB89B_0AB2_4F25_9929_A90BF2234D4F__INCLUDED_)
#define AFX_PRINTLINEANDFONT_H__FEACB89B_0AB2_4F25_9929_A90BF2234D4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintLineandFontApp:
// See PrintLineandFont.cpp for the implementation of this class
//

class CPrintLineandFontApp : public CWinApp
{
public:
	CPrintLineandFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintLineandFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintLineandFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTLINEANDFONT_H__FEACB89B_0AB2_4F25_9929_A90BF2234D4F__INCLUDED_)
