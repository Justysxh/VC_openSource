// Title.h : main header file for the TITLE application
//

#if !defined(AFX_TITLE_H__BEBAA10B_4260_4459_959A_6C75790E1298__INCLUDED_)
#define AFX_TITLE_H__BEBAA10B_4260_4459_959A_6C75790E1298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTitleApp:
// See Title.cpp for the implementation of this class
//

class CTitleApp : public CWinApp
{
public:
	CTitleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTitleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLE_H__BEBAA10B_4260_4459_959A_6C75790E1298__INCLUDED_)
