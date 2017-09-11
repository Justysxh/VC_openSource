// TextScreenSave.h : main header file for the TEXTSCREENSAVE application
//

#if !defined(AFX_TEXTSCREENSAVE_H__09934523_537D_4B6A_8F2B_81922A0C0D57__INCLUDED_)
#define AFX_TEXTSCREENSAVE_H__09934523_537D_4B6A_8F2B_81922A0C0D57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextScreenSaveApp:
// See TextScreenSave.cpp for the implementation of this class
//

class CTextScreenSaveApp : public CWinApp
{
public:
	CTextScreenSaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextScreenSaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextScreenSaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTSCREENSAVE_H__09934523_537D_4B6A_8F2B_81922A0C0D57__INCLUDED_)
