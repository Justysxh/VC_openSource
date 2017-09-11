#if !defined(AFX_CLIENTSOCK_H__721AAF32_BD54_4B1E_9F8E_07959D677E28__INCLUDED_)
#define AFX_CLIENTSOCK_H__721AAF32_BD54_4B1E_9F8E_07959D677E28__INCLUDED_

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
	CClientDlg* m_pDlg;
	CClientSock();
	virtual ~CClientSock();

// Overrides
public:
	void SetDialog(CClientDlg* pDlg);
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
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCK_H__721AAF32_BD54_4B1E_9F8E_07959D677E28__INCLUDED_)
