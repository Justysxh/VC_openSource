// PhoneRecord.h : main header file for the PHONERECORD application
//

#if !defined(AFX_PHONERECORD_H__527017B4_4B6B_47DC_9FF7_5F06328BAB07__INCLUDED_)
#define AFX_PHONERECORD_H__527017B4_4B6B_47DC_9FF7_5F06328BAB07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPhoneRecordApp:
// See PhoneRecord.cpp for the implementation of this class
//

class CPhoneRecordApp : public CWinApp
{
public:
	CPhoneRecordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhoneRecordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPhoneRecordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PHONERECORD_H__527017B4_4B6B_47DC_9FF7_5F06328BAB07__INCLUDED_)
