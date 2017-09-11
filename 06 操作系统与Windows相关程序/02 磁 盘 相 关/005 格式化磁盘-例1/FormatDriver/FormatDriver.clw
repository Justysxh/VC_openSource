; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFormatDriverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FormatDriver.h"

ClassCount=3
Class1=CFormatDriverApp
Class2=CFormatDriverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FORMATDRIVER_DIALOG

[CLS:CFormatDriverApp]
Type=0
HeaderFile=FormatDriver.h
ImplementationFile=FormatDriver.cpp
Filter=N

[CLS:CFormatDriverDlg]
Type=0
HeaderFile=FormatDriverDlg.h
ImplementationFile=FormatDriverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DRIVER

[CLS:CAboutDlg]
Type=0
HeaderFile=FormatDriverDlg.h
ImplementationFile=FormatDriverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FORMATDRIVER_DIALOG]
Type=1
Class=CFormatDriverDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_DRIVER,combobox,1344340226
Control3=IDC_BTFORMAT,button,1342242816

