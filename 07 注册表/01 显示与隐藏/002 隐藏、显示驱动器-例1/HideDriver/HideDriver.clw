; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHideDriverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HideDriver.h"

ClassCount=3
Class1=CHideDriverApp
Class2=CHideDriverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HIDEDRIVER_DIALOG

[CLS:CHideDriverApp]
Type=0
HeaderFile=HideDriver.h
ImplementationFile=HideDriver.cpp
Filter=N

[CLS:CHideDriverDlg]
Type=0
HeaderFile=HideDriverDlg.h
ImplementationFile=HideDriverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BTHIDE

[CLS:CAboutDlg]
Type=0
HeaderFile=HideDriverDlg.h
ImplementationFile=HideDriverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HIDEDRIVER_DIALOG]
Type=1
Class=CHideDriverDlg
ControlCount=2
Control1=IDC_BTHIDE,button,1342242816
Control2=IDC_BTSHOW,button,1342242816

