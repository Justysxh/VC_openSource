// BitmapButton.h : main header file for the BITMAPBUTTON application
//

#if !defined(AFX_BITMAPBUTTON_H__099E5296_E50F_4CD5_ADE3_5C913412F430__INCLUDED_)
#define AFX_BITMAPBUTTON_H__099E5296_E50F_4CD5_ADE3_5C913412F430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonApp:
// See BitmapButton.cpp for the implementation of this class
//

class CBitmapButtonApp : public CWinApp
{
public:
	CBitmapButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitmapButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBUTTON_H__099E5296_E50F_4CD5_ADE3_5C913412F430__INCLUDED_)
