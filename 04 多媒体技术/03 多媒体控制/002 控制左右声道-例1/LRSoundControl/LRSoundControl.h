// LRSoundControl.h : main header file for the LRSOUNDCONTROL application
//

#if !defined(AFX_LRSOUNDCONTROL_H__4BF795B8_AEF4_4249_804B_B4B346E7F113__INCLUDED_)
#define AFX_LRSOUNDCONTROL_H__4BF795B8_AEF4_4249_804B_B4B346E7F113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLRSoundControlApp:
// See LRSoundControl.cpp for the implementation of this class
//

class CLRSoundControlApp : public CWinApp
{
public:
	CLRSoundControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLRSoundControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLRSoundControlApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LRSOUNDCONTROL_H__4BF795B8_AEF4_4249_804B_B4B346E7F113__INCLUDED_)
