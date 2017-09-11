; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CResShareDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ResShare.h"

ClassCount=3
Class1=CResShareApp
Class2=CResShareDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RESSHARE_DIALOG

[CLS:CResShareApp]
Type=0
HeaderFile=ResShare.h
ImplementationFile=ResShare.cpp
Filter=N

[CLS:CResShareDlg]
Type=0
HeaderFile=ResShareDlg.h
ImplementationFile=ResShareDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ResShareDlg.h
ImplementationFile=ResShareDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RESSHARE_DIALOG]
Type=1
Class=CResShareDlg
ControlCount=1
Control1=IDC_TREE1,SysTreeView32,1350631431

