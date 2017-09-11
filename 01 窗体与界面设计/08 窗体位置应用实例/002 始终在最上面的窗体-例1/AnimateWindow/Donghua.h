// Donghua.h : main header file for the DONGHUA application
//

#if !defined(AFX_DONGHUA_H__66B919F1_C90C_421E_8C3A_1B1B6A0D2130__INCLUDED_)
#define AFX_DONGHUA_H__66B919F1_C90C_421E_8C3A_1B1B6A0D2130__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDonghuaApp:
// See Donghua.cpp for the implementation of this class
//

class CDonghuaApp : public CWinApp
{
public:
	CDonghuaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDonghuaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDonghuaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONGHUA_H__66B919F1_C90C_421E_8C3A_1B1B6A0D2130__INCLUDED_)
