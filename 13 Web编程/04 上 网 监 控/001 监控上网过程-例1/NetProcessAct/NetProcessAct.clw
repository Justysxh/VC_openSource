; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetProcessActDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetProcessAct.h"

ClassCount=3
Class1=CNetProcessActApp
Class2=CNetProcessActDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETPROCESSACT_DIALOG

[CLS:CNetProcessActApp]
Type=0
HeaderFile=NetProcessAct.h
ImplementationFile=NetProcessAct.cpp
Filter=N

[CLS:CNetProcessActDlg]
Type=0
HeaderFile=NetProcessActDlg.h
ImplementationFile=NetProcessActDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ACTLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=NetProcessActDlg.h
ImplementationFile=NetProcessActDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETPROCESSACT_DIALOG]
Type=1
Class=CNetProcessActDlg
ControlCount=3
Control1=IDC_ACTLIST,SysListView32,1350631425
Control2=IDC_BTENTER,button,1342242816
Control3=IDC_BTEXIT,button,1342242816

