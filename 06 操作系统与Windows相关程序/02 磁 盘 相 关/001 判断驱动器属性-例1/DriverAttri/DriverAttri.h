// DriverAttri.h : main header file for the DRIVERATTRI application
//

#if !defined(AFX_DRIVERATTRI_H__BAF0BF08_E115_4BBD_AF3C_6C58768D4CCC__INCLUDED_)
#define AFX_DRIVERATTRI_H__BAF0BF08_E115_4BBD_AF3C_6C58768D4CCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDriverAttriApp:
// See DriverAttri.cpp for the implementation of this class
//

class CDriverAttriApp : public CWinApp
{
public:
	CDriverAttriApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverAttriApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDriverAttriApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERATTRI_H__BAF0BF08_E115_4BBD_AF3C_6C58768D4CCC__INCLUDED_)
