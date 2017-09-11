// TextColor.h : main header file for the TEXTCOLOR application
//

#if !defined(AFX_TEXTCOLOR_H__38FB13CF_9436_4AF6_BCCF_26F99355307A__INCLUDED_)
#define AFX_TEXTCOLOR_H__38FB13CF_9436_4AF6_BCCF_26F99355307A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextColorApp:
// See TextColor.cpp for the implementation of this class
//

class CTextColorApp : public CWinApp
{
public:
	CTextColorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextColorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextColorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTCOLOR_H__38FB13CF_9436_4AF6_BCCF_26F99355307A__INCLUDED_)
