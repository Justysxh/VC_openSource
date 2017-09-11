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
Class4=CMysocket
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
LastObject=CClientDlg

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
ControlCount=9
Control1=IDC_EDIT3,edit,1350631552
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTONJOIN,button,1342242816
Control8=IDC_LIST1,listbox,1352728835
Control9=IDC_BUTTONSEND,button,1342242816

[CLS:CMysocket]
Type=0
HeaderFile=Mysocket.h
ImplementationFile=Mysocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CMysocket

