; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CScrollStatusDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ScrollStatus.h"

ClassCount=3
Class1=CScrollStatusApp
Class2=CScrollStatusDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SCROLLSTATUS_DIALOG
Resource4=IDR_MENU1

[CLS:CScrollStatusApp]
Type=0
HeaderFile=ScrollStatus.h
ImplementationFile=ScrollStatus.cpp
Filter=N

[CLS:CScrollStatusDlg]
Type=0
HeaderFile=ScrollStatusDlg.h
ImplementationFile=ScrollStatusDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ScrollStatusDlg.h
ImplementationFile=ScrollStatusDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SCROLLSTATUS_DIALOG]
Type=1
Class=CScrollStatusDlg
ControlCount=2
Control1=IDC_WEB,static,1342308352
Control2=IDC_PARENT,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
CommandCount=0

