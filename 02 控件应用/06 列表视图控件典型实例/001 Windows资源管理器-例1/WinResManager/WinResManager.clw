; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWinResManagerDlg
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WinResManager.h"

ClassCount=5
Class1=CWinResManagerApp
Class2=CWinResManagerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CFileListCtrl
Class4=CFileHeaderCtrl
Resource3=IDD_WINRESMANAGER_DIALOG

[CLS:CWinResManagerApp]
Type=0
HeaderFile=WinResManager.h
ImplementationFile=WinResManager.cpp
Filter=N

[CLS:CWinResManagerDlg]
Type=0
HeaderFile=WinResManagerDlg.h
ImplementationFile=WinResManagerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST

[CLS:CAboutDlg]
Type=0
HeaderFile=WinResManagerDlg.h
ImplementationFile=WinResManagerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WINRESMANAGER_DIALOG]
Type=1
Class=CWinResManagerDlg
ControlCount=2
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_FRAME,static,1342177287

[CLS:CFileHeaderCtrl]
Type=0
HeaderFile=FileHeaderCtrl.h
ImplementationFile=FileHeaderCtrl.cpp
BaseClass=CListCtrl
Filter=W

[CLS:CFileListCtrl]
Type=0
HeaderFile=FileListCtrl.h
ImplementationFile=FileListCtrl.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC

