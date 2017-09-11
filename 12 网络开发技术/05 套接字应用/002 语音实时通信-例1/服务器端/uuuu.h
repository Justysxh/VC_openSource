// uuuu.h : main header file for the UUUU application
//

#if !defined(AFX_UUUU_H__5255E25D_6FB3_4EA5_A139_CD627021C0FC__INCLUDED_)
#define AFX_UUUU_H__5255E25D_6FB3_4EA5_A139_CD627021C0FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUuuuApp:
// See uuuu.cpp for the implementation of this class
//
//套接字类型,视频套接字,音频套接字,文本套接字
enum SockType { tpVideo,tpAudio,tpText} ;

class CUuuuApp : public CWinApp
{
public:
	CUuuuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUuuuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUuuuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUUU_H__5255E25D_6FB3_4EA5_A139_CD627021C0FC__INCLUDED_)
