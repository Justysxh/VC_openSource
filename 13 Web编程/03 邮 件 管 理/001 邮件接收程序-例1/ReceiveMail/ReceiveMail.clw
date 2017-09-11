; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReceiveMailDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ReceiveMail.h"

ClassCount=3
Class1=CReceiveMailApp
Class2=CReceiveMailDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RECEIVEMAIL_DIALOG

[CLS:CReceiveMailApp]
Type=0
HeaderFile=ReceiveMail.h
ImplementationFile=ReceiveMail.cpp
Filter=N

[CLS:CReceiveMailDlg]
Type=0
HeaderFile=ReceiveMailDlg.h
ImplementationFile=ReceiveMailDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_RECELST

[CLS:CAboutDlg]
Type=0
HeaderFile=ReceiveMailDlg.h
ImplementationFile=ReceiveMailDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RECEIVEMAIL_DIALOG]
Type=1
Class=CReceiveMailDlg
ControlCount=8
Control1=IDC_BTRECE,button,1342242816
Control2=IDC_POP,static,1342308352
Control3=IDC_EDPOP,edit,1350631552
Control4=IDC_USER,static,1342308352
Control5=IDC_EDUSER,edit,1350631552
Control6=IDC_PWD,static,1342308352
Control7=IDC_EDPWD,edit,1350631584
Control8=IDC_RECELST,SysListView32,1350631425

