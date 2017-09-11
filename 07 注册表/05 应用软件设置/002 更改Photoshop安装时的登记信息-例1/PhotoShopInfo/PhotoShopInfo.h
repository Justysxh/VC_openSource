// PhotoShopInfo.h : main header file for the PHOTOSHOPINFO application
//

#if !defined(AFX_PHOTOSHOPINFO_H__9F1FCAC0_300B_40DD_80A4_63A20BF0F7C8__INCLUDED_)
#define AFX_PHOTOSHOPINFO_H__9F1FCAC0_300B_40DD_80A4_63A20BF0F7C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPhotoShopInfoApp:
// See PhotoShopInfo.cpp for the implementation of this class
//

class CPhotoShopInfoApp : public CWinApp
{
public:
	CPhotoShopInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoShopInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPhotoShopInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHOTOSHOPINFO_H__9F1FCAC0_300B_40DD_80A4_63A20BF0F7C8__INCLUDED_)
