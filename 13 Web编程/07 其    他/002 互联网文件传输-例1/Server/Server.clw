; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerSock
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=4
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CServerSock
Resource3=IDD_SERVER_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_FILENAME,edit,1350631552
Control4=IDC_BROWSE,button,1342242816
Control5=IDC_PROGRESS,msctls_progress32,1350565888
Control6=IDC_SEND_FILE,button,1342242816
Control7=IDC_SEND_CANCEL,button,1342242816

[CLS:CServerSock]
Type=0
HeaderFile=ServerSock.h
ImplementationFile=ServerSock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

