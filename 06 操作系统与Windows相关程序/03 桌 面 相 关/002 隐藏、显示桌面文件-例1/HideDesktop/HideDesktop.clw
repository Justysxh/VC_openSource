; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHideDesktopDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HideDesktop.h"

ClassCount=4
Class1=CHideDesktopApp
Class2=CHideDesktopDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HIDEDESKTOP_DIALOG

[CLS:CHideDesktopApp]
Type=0
HeaderFile=HideDesktop.h
ImplementationFile=HideDesktop.cpp
Filter=N

[CLS:CHideDesktopDlg]
Type=0
HeaderFile=HideDesktopDlg.h
ImplementationFile=HideDesktopDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=HideDesktopDlg.h
ImplementationFile=HideDesktopDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HIDEDESKTOP_DIALOG]
Type=1
Class=CHideDesktopDlg
ControlCount=2
Control1=IDC_BTHIDE,button,1342242816
Control2=IDC_BTSHOW,button,1342242816

