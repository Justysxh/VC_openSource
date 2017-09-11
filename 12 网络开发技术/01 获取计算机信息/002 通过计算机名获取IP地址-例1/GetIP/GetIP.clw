; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetIPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GetIP.h"

ClassCount=3
Class1=CGetIPApp
Class2=CGetIPDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GETIP_DIALOG

[CLS:CGetIPApp]
Type=0
HeaderFile=GetIP.h
ImplementationFile=GetIP.cpp
Filter=N

[CLS:CGetIPDlg]
Type=0
HeaderFile=GetIPDlg.h
ImplementationFile=GetIPDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CGetIPDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=GetIPDlg.h
ImplementationFile=GetIPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GETIP_DIALOG]
Type=1
Class=CGetIPDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control5=IDC_BUTOK,button,1342242816
Control6=IDC_BUTEXIT,button,1342242816

