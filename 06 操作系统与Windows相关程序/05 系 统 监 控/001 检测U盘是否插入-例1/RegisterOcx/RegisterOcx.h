// RegisterOcx.h : main header file for the REGISTEROCX application
//

#if !defined(AFX_REGISTEROCX_H__57E4FCDA_8AF8_4E2B_9486_852F9B62C18A__INCLUDED_)
#define AFX_REGISTEROCX_H__57E4FCDA_8AF8_4E2B_9486_852F9B62C18A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegisterOcxApp:
// See RegisterOcx.cpp for the implementation of this class
//

class CRegisterOcxApp : public CWinApp
{
public:
	CRegisterOcxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterOcxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegisterOcxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTEROCX_H__57E4FCDA_8AF8_4E2B_9486_852F9B62C18A__INCLUDED_)
