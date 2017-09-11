// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__77948BE3_2F03_11D1_9DAB_00C04FD9DFD9__INCLUDED_)
#define AFX_STDAFX_H__77948BE3_2F03_11D1_9DAB_00C04FD9DFD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Insert your headers here
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>

//Include ODS headers
#ifdef __cplusplus
extern "C" {
#endif 

#include <Srv.h>		// Main header file that includes all other header files

#ifdef __cplusplus
}
#endif 


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__77948BE3_2F03_11D1_9DAB_00C04FD9DFD9__INCLUDED_)
