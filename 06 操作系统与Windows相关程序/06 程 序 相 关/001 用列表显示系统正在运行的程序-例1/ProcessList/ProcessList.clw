; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProcessListDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProcessList.h"

ClassCount=3
Class1=CProcessListApp
Class2=CProcessListDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROCESSLIST_DIALOG

[CLS:CProcessListApp]
Type=0
HeaderFile=ProcessList.h
ImplementationFile=ProcessList.cpp
Filter=N

[CLS:CProcessListDlg]
Type=0
HeaderFile=ProcessListDlg.h
ImplementationFile=ProcessListDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CProcessListDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ProcessListDlg.h
ImplementationFile=ProcessListDlg.cpp
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

[DLG:IDD_PROCESSLIST_DIALOG]
Type=1
Class=CProcessListDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

