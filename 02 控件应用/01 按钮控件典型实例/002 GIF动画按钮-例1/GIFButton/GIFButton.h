// GIFButton.h : main header file for the GIFBUTTON application
//

#if !defined(AFX_GIFBUTTON_H__73D21D84_269D_483D_A8AA_48D72434E0E9__INCLUDED_)
#define AFX_GIFBUTTON_H__73D21D84_269D_483D_A8AA_48D72434E0E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGIFButtonApp:
// See GIFButton.cpp for the implementation of this class
//

class CGIFButtonApp : public CWinApp
{
public:
	CGIFButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGIFButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGIFButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GIFBUTTON_H__73D21D84_269D_483D_A8AA_48D72434E0E9__INCLUDED_)
