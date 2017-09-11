; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTrayPopMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TrayPopMenu.h"

ClassCount=3
Class1=CTrayPopMenuApp
Class2=CTrayPopMenuDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_TRAYMENU
Resource4=IDD_TRAYPOPMENU_DIALOG
Resource5=IDR_MAINMENU

[CLS:CTrayPopMenuApp]
Type=0
HeaderFile=TrayPopMenu.h
ImplementationFile=TrayPopMenu.cpp
Filter=N

[CLS:CTrayPopMenuDlg]
Type=0
HeaderFile=TrayPopMenuDlg.h
ImplementationFile=TrayPopMenuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEMEXIT

[CLS:CAboutDlg]
Type=0
HeaderFile=TrayPopMenuDlg.h
ImplementationFile=TrayPopMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TRAYPOPMENU_DIALOG]
Type=1
Class=CTrayPopMenuDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[MNU:IDR_TRAYMENU]
Type=1
Class=?
Command1=ID_MENUITEM32771
Command2=ID_MENUITEM32772
Command3=ID_MENUITEM32773
Command4=ID_MENUITEMEXIT
CommandCount=4

[MNU:IDR_MAINMENU]
Type=1
Class=?
CommandCount=0

