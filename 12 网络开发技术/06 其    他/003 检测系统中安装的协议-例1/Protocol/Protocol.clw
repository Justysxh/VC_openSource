; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProtocolDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Protocol.h"

ClassCount=3
Class1=CProtocolApp
Class2=CProtocolDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROTOCOL_DIALOG

[CLS:CProtocolApp]
Type=0
HeaderFile=Protocol.h
ImplementationFile=Protocol.cpp
Filter=N

[CLS:CProtocolDlg]
Type=0
HeaderFile=ProtocolDlg.h
ImplementationFile=ProtocolDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST2

[CLS:CAboutDlg]
Type=0
HeaderFile=ProtocolDlg.h
ImplementationFile=ProtocolDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROTOCOL_DIALOG]
Type=1
Class=CProtocolDlg
ControlCount=2
Control1=IDC_BUTENUMERATE,button,1342242816
Control2=IDC_LIST1,SysListView32,1350631813

