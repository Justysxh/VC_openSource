// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket(CServerDlg* pdlg)
: m_pDlg(pdlg)
{

}

CClientSocket::~CClientSocket()
{
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
	CSocket::OnReceive(nErrorCode);
	if(m_pDlg)
	{		
		//调用对话框的ReceiveData方法
		m_pDlg->ReceiveData(this);
	}
}

void CClientSocket::OnClose( int nErrorCode )
{
	CSocket::OnClose(nErrorCode);
	AfxMessageBox("有客户端发生关闭");
	m_pDlg->OnClose(this);
}