#if !defined(AFX_CLIENTSOCKET_H__7067C654_9271_4688_A95A_0A98A528BC1F__INCLUDED_)
#define AFX_CLIENTSOCKET_H__7067C654_9271_4688_A95A_0A98A528BC1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//
#include "Afxsock.h"
#include "uuuuDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target
class CUuuuDlg;



class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket(CUuuuDlg* pDlg,SockType tpSock);
	virtual ~CClientSocket();
	CUuuuDlg* m_pDlg;
	SockType  m_SockType;
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__7067C654_9271_4688_A95A_0A98A528BC1F__INCLUDED_)
