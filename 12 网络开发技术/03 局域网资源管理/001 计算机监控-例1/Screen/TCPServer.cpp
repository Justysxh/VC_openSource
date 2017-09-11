// TCPServer.cpp: implementation of the CTCPServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Server.h"
#include "TCPServer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

////CTCPServerEvent///////////////////////////////////////////////////

void CTCPServerEvent::OnAccept(CSocket * socket, int nErrorCode )
{

}

void CTCPClientEvent::OnClose(CSocket * socket, int nErrorCode )
{

}

void CTCPClientEvent::OnReceive(CSocket * socket, int nErrorCode )
{

}

////CTCPClientSocket//////////////////////////////////////////////////
CTCPClientSocket::CTCPClientSocket(CTCPServerSocket *ServerSocket)
	:CSocket()
{
	serversocket = ServerSocket;
}

void CTCPClientSocket::SetClientEvent(CTCPClientEvent * ClientEvent)
{
	this->clientevent = ClientEvent;
}

void CTCPClientSocket::OnClose(int nErrorCode )
{
	CSocket::OnClose(nErrorCode);
	if (clientevent != NULL)
		clientevent->OnClose(this,nErrorCode);
	POSITION pos = 
		serversocket->ClientList.GetHeadPosition();
	while (pos != NULL)
	{
		if (serversocket->ClientList.GetAt(pos) == this)
			serversocket->ClientList.RemoveAt(pos);
		serversocket->ClientList.GetNext(pos);
	}
}

void CTCPClientSocket::OnReceive(int nErrorCode )
{
	CSocket::OnReceive(nErrorCode);
	if (clientevent != NULL)
		clientevent->OnReceive(this,nErrorCode);
}

////CTCPServerSocket/////////////////////////////////////////////////////
CTCPServerSocket::CTCPServerSocket()
:CSocket()
{

}
void CTCPServerSocket::SetServerEvent(CTCPServerEvent *ServerEvent)
{
	serverevent = ServerEvent;
		
}

void CTCPServerSocket::OnAccept(int nErrorCode )
{
	CSocket::OnAccept(nErrorCode);
	clientsocket = new CTCPClientSocket(this);
	this->Accept(*clientsocket);
	POSITION pos = ClientList.GetHeadPosition();
	ClientList.InsertBefore(pos,clientsocket);
	if (serverevent != NULL)
		clientsocket->SetClientEvent(serverevent);
	if (serverevent != NULL)
		serverevent->OnAccept(this,nErrorCode);
}

//////////////////////////////////////////////////////////////////////



