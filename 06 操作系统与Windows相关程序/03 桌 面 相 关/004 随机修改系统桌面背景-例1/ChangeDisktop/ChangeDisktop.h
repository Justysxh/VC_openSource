// ChangeDisktop.h : main header file for the CHANGEDISKTOP application
//

#if !defined(AFX_CHANGEDISKTOP_H__8974F7FD_4E34_4A24_BE4B_FFEB05313B01__INCLUDED_)
#define AFX_CHANGEDISKTOP_H__8974F7FD_4E34_4A24_BE4B_FFEB05313B01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChangeDisktopApp:
// See ChangeDisktop.cpp for the implementation of this class
//
class CChangeDisktopApp : public CWinApp
{
public:
	CChangeDisktopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDisktopApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChangeDisktopApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDISKTOP_H__8974F7FD_4E34_4A24_BE4B_FFEB05313B01__INCLUDED_)
