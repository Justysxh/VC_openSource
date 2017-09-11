; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCustomPopMenuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CustomPopMenu.h"

ClassCount=3
Class1=CCustomPopMenuApp
Class2=CCustomPopMenuDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_CUSTOMPOPMENU_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_POPUPMENU

[CLS:CCustomPopMenuApp]
Type=0
HeaderFile=CustomPopMenu.h
ImplementationFile=CustomPopMenu.cpp
Filter=N

[CLS:CCustomPopMenuDlg]
Type=0
HeaderFile=CustomPopMenuDlg.h
ImplementationFile=CustomPopMenuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM32771

[CLS:CAboutDlg]
Type=0
HeaderFile=CustomPopMenuDlg.h
ImplementationFile=CustomPopMenuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CUSTOMPOPMENU_DIALOG]
Type=1
Class=CCustomPopMenuDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[MNU:IDR_POPUPMENU]
Type=1
Class=?
Command1=ID_MENUITEM32771
Command2=ID_MENUITEM32772
Command3=ID_MENUITEM32773
Command4=ID_MENUITEM32775
Command5=ID_MENUITEM32776
Command6=ID_MENUITEM32777
Command7=ID_MENUITEM32778
CommandCount=7

