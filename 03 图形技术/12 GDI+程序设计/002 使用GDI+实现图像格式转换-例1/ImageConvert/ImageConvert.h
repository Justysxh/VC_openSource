// ImageConvert.h : main header file for the IMAGECONVERT application
//

#if !defined(AFX_IMAGECONVERT_H__BA91DCEC_A486_43F7_9E73_C613135D9249__INCLUDED_)
#define AFX_IMAGECONVERT_H__BA91DCEC_A486_43F7_9E73_C613135D9249__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageConvertApp:
// See ImageConvert.cpp for the implementation of this class
//

class CImageConvertApp : public CWinApp
{
public:
	CImageConvertApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageConvertApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageConvertApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECONVERT_H__BA91DCEC_A486_43F7_9E73_C613135D9249__INCLUDED_)
