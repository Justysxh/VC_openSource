// Drag.h : main header file for the DRAG application
//

#if !defined(AFX_DRAG_H__C6CC79EB_24CC_4F25_8551_8B92884A954F__INCLUDED_)
#define AFX_DRAG_H__C6CC79EB_24CC_4F25_8551_8B92884A954F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDragApp:
// See Drag.cpp for the implementation of this class
//

class CDragApp : public CWinApp
{
public:
	CDragApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDragApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAG_H__C6CC79EB_24CC_4F25_8551_8B92884A954F__INCLUDED_)
