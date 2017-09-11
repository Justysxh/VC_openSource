// SolGame.h : main header file for the SOLGAME application
//

#if !defined(AFX_SOLGAME_H__57E70EB5_A0A2_45D2_B7C8_53773FC3A4BD__INCLUDED_)
#define AFX_SOLGAME_H__57E70EB5_A0A2_45D2_B7C8_53773FC3A4BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSolGameApp:
// See SolGame.cpp for the implementation of this class
//

class CSolGameApp : public CWinApp
{
public:
	CSolGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSolGameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLGAME_H__57E70EB5_A0A2_45D2_B7C8_53773FC3A4BD__INCLUDED_)
