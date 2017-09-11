// CombineImage.h : main header file for the COMBINEIMAGE application
//

#if !defined(AFX_COMBINEIMAGE_H__169B21CE_8FA0_41D3_9C67_3FE4EE515918__INCLUDED_)
#define AFX_COMBINEIMAGE_H__169B21CE_8FA0_41D3_9C67_3FE4EE515918__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCombineImageApp:
// See CombineImage.cpp for the implementation of this class
//

class CCombineImageApp : public CWinApp
{
public:
	CCombineImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombineImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCombineImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBINEIMAGE_H__169B21CE_8FA0_41D3_9C67_3FE4EE515918__INCLUDED_)
