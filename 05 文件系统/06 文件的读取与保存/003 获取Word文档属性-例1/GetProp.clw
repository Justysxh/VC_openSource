; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetPropDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GetProp.h"

ClassCount=3
Class1=CGetPropApp
Class2=CGetPropDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GETPROP_DIALOG

[CLS:CGetPropApp]
Type=0
HeaderFile=GetProp.h
ImplementationFile=GetProp.cpp
Filter=N

[CLS:CGetPropDlg]
Type=0
HeaderFile=GetPropDlg.h
ImplementationFile=GetPropDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FILENAME

[CLS:CAboutDlg]
Type=0
HeaderFile=GetPropDlg.h
ImplementationFile=GetPropDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GETPROP_DIALOG]
Type=1
Class=CGetPropDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FILENAME,edit,1350631552
Control3=IDC_BROWN,button,1342242816
Control4=IDC_PROPERTY,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST,SysListView32,1350631425

