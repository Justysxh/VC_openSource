; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CParamExeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ParamExe.h"

ClassCount=4
Class1=CParamExeApp
Class2=CParamExeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PARAMEXE_DIALOG

[CLS:CParamExeApp]
Type=0
HeaderFile=ParamExe.h
ImplementationFile=ParamExe.cpp
Filter=N

[CLS:CParamExeDlg]
Type=0
HeaderFile=ParamExeDlg.h
ImplementationFile=ParamExeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ParamExeDlg.h
ImplementationFile=ParamExeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PARAMEXE_DIALOG]
Type=1
Class=CParamExeDlg
ControlCount=4
Control1=IDC_BACKUP,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_DETATCH,button,1342242816
Control4=IDC_STOPSERVER,button,1342242816

