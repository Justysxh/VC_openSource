// INIReg.h : main header file for the INIREG application
//

#if !defined(AFX_INIREG_H__CD93B61D_7909_48BD_ADE5_7800FE3B2E11__INCLUDED_)
#define AFX_INIREG_H__CD93B61D_7909_48BD_ADE5_7800FE3B2E11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CINIRegApp:
// See INIReg.cpp for the implementation of this class
//

class CINIRegApp : public CWinApp
{
public:
	CINIRegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINIRegApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CINIRegApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INIREG_H__CD93B61D_7909_48BD_ADE5_7800FE3B2E11__INCLUDED_)
