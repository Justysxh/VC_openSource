; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHideStartMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HideStartMenu.h"

ClassCount=4
Class1=CHideStartMenuApp
Class2=CHideStartMenuDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HIDESTARTMENU_DIALOG

[CLS:CHideStartMenuApp]
Type=0
HeaderFile=HideStartMenu.h
ImplementationFile=HideStartMenu.cpp
Filter=N

[CLS:CHideStartMenuDlg]
Type=0
HeaderFile=HideStartMenuDlg.h
ImplementationFile=HideStartMenuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=HideStartMenuDlg.h
ImplementationFile=HideStartMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HIDESTARTMENU_DIALOG]
Type=1
Class=CHideStartMenuDlg
ControlCount=2
Control1=IDC_BTHIDE,button,1342242816
Control2=IDC_BTSHOW,button,1342242816

