; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShareMemDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShareMem.h"

ClassCount=3
Class1=CShareMemApp
Class2=CShareMemDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SHAREMEM_DIALOG

[CLS:CShareMemApp]
Type=0
HeaderFile=ShareMem.h
ImplementationFile=ShareMem.cpp
Filter=N

[CLS:CShareMemDlg]
Type=0
HeaderFile=ShareMemDlg.h
ImplementationFile=ShareMemDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CShareMemDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ShareMemDlg.h
ImplementationFile=ShareMemDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHAREMEM_DIALOG]
Type=1
Class=CShareMemDlg
ControlCount=5
Control1=IDC_WRITE,button,1342275584
Control2=IDC_READ,button,1342275584
Control3=IDC_WRITEEDIT,edit,1350631552
Control4=IDC_READEDIT,edit,1350631552
Control5=IDC_STATIC,button,1342177287

