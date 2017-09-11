// Mapping.h : main header file for the MAPPING application
//

#if !defined(AFX_MAPPING_H__CD7BB18F_2AF8_4BAB_9A7F_3D45B6C899F7__INCLUDED_)
#define AFX_MAPPING_H__CD7BB18F_2AF8_4BAB_9A7F_3D45B6C899F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMappingApp:
// See Mapping.cpp for the implementation of this class
//

class CMappingApp : public CWinApp
{
public:
	CMappingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMappingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMappingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPING_H__CD7BB18F_2AF8_4BAB_9A7F_3D45B6C899F7__INCLUDED_)
