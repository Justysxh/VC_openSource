// RecordSound.h : main header file for the RECORDSOUND application
//

#if !defined(AFX_RECORDSOUND_H__117AFA9F_8F54_48A0_A5A6_71EEAFE71D62__INCLUDED_)
#define AFX_RECORDSOUND_H__117AFA9F_8F54_48A0_A5A6_71EEAFE71D62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecordSoundApp:
// See RecordSound.cpp for the implementation of this class
//

class CRecordSoundApp : public CWinApp
{
public:
	CRecordSoundApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordSoundApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRecordSoundApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDSOUND_H__117AFA9F_8F54_48A0_A5A6_71EEAFE71D62__INCLUDED_)
