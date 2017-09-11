; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDynamicCreateDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DynamicCreate.h"

ClassCount=3
Class1=CDynamicCreateApp
Class2=CDynamicCreateDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DYNAMICCREATE_DIALOG

[CLS:CDynamicCreateApp]
Type=0
HeaderFile=DynamicCreate.h
ImplementationFile=DynamicCreate.cpp
Filter=N

[CLS:CDynamicCreateDlg]
Type=0
HeaderFile=DynamicCreateDlg.h
ImplementationFile=DynamicCreateDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=DynamicCreateDlg.h
ImplementationFile=DynamicCreateDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DYNAMICCREATE_DIALOG]
Type=1
Class=CDynamicCreateDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

