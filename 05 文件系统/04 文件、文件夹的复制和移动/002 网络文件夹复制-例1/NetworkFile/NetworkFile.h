// NetworkFile.h : main header file for the NETWORKFILE application
//

#if !defined(AFX_NETWORKFILE_H__93876991_508D_45EF_BFB8_03181E7F6C12__INCLUDED_)
#define AFX_NETWORKFILE_H__93876991_508D_45EF_BFB8_03181E7F6C12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetworkFileApp:
// See NetworkFile.cpp for the implementation of this class
//

class CNetworkFileApp : public CWinApp
{
public:
	CNetworkFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetworkFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetworkFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORKFILE_H__93876991_508D_45EF_BFB8_03181E7F6C12__INCLUDED_)
