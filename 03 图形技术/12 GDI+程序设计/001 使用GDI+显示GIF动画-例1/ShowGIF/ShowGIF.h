// ShowGIF.h : main header file for the SHOWGIF application
//

#if !defined(AFX_SHOWGIF_H__6E4F225D_4E2F_4AE4_92EA_B20F1D398E7B__INCLUDED_)
#define AFX_SHOWGIF_H__6E4F225D_4E2F_4AE4_92EA_B20F1D398E7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowGIFApp:
// See ShowGIF.cpp for the implementation of this class
//

class CShowGIFApp : public CWinApp
{
public:
	CShowGIFApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGIFApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowGIFApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGIF_H__6E4F225D_4E2F_4AE4_92EA_B20F1D398E7B__INCLUDED_)
