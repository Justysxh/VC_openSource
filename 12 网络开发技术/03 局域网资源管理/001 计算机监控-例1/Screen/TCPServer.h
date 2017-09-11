// TCPServer.h: interface for the CTCPServer class.
//
//////////////////////////////////////////////////////////////////////
#include <afxcoll.h>
#include <afxsock.h>

#if !defined(AFX_TCPSERVER_H__4EBA8D8C_CC6E_4C73_808F_3FA7AE7F983D__INCLUDED_)
#define AFX_TCPSERVER_H__4EBA8D8C_CC6E_4C73_808F_3FA7AE7F983D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTCPClientEvent
{
public:
	virtual void OnClose(CSocket * socket, int nErrorCode );
	virtual void OnReceive(CSocket * socket, int nErrorCode );
};

class CTCPServerEvent:public CTCPClientEvent
{
public:
	virtual void OnAccept(CSocket * socket, int nErrorCode );
};

class CTCPServerSocket;
class CTCPClientSocket:public CSocket
{
private:
	CTCPClientEvent * clientevent;
	CTCPServerSocket *serversocket;
public:
	CTCPClientSocket(CTCPServerSocket *ServerSocket = NULL);
	void SetClientEvent(CTCPClientEvent * ClientEvent);
	virtual void OnClose(int nErrorCode );
	virtual void OnReceive(int nErrorCode );
};

class CTCPServerSocket:public CSocket
{
private:
	CTCPClientSocket *clientsocket;
	CTCPServerEvent *serverevent;
public:
	CPtrList ClientList;
public:
	CTCPServerSocket();

	void SetServerEvent(CTCPServerEvent *ServerEvent);
	virtual void OnAccept(int nErrorCode );
};

#endif // !defined(AFX_TCPSERVER_H__4EBA8D8C_CC6E_4C73_808F_3FA7AE7F983D__INCLUDED_)
