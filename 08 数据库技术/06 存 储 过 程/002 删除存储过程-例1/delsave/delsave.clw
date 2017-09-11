; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDelsaveDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "delsave.h"

ClassCount=3
Class1=CDelsaveApp
Class2=CDelsaveDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DELSAVE_DIALOG

[CLS:CDelsaveApp]
Type=0
HeaderFile=delsave.h
ImplementationFile=delsave.cpp
Filter=N

[CLS:CDelsaveDlg]
Type=0
HeaderFile=delsaveDlg.h
ImplementationFile=delsaveDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=delsaveDlg.h
ImplementationFile=delsaveDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DELSAVE_DIALOG]
Type=1
Class=CDelsaveDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342177287

