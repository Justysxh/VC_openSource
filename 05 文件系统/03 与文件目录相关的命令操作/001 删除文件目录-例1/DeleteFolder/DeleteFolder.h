// DeleteFolder.h : main header file for the DELETEFOLDER application
//

#if !defined(AFX_DELETEFOLDER_H__9F78D621_7411_4667_904E_A5098971243D__INCLUDED_)
#define AFX_DELETEFOLDER_H__9F78D621_7411_4667_904E_A5098971243D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteFolderApp:
// See DeleteFolder.cpp for the implementation of this class
//

class CDeleteFolderApp : public CWinApp
{
public:
	CDeleteFolderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteFolderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteFolderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEFOLDER_H__9F78D621_7411_4667_904E_A5098971243D__INCLUDED_)
