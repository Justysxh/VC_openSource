; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDeleteURLDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DeleteURL.h"

ClassCount=4
Class1=CDeleteURLApp
Class2=CDeleteURLDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DELETEURL_DIALOG

[CLS:CDeleteURLApp]
Type=0
HeaderFile=DeleteURL.h
ImplementationFile=DeleteURL.cpp
Filter=N

[CLS:CDeleteURLDlg]
Type=0
HeaderFile=DeleteURLDlg.h
ImplementationFile=DeleteURLDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DeleteURLDlg.h
ImplementationFile=DeleteURLDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DELETEURL_DIALOG]
Type=1
Class=CDeleteURLDlg
ControlCount=2
Control1=IDC_BTCLEAR,button,1342242816
Control2=IDC_BTEXIT,button,1342242816

