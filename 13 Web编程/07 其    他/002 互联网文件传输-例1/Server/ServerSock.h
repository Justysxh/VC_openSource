#if !defined(AFX_SERVERSOCK_H__81C34A9E_643D_4A9B_A317_661D8C35780F__INCLUDED_)
#define AFX_SERVERSOCK_H__81C34A9E_643D_4A9B_A317_661D8C35780F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSock.h : header file
//

#include "Afxsock.h"

/////////////////////////////////////////////////////////////////////////////
// CServerSock command target

class CServerDlg;

class CServerSock : public CSocket
{
// Attributes
public:

// Operations
public:
	CServerSock();
	virtual ~CServerSock();

// Overrides
public:
	BOOL PumpMessages(UINT uStopFlag);
	void SetDlg(CServerDlg* pDlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSock)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
	CServerDlg* m_pDlg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCK_H__81C34A9E_643D_4A9B_A317_661D8C35780F__INCLUDED_)
