// EnumServer.h : main header file for the ENUMSERVER application
//

#if !defined(AFX_ENUMSERVER_H__55298FE3_AD5B_4EF5_99B1_9245C47E19D1__INCLUDED_)
#define AFX_ENUMSERVER_H__55298FE3_AD5B_4EF5_99B1_9245C47E19D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumServerApp:
// See EnumServer.cpp for the implementation of this class
//

class CEnumServerApp : public CWinApp
{
public:
	CEnumServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMSERVER_H__55298FE3_AD5B_4EF5_99B1_9245C47E19D1__INCLUDED_)
