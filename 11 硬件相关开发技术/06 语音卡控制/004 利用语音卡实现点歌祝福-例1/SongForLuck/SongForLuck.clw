; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSongForLuckDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SongForLuck.h"

ClassCount=3
Class1=CSongForLuckApp
Class2=CSongForLuckDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SONGFORLUCK_DIALOG

[CLS:CSongForLuckApp]
Type=0
HeaderFile=SongForLuck.h
ImplementationFile=SongForLuck.cpp
Filter=N

[CLS:CSongForLuckDlg]
Type=0
HeaderFile=SongForLuckDlg.h
ImplementationFile=SongForLuckDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SongForLuckDlg.h
ImplementationFile=SongForLuckDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SONGFORLUCK_DIALOG]
Type=1
Class=CSongForLuckDlg
ControlCount=2
Control1=IDC_STATIC,button,1342177287
Control2=IDC_LIST1,SysListView32,1350631425

