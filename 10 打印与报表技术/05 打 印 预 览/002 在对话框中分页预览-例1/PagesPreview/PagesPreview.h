// PagesPreview.h : main header file for the PAGESPREVIEW application
//

#if !defined(AFX_PAGESPREVIEW_H__5AFF06AD_29E0_4394_8ADF_BD4F2FFB0028__INCLUDED_)
#define AFX_PAGESPREVIEW_H__5AFF06AD_29E0_4394_8ADF_BD4F2FFB0028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPagesPreviewApp:
// See PagesPreview.cpp for the implementation of this class
//

class CPagesPreviewApp : public CWinApp
{

public:

	CPagesPreviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPagesPreviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPagesPreviewApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPREVIEW_H__5AFF06AD_29E0_4394_8ADF_BD4F2FFB0028__INCLUDED_)
