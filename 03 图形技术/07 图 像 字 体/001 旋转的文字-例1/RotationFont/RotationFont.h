// RotationFont.h : main header file for the ROTATIONFONT application
//

#if !defined(AFX_ROTATIONFONT_H__1133C010_7900_4DA2_BFA1_69D695811D02__INCLUDED_)
#define AFX_ROTATIONFONT_H__1133C010_7900_4DA2_BFA1_69D695811D02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRotationFontApp:
// See RotationFont.cpp for the implementation of this class
//

class CRotationFontApp : public CWinApp
{
public:
	CRotationFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotationFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRotationFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATIONFONT_H__1133C010_7900_4DA2_BFA1_69D695811D02__INCLUDED_)
