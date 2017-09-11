// BmpTree.h : main header file for the BMPTREE application
//

#if !defined(AFX_BMPTREE_H__AB4754ED_E739_44CD_BDDF_A259F90FF1A6__INCLUDED_)
#define AFX_BMPTREE_H__AB4754ED_E739_44CD_BDDF_A259F90FF1A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpTreeApp:
// See BmpTree.cpp for the implementation of this class
//

class CBmpTreeApp : public CWinApp
{
public:
	CBmpTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmpTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPTREE_H__AB4754ED_E739_44CD_BDDF_A259F90FF1A6__INCLUDED_)
