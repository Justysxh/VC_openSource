; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAttachDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Attach.h"

ClassCount=3
Class1=CAttachApp
Class2=CAttachDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ATTACH_DIALOG

[CLS:CAttachApp]
Type=0
HeaderFile=Attach.h
ImplementationFile=Attach.cpp
Filter=N

[CLS:CAttachDlg]
Type=0
HeaderFile=AttachDlg.h
ImplementationFile=AttachDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=AttachDlg.h
ImplementationFile=AttachDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ATTACH_DIALOG]
Type=1
Class=CAttachDlg
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631813
Control5=IDC_BUTTON2,button,1342242816

