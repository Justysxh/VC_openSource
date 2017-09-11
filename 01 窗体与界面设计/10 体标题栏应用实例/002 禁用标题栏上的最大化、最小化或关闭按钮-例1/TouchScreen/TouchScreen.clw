; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTouchScreenDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TouchScreen.h"

ClassCount=3
Class1=CTouchScreenApp
Class2=CTouchScreenDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TOUCHSCREEN_DIALOG

[CLS:CTouchScreenApp]
Type=0
HeaderFile=TouchScreen.h
ImplementationFile=TouchScreen.cpp
Filter=N

[CLS:CTouchScreenDlg]
Type=0
HeaderFile=TouchScreenDlg.h
ImplementationFile=TouchScreenDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STATICCENTER

[CLS:CAboutDlg]
Type=0
HeaderFile=TouchScreenDlg.h
ImplementationFile=TouchScreenDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TOUCHSCREEN_DIALOG]
Type=1
Class=CTouchScreenDlg
ControlCount=4
Control1=IDC_STATICCENTER,static,1342308608
Control2=IDC_STATIC,static,1342177294
Control3=IDC_CENTER,SysAnimate32,1342242816
Control4=IDC_WAZARD,SysAnimate32,1342242820

