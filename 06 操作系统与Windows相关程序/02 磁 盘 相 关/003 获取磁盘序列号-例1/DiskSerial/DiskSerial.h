// DiskSerial.h : main header file for the DISKSERIAL application
//

#if !defined(AFX_DISKSERIAL_H__E016B1F6_FD30_4AB5_AF8B_AE03ADE0C1A3__INCLUDED_)
#define AFX_DISKSERIAL_H__E016B1F6_FD30_4AB5_AF8B_AE03ADE0C1A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDiskSerialApp:
// See DiskSerial.cpp for the implementation of this class
//

class CDiskSerialApp : public CWinApp
{
public:
	CDiskSerialApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskSerialApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDiskSerialApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKSERIAL_H__E016B1F6_FD30_4AB5_AF8B_AE03ADE0C1A3__INCLUDED_)
