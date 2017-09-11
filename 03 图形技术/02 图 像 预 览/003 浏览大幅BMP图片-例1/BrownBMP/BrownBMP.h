// BrownBMP.h : main header file for the BROWNBMP application
//

#if !defined(AFX_BROWNBMP_H__CD022C85_9BDD_43CE_8908_1FBDD72ACA18__INCLUDED_)
#define AFX_BROWNBMP_H__CD022C85_9BDD_43CE_8908_1FBDD72ACA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrownBMPApp:
// See BrownBMP.cpp for the implementation of this class
//

class CBrownBMPApp : public CWinApp
{
public:
	CBrownBMPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrownBMPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrownBMPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWNBMP_H__CD022C85_9BDD_43CE_8908_1FBDD72ACA18__INCLUDED_)
