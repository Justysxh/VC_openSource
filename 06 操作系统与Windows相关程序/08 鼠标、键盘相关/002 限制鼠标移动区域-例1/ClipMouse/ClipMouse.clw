; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClipMouseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ClipMouse.h"

ClassCount=3
Class1=CClipMouseApp
Class2=CClipMouseDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CLIPMOUSE_DIALOG

[CLS:CClipMouseApp]
Type=0
HeaderFile=ClipMouse.h
ImplementationFile=ClipMouse.cpp
Filter=N

[CLS:CClipMouseDlg]
Type=0
HeaderFile=ClipMouseDlg.h
ImplementationFile=ClipMouseDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BTCLIP

[CLS:CAboutDlg]
Type=0
HeaderFile=ClipMouseDlg.h
ImplementationFile=ClipMouseDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIPMOUSE_DIALOG]
Type=1
Class=CClipMouseDlg
ControlCount=2
Control1=IDC_BTCLIP,button,1342242816
Control2=IDC_BTRELEASE,button,1342242816

