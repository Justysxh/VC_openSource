; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUuuuDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "uuuu.h"

ClassCount=5
Class1=CUuuuApp
Class2=CUuuuDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CServerSocket
Class5=CClientSocket
Resource3=IDD_UUUU_DIALOG

[CLS:CUuuuApp]
Type=0
HeaderFile=uuuu.h
ImplementationFile=uuuu.cpp
Filter=N

[CLS:CUuuuDlg]
Type=0
HeaderFile=uuuuDlg.h
ImplementationFile=uuuuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=uuuuDlg.h
ImplementationFile=uuuuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_UUUU_DIALOG]
Type=1
Class=CUuuuDlg
ControlCount=5
Control1=IDOK,button,1342275584
Control2=IDCANCEL,button,1342275584
Control3=IDC_STATIC1,static,1342177294
Control4=IDC_BUTTON1,button,1342275584
Control5=IDC_EDIT1,edit,1350639744

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

