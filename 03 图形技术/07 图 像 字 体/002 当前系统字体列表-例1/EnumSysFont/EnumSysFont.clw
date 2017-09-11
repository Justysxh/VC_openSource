; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEnumSysFontDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EnumSysFont.h"

ClassCount=3
Class1=CEnumSysFontApp
Class2=CEnumSysFontDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ENUMSYSFONT_DIALOG

[CLS:CEnumSysFontApp]
Type=0
HeaderFile=EnumSysFont.h
ImplementationFile=EnumSysFont.cpp
Filter=N

[CLS:CEnumSysFontDlg]
Type=0
HeaderFile=EnumSysFontDlg.h
ImplementationFile=EnumSysFontDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FONTLIST

[CLS:CAboutDlg]
Type=0
HeaderFile=EnumSysFontDlg.h
ImplementationFile=EnumSysFontDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ENUMSYSFONT_DIALOG]
Type=1
Class=CEnumSysFontDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,button,1342177287
Control3=IDC_FONTLIST,combobox,1344340227
Control4=IDC_STATIC,static,1342308352
Control5=IDC_DEMO,static,1342177287

