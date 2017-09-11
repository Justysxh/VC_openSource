// ClientSock.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientSock.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSock

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSock, CSocket)
	//{{AFX_MSG_MAP(CClientSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSock member functions

void CClientSock::SetDlg(CClientDlg *pDlg)
{
	m_pDlg = pDlg;
}

void CClientSock::OnReceive(int nErrorCode) 
{
	m_pDlg->ReceiveData();	
	CSocket::OnReceive(nErrorCode);
}
