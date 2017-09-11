#if !defined(AFX_SERVERSOCKET_H__0D149AB8_C62D_4FED_BBB0_EC181FFD208F__INCLUDED_)
#define AFX_SERVERSOCKET_H__0D149AB8_C62D_4FED_BBB0_EC181FFD208F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//
#include "uuuuDlg.h"
#include "Afxsock.h"
/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target
class CUuuuDlg;
class CServerSocket : public CSocket
{
// Attributes
public:
// Operations
public:
	CServerSocket(CUuuuDlg* pDlg);
	CUuuuDlg* m_pDlg;

	virtual ~CServerSocket();
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__0D149AB8_C62D_4FED_BBB0_EC181FFD208F__INCLUDED_)
