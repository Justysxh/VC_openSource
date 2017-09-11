; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CScreenProtectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ScreenProtect.h"

ClassCount=3
Class1=CScreenProtectApp
Class2=CScreenProtectDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SCREENPROTECT_DIALOG

[CLS:CScreenProtectApp]
Type=0
HeaderFile=ScreenProtect.h
ImplementationFile=ScreenProtect.cpp
Filter=N

[CLS:CScreenProtectDlg]
Type=0
HeaderFile=ScreenProtectDlg.h
ImplementationFile=ScreenProtectDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PICTURE

[CLS:CAboutDlg]
Type=0
HeaderFile=ScreenProtectDlg.h
ImplementationFile=ScreenProtectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SCREENPROTECT_DIALOG]
Type=1
Class=CScreenProtectDlg
ControlCount=1
Control1=IDC_PICTURE,static,1342177294

