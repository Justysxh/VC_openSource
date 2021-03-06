; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=4
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CClientSock
Resource3=IDD_CLIENT_DIALOG

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CANCELREC

[CLS:CAboutDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=10
Control1=IDC_STATIC,button,1342177287
Control2=IDC_FILERECPROGRESS,msctls_progress32,1350565888
Control3=IDC_CANCELREC,button,1476460544
Control4=IDC_EXIT,button,1342242816
Control5=IDC_CONNECT,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_SERVERIP,edit,1350631552
Control10=IDC_PORT,edit,1350639744

[CLS:CClientSock]
Type=0
HeaderFile=ClientSock.h
ImplementationFile=ClientSock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

