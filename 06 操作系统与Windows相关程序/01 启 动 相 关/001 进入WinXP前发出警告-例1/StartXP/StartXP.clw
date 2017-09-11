; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStartXPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StartXP.h"

ClassCount=4
Class1=CStartXPApp
Class2=CStartXPDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_STARTXP_DIALOG

[CLS:CStartXPApp]
Type=0
HeaderFile=StartXP.h
ImplementationFile=StartXP.cpp
Filter=N

[CLS:CStartXPDlg]
Type=0
HeaderFile=StartXPDlg.h
ImplementationFile=StartXPDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=StartXPDlg.h
ImplementationFile=StartXPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STARTXP_DIALOG]
Type=1
Class=CStartXPDlg
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BTADD,button,1342242816
Control3=IDC_BTMOVE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDTITLE,edit,1350631552
Control7=IDC_EDBODY,edit,1350631552

