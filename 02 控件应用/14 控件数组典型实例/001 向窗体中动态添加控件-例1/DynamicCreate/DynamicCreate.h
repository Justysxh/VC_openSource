// DynamicCreate.h : main header file for the DYNAMICCREATE application
//

#if !defined(AFX_DYNAMICCREATE_H__0D151B23_3B9E_4D7C_8756_7D67D6F2FE34__INCLUDED_)
#define AFX_DYNAMICCREATE_H__0D151B23_3B9E_4D7C_8756_7D67D6F2FE34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynamicCreateApp:
// See DynamicCreate.cpp for the implementation of this class
//

class CDynamicCreateApp : public CWinApp
{
public:
	CDynamicCreateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicCreateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDynamicCreateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICCREATE_H__0D151B23_3B9E_4D7C_8756_7D67D6F2FE34__INCLUDED_)
