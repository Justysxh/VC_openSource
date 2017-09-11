// RemoteClose.h : main header file for the REMOTECLOSE application
//

#if !defined(AFX_REMOTECLOSE_H__3C16764D_4719_4848_955A_CEAD0464DCF7__INCLUDED_)
#define AFX_REMOTECLOSE_H__3C16764D_4719_4848_955A_CEAD0464DCF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRemoteCloseApp:
// See RemoteClose.cpp for the implementation of this class
//

class CRemoteCloseApp : public CWinApp
{
public:
	CRemoteCloseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemoteCloseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRemoteCloseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTECLOSE_H__3C16764D_4719_4848_955A_CEAD0464DCF7__INCLUDED_)
