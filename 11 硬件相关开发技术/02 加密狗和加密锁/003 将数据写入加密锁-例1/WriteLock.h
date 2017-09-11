// WriteLock.h : main header file for the WRITELOCK application
//

#if !defined(AFX_WRITELOCK_H__C5AD7CA2_7C9D_4068_A61D_DB82D2C644AC__INCLUDED_)
#define AFX_WRITELOCK_H__C5AD7CA2_7C9D_4068_A61D_DB82D2C644AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWriteLockApp:
// See WriteLock.cpp for the implementation of this class
//

class CWriteLockApp : public CWinApp
{
public:
	CWriteLockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWriteLockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWriteLockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WRITELOCK_H__C5AD7CA2_7C9D_4068_A61D_DB82D2C644AC__INCLUDED_)
