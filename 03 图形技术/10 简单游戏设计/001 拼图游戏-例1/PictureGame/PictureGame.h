// PictureGame.h : main header file for the PICTUREGAME application
//

#if !defined(AFX_PICTUREGAME_H__B9521042_7A86_4E39_BCD3_337284997D09__INCLUDED_)
#define AFX_PICTUREGAME_H__B9521042_7A86_4E39_BCD3_337284997D09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPictureGameApp:
// See PictureGame.cpp for the implementation of this class
//

class CPictureGameApp : public CWinApp
{
public:
	CPictureGameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPictureGameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREGAME_H__B9521042_7A86_4E39_BCD3_337284997D09__INCLUDED_)
