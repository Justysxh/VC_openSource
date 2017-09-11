// Relievo.h : main header file for the RELIEVO application
//

#if !defined(AFX_RELIEVO_H__D0A98840_4E12_46BF_AC79_CE46593893ED__INCLUDED_)
#define AFX_RELIEVO_H__D0A98840_4E12_46BF_AC79_CE46593893ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRelievoApp:
// See Relievo.cpp for the implementation of this class
//

class CRelievoApp : public CWinApp
{
public:
	CRelievoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRelievoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRelievoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RELIEVO_H__D0A98840_4E12_46BF_AC79_CE46593893ED__INCLUDED_)
