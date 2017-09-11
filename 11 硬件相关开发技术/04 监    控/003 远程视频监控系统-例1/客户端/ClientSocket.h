#if !defined(AFX_CLIENTSOCKET_H__CEC97C4B_0D07_42A3_98FA_A335167F0CF7__INCLUDED_)
#define AFX_CLIENTSOCKET_H__CEC97C4B_0D07_42A3_98FA_A335167F0CF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afxsock.h"

/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target
class CKinescodeDlg;

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket(CKinescodeDlg* pDlg);
	virtual ~CClientSocket();
	CKinescodeDlg* m_pDlg;

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

#endif // !defined(AFX_CLIENTSOCKET_H__CEC97C4B_0D07_42A3_98FA_A335167F0CF7__INCLUDED_)
