; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetworkListDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetworkList.h"

ClassCount=3
Class1=CNetworkListApp
Class2=CNetworkListDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NETWORKLIST_DIALOG

[CLS:CNetworkListApp]
Type=0
HeaderFile=NetworkList.h
ImplementationFile=NetworkList.cpp
Filter=N

[CLS:CNetworkListDlg]
Type=0
HeaderFile=NetworkListDlg.h
ImplementationFile=NetworkListDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NetworkListDlg.h
ImplementationFile=NetworkListDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NETWORKLIST_DIALOG]
Type=1
Class=CNetworkListDlg
ControlCount=2
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_STATIC,static,1342308352

