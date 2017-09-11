; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRegSoftDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RegSoft.h"

ClassCount=3
Class1=CRegSoftApp
Class2=CRegSoftDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_REGSOFT_DIALOG

[CLS:CRegSoftApp]
Type=0
HeaderFile=RegSoft.h
ImplementationFile=RegSoft.cpp
Filter=N

[CLS:CRegSoftDlg]
Type=0
HeaderFile=RegSoftDlg.h
ImplementationFile=RegSoftDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SPARE

[CLS:CAboutDlg]
Type=0
HeaderFile=RegSoftDlg.h
ImplementationFile=RegSoftDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_REGSOFT_DIALOG]
Type=1
Class=CRegSoftDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDSET,edit,1350631552
Control3=IDC_BTSET,button,1342242816
Control4=IDC_SPARE,static,1342308352

