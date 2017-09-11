; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFetchDirDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FetchDir.h"

ClassCount=3
Class1=CFetchDirApp
Class2=CFetchDirDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FETCHDIR_DIALOG

[CLS:CFetchDirApp]
Type=0
HeaderFile=FetchDir.h
ImplementationFile=FetchDir.cpp
Filter=N

[CLS:CFetchDirDlg]
Type=0
HeaderFile=FetchDirDlg.h
ImplementationFile=FetchDirDlg.cpp
Filter=D
LastObject=IDC_LIST
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FetchDirDlg.h
ImplementationFile=FetchDirDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FETCHDIR_DIALOG]
Type=1
Class=CFetchDirDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_FETCH,button,1342242816
Control3=IDC_LIST,listbox,1352728833
Control4=IDC_SAVETOFILE,button,1342242816

