; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShaddlg2
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Shadow.h"

ClassCount=5
Class1=CShadowApp
Class2=CShadowDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CShaddlg1
Resource4=IDD_SHADOW_DIALOG
Class5=CShaddlg2
Resource5=IDD_DIALOG2

[CLS:CShadowApp]
Type=0
HeaderFile=Shadow.h
ImplementationFile=Shadow.cpp
Filter=N

[CLS:CShadowDlg]
Type=0
HeaderFile=ShadowDlg.h
ImplementationFile=ShadowDlg.cpp
Filter=D
LastObject=CShadowDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ShadowDlg.h
ImplementationFile=ShadowDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHADOW_DIALOG]
Type=1
Class=CShadowDlg
ControlCount=0

[DLG:IDD_DIALOG1]
Type=1
Class=CShaddlg1
ControlCount=0

[CLS:CShaddlg1]
Type=0
HeaderFile=Shaddlg1.h
ImplementationFile=Shaddlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=CShaddlg1
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CShaddlg2
ControlCount=0

[CLS:CShaddlg2]
Type=0
HeaderFile=Shaddlg2.h
ImplementationFile=Shaddlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=CShaddlg2
VirtualFilter=dWC

