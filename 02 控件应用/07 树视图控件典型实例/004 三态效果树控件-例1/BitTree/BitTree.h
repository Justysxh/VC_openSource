// BitTree.h : main header file for the BITTREE application
//

#if !defined(AFX_BITTREE_H__B1ADC30D_C906_4CA8_B603_4187CCACE37C__INCLUDED_)
#define AFX_BITTREE_H__B1ADC30D_C906_4CA8_B603_4187CCACE37C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitTreeApp:
// See BitTree.cpp for the implementation of this class
//

class CBitTreeApp : public CWinApp
{
public:
	CBitTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITTREE_H__B1ADC30D_C906_4CA8_B603_4187CCACE37C__INCLUDED_)
