// FingerExercise.h : main header file for the FINGEREXERCISE application
//

#if !defined(AFX_FINGEREXERCISE_H__3B85D044_A024_4264_B452_3852D220DD6A__INCLUDED_)
#define AFX_FINGEREXERCISE_H__3B85D044_A024_4264_B452_3852D220DD6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFingerExerciseApp:
// See FingerExercise.cpp for the implementation of this class
//

class CFingerExerciseApp : public CWinApp
{
public:
	CFingerExerciseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFingerExerciseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFingerExerciseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINGEREXERCISE_H__3B85D044_A024_4264_B452_3852D220DD6A__INCLUDED_)
