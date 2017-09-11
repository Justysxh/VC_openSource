// ManageImage.h : main header file for the MANAGEIMAGE application
//

#if !defined(AFX_MANAGEIMAGE_H__7ED13E9D_213C_4B3F_B209_BF1381A77D98__INCLUDED_)
#define AFX_MANAGEIMAGE_H__7ED13E9D_213C_4B3F_B209_BF1381A77D98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CManageImageApp:
// See ManageImage.cpp for the implementation of this class
//

class CManageImageApp : public CWinApp
{
public:
	CManageImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CManageImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEIMAGE_H__7ED13E9D_213C_4B3F_B209_BF1381A77D98__INCLUDED_)
