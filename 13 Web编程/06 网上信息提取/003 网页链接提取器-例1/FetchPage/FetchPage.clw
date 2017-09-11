; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFetchPageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FetchPage.h"

ClassCount=3
Class1=CFetchPageApp
Class2=CFetchPageDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FETCHPAGE_DIALOG

[CLS:CFetchPageApp]
Type=0
HeaderFile=FetchPage.h
ImplementationFile=FetchPage.cpp
Filter=N

[CLS:CFetchPageDlg]
Type=0
HeaderFile=FetchPageDlg.h
ImplementationFile=FetchPageDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FetchPageDlg.h
ImplementationFile=FetchPageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FETCHPAGE_DIALOG]
Type=1
Class=CFetchPageDlg
ControlCount=3
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_LOOKUP,button,1342275584
Control3=IDC_CANCEL,button,1342275584

