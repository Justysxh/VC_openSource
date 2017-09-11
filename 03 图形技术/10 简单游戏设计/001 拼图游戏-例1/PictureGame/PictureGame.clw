; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHelpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PictureGame.h"

ClassCount=4
Class1=CPictureGameApp
Class2=CPictureGameDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PICTUREGAME_DIALOG
Resource4=IDD_HELPDIALOG
Class4=CHelpDlg
Resource5=IDR_MENU1

[CLS:CPictureGameApp]
Type=0
HeaderFile=PictureGame.h
ImplementationFile=PictureGame.cpp
Filter=N

[CLS:CPictureGameDlg]
Type=0
HeaderFile=PictureGameDlg.h
ImplementationFile=PictureGameDlg.cpp
Filter=D
LastObject=ID_MENUEXIT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PictureGameDlg.h
ImplementationFile=PictureGameDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PICTUREGAME_DIALOG]
Type=1
Class=CPictureGameDlg
ControlCount=1
Control1=IDC_COMPART,static,1342177287

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUSTART
Command2=ID_MENUHELP
Command3=ID_MENUEASY
Command4=ID_MENUMID
Command5=ID_MENUHARD
Command6=ID_MENUEXIT
Command7=ID_MENUBMP1
Command8=ID_MENUBMP2
Command9=ID_MENUBMP3
Command10=ID_MENUCUSTOM
CommandCount=10

[DLG:IDD_HELPDIALOG]
Type=1
Class=CHelpDlg
ControlCount=1
Control1=IDC_STATICHELP,static,1342177287

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STATICHELP

