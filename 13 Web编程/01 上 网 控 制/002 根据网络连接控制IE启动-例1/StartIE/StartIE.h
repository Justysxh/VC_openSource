// StartIE.h : main header file for the STARTIE application
//

#if !defined(AFX_STARTIE_H__07CC8D1F_B980_466C_9FC9_3B3891A47029__INCLUDED_)
#define AFX_STARTIE_H__07CC8D1F_B980_466C_9FC9_3B3891A47029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStartIEApp:
// See StartIE.cpp for the implementation of this class
//

class CStartIEApp : public CWinApp
{
public:
	CStartIEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStartIEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStartIEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTIE_H__07CC8D1F_B980_466C_9FC9_3B3891A47029__INCLUDED_)
