// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "kinescode.h"
#include "KinescodeDlg.h"
#include "ClientSocket.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket(CKinescodeDlg* pDlg)
{
	m_pDlg = pDlg;
}

CClientSocket::~CClientSocket()
{
	m_pDlg = NULL;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions


void CClientSocket::OnReceive(int nErrorCode) 
{
	m_pDlg->ReceiveData(this);
//	CSocket::OnReceive(nErrorCode);
}
