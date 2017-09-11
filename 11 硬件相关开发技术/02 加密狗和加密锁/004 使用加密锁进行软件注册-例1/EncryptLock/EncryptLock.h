// EncryptLock.h : main header file for the ENCRYPTLOCK application
//

#if !defined(AFX_ENCRYPTLOCK_H__752A883D_C6A8_42E8_BF65_053E46DB4FA2__INCLUDED_)
#define AFX_ENCRYPTLOCK_H__752A883D_C6A8_42E8_BF65_053E46DB4FA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEncryptLockApp:
// See EncryptLock.cpp for the implementation of this class
//

class CEncryptLockApp : public CWinApp
{
public:
	CEncryptLockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncryptLockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEncryptLockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTLOCK_H__752A883D_C6A8_42E8_BF65_053E46DB4FA2__INCLUDED_)
