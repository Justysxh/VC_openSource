; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMoveFIleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MoveFIle.h"

ClassCount=3
Class1=CMoveFIleApp
Class2=CMoveFIleDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MOVEFILE_DIALOG

[CLS:CMoveFIleApp]
Type=0
HeaderFile=MoveFIle.h
ImplementationFile=MoveFIle.cpp
Filter=N

[CLS:CMoveFIleDlg]
Type=0
HeaderFile=MoveFIleDlg.h
ImplementationFile=MoveFIleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMoveFIleDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MoveFIleDlg.h
ImplementationFile=MoveFIleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOVEFILE_DIALOG]
Type=1
Class=CMoveFIleDlg
ControlCount=3
Control1=IDC_FILELST,SysListView32,1350631425
Control2=IDC_BTADDFILE,button,1342242816
Control3=IDC_BTMOVE,button,1342242816

