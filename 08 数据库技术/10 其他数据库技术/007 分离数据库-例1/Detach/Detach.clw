; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDetachDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Detach.h"

ClassCount=3
Class1=CDetachApp
Class2=CDetachDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DETACH_DIALOG

[CLS:CDetachApp]
Type=0
HeaderFile=Detach.h
ImplementationFile=Detach.cpp
Filter=N

[CLS:CDetachDlg]
Type=0
HeaderFile=DetachDlg.h
ImplementationFile=DetachDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=DetachDlg.h
ImplementationFile=DetachDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DETACH_DIALOG]
Type=1
Class=CDetachDlg
ControlCount=1
Control1=IDC_LIST1,listbox,1352728835

