// AudioCompress.h : main header file for the AUDIOCOMPRESS application
//

#if !defined(AFX_AUDIOCOMPRESS_H__C5DA03A6_BD6E_4A44_8BDF_2A0E15E0A7BB__INCLUDED_)
#define AFX_AUDIOCOMPRESS_H__C5DA03A6_BD6E_4A44_8BDF_2A0E15E0A7BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAudioCompressApp:
// See AudioCompress.cpp for the implementation of this class
//

class CAudioCompressApp : public CWinApp
{
public:
	CAudioCompressApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAudioCompressApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAudioCompressApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUDIOCOMPRESS_H__C5DA03A6_BD6E_4A44_8BDF_2A0E15E0A7BB__INCLUDED_)
