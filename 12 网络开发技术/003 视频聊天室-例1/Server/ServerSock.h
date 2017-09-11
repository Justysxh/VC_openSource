#if !defined(AFX_SERVERSOCK_H__CC3F2CAE_F9DD_4DAE_ACF3_F7D9ADBD07BF__INCLUDED_)
#define AFX_SERVERSOCK_H__CC3F2CAE_F9DD_4DAE_ACF3_F7D9ADBD07BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CServerSock command target
#include "Afxsock.h"
class CServerDlg;
class CServerSock : public CSocket
{
// Attributes
public:

// Operations
public:
	CServerSock();
	virtual ~CServerSock();
	CServerDlg* m_pDlg;
	int m_nFlag;
	
// Overrides
public:
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
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCK_H__CC3F2CAE_F9DD_4DAE_ACF3_F7D9ADBD07BF__INCLUDED_)
