; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiskWarnDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DiskWarn.h"

ClassCount=3
Class1=CDiskWarnApp
Class2=CDiskWarnDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DISKWARN_DIALOG
Resource4=IDR_TRAYMENU

[CLS:CDiskWarnApp]
Type=0
HeaderFile=DiskWarn.h
ImplementationFile=DiskWarn.cpp
Filter=N

[CLS:CDiskWarnDlg]
Type=0
HeaderFile=DiskWarnDlg.h
ImplementationFile=DiskWarnDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CMBSPACE

[CLS:CAboutDlg]
Type=0
HeaderFile=DiskWarnDlg.h
ImplementationFile=DiskWarnDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DISKWARN_DIALOG]
Type=1
Class=CDiskWarnDlg
ControlCount=7
Control1=IDC_DISKLIST,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CMBSPACE,combobox,1344340226
Control4=IDC_EDSPACE,edit,1350631552
Control5=IDC_BTSET,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BTEXIT,button,1342242816

[MNU:IDR_TRAYMENU]
Type=1
Class=?
Command1=ID_SHOW
CommandCount=1

