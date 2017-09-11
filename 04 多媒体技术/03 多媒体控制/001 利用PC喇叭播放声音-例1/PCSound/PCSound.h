// PCSound.h : main header file for the PCSOUND application
//

#if !defined(AFX_PCSOUND_H__D3D65CBD_3169_473F_A366_FF36432EBDFF__INCLUDED_)
#define AFX_PCSOUND_H__D3D65CBD_3169_473F_A366_FF36432EBDFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPCSoundApp:
// See PCSound.cpp for the implementation of this class
//

class CPCSoundApp : public CWinApp
{
public:
	CPCSoundApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCSoundApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPCSoundApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCSOUND_H__D3D65CBD_3169_473F_A366_FF36432EBDFF__INCLUDED_)
