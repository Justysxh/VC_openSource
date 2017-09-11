// StartMode.h : main header file for the STARTMODE application
//

#if !defined(AFX_STARTMODE_H__EA3C45D7_3505_44AB_B072_828C92CC07BB__INCLUDED_)
#define AFX_STARTMODE_H__EA3C45D7_3505_44AB_B072_828C92CC07BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartModeApp:
// See StartMode.cpp for the implementation of this class
//

class CStartModeApp : public CWinApp
{
public:
	CStartModeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartModeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStartModeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTMODE_H__EA3C45D7_3505_44AB_B072_828C92CC07BB__INCLUDED_)
