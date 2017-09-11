// ReturnPata.h : main header file for the RETURNPATA application
//

#if !defined(AFX_RETURNPATA_H__81DDC112_CF50_49AB_888E_AAF608EA1C80__INCLUDED_)
#define AFX_RETURNPATA_H__81DDC112_CF50_49AB_888E_AAF608EA1C80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReturnPataApp:
// See ReturnPata.cpp for the implementation of this class
//

class CReturnPataApp : public CWinApp
{
public:
	CReturnPataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnPataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReturnPataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNPATA_H__81DDC112_CF50_49AB_888E_AAF608EA1C80__INCLUDED_)
