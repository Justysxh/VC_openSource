; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLogin
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "kinescode.h"
LastPage=0

ClassCount=5
Class1=CKinescodeApp
Class2=CAboutDlg
Class3=CKinescodeDlg

ResourceCount=3
Resource1=IDD_KINESCODE_DIALOG
Class4=CClientSocket
Class5=CLogin
Resource2=IDD_ABOUTBOX
Resource3=IDD_LOGIN

[CLS:CKinescodeApp]
Type=0
BaseClass=CWinApp
HeaderFile=Kinescode.h
ImplementationFile=Kinescode.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=KinescodeDlg.cpp
ImplementationFile=KinescodeDlg.cpp

[CLS:CKinescodeDlg]
Type=0
BaseClass=CDialog
HeaderFile=KinescodeDlg.h
ImplementationFile=KinescodeDlg.cpp
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KINESCODE_DIALOG]
Type=1
Class=CKinescodeDlg
ControlCount=4
Control1=IDC_KINESCODE,button,1342275584
Control2=IDC_EXIT,button,1342275584
Control3=IDC_STOPKINESCODE,button,1342275584
Control4=IDC_LINKSERVER,button,1342275584

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_PORT

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=7
Control1=IDOK,button,1342275584
Control2=IDCANCEL,button,1342275584
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SERVERADDR,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PORT,edit,1350639744

