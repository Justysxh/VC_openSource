; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Login.h"

ClassCount=3
Class1=CLoginApp
Class2=CLoginDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LOGIN_DIALOG

[CLS:CLoginApp]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
Filter=N

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
Filter=D
LastObject=IDC_LIST1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631428
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631584
Control4=IDC_BUTTON,button,1342242816

