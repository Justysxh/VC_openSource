// FileFindThread.h : main header file for the FILEFINDTHREAD application
//

#if !defined(AFX_FILEFINDTHREAD_H__C55838E6_9E95_45DE_BAE3_AB814DD8969C__INCLUDED_)
#define AFX_FILEFINDTHREAD_H__C55838E6_9E95_45DE_BAE3_AB814DD8969C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileFindThreadApp:
// See FileFindThread.cpp for the implementation of this class
//

class CFileFindThreadApp : public CWinApp
{
public:
	CFileFindThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileFindThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileFindThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEFINDTHREAD_H__C55838E6_9E95_45DE_BAE3_AB814DD8969C__INCLUDED_)
