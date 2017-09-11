; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSniffAppDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SniffApp.h"

ClassCount=3
Class1=CSniffAppApp
Class2=CSniffAppDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SNIFFAPP_DIALOG

[CLS:CSniffAppApp]
Type=0
HeaderFile=SniffApp.h
ImplementationFile=SniffApp.cpp
Filter=N

[CLS:CSniffAppDlg]
Type=0
HeaderFile=SniffAppDlg.h
ImplementationFile=SniffAppDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=SniffAppDlg.h
ImplementationFile=SniffAppDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SNIFFAPP_DIALOG]
Type=1
Class=CSniffAppDlg
ControlCount=3
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_BEGINLISTEN,button,1342275584
Control3=IDC_CANCEL,button,1342275584

