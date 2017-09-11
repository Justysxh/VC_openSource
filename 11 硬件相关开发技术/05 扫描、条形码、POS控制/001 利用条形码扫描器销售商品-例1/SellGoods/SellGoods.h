// SellGoods.h : main header file for the SELLGOODS application
//

#if !defined(AFX_SELLGOODS_H__567D3D47_BE45_4701_A31A_5779252C577B__INCLUDED_)
#define AFX_SELLGOODS_H__567D3D47_BE45_4701_A31A_5779252C577B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSellGoodsApp:
// See SellGoods.cpp for the implementation of this class
//

class CSellGoodsApp : public CWinApp
{
public:
	CSellGoodsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSellGoodsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSellGoodsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELLGOODS_H__567D3D47_BE45_4701_A31A_5779252C577B__INCLUDED_)
