; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COvertimeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Overtime.h"

ClassCount=3
Class1=COvertimeApp
Class2=COvertimeDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_OVERTIME_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:COvertimeApp]
Type=0
HeaderFile=Overtime.h
ImplementationFile=Overtime.cpp
Filter=N

[CLS:COvertimeDlg]
Type=0
HeaderFile=OvertimeDlg.h
ImplementationFile=OvertimeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST2

[CLS:CAboutDlg]
Type=0
HeaderFile=OvertimeDlg.h
ImplementationFile=OvertimeDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_OVERTIME_DIALOG]
Type=1
Class=COvertimeDlg
ControlCount=6
Control1=IDC_BUTTONOK,button,1073807360
Control2=IDC_STATIC,static,1342177294
Control3=IDC_LIST1,SysListView32,1342242816
Control4=IDC_LIST2,SysListView32,1342242816
Control5=IDC_STATICTIME,static,1342308352
Control6=IDC_BUTCLOSE,button,1073807360

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUCLEAR
CommandCount=1

