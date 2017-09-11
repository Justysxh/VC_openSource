// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "uuuu.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket(CUuuuDlg* pDlg)
: m_pDlg(pDlg)
{

}

CServerSocket::~CServerSocket()
{
	m_pDlg = NULL;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnAccept(int nErrorCode) 
{
	m_pDlg->AcceptConnect();
	CSocket::OnAccept(nErrorCode);
}
