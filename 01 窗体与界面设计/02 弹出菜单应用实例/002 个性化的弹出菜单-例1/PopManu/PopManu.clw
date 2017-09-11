; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPopManuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PopManu.h"

ClassCount=3
Class1=CPopManuApp
Class2=CPopManuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_POPMANU_DIALOG
Resource4=IDR_POPMENU

[CLS:CPopManuApp]
Type=0
HeaderFile=PopManu.h
ImplementationFile=PopManu.cpp
Filter=N

[CLS:CPopManuDlg]
Type=0
HeaderFile=PopManuDlg.h
ImplementationFile=PopManuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPopManuDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=PopManuDlg.h
ImplementationFile=PopManuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEMDESC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_POPMANU_DIALOG]
Type=1
Class=CPopManuDlg
ControlCount=1
Control1=IDC_LIST3,SysListView32,1350631425

[MNU:IDR_POPMENU]
Type=1
Class=?
Command1=ID_MENUITEMDESC
Command2=ID_MENUITEMASC
CommandCount=2

