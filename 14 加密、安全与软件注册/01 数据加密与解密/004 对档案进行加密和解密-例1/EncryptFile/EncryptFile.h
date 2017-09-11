// EncryptFile.h : main header file for the ENCRYPTFILE application
//

#if !defined(AFX_ENCRYPTFILE_H__DBF15C7D_D2D7_4CB7_965A_014F47D50205__INCLUDED_)
#define AFX_ENCRYPTFILE_H__DBF15C7D_D2D7_4CB7_965A_014F47D50205__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEncryptFileApp:
// See EncryptFile.cpp for the implementation of this class
//

class CEncryptFileApp : public CWinApp
{
public:
	CEncryptFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncryptFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEncryptFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTFILE_H__DBF15C7D_D2D7_4CB7_965A_014F47D50205__INCLUDED_)
