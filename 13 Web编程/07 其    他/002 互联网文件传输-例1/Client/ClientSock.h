#if !defined(AFX_CLIENTSOCK_H__458282AE_9F24_40BB_941B_449479304446__INCLUDED_)
#define AFX_CLIENTSOCK_H__458282AE_9F24_40BB_941B_449479304446__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSock.h : header file
//
#include "Afxsock.h"


/////////////////////////////////////////////////////////////////////////////
// CClientSock command target
class CClientDlg;
class CClientSock : public CSocket
{
// Attributes
public:

// Operations
public:
	
	CClientSock();
	virtual ~CClientSock();

// Overrides
public:
	void SetDlg(CClientDlg* pDlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSock)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
	CClientDlg* m_pDlg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCK_H__458282AE_9F24_40BB_941B_449479304446__INCLUDED_)
