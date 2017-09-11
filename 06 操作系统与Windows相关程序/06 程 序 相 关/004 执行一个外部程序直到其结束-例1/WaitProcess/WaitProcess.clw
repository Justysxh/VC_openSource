; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWaitProcessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WaitProcess.h"

ClassCount=4
Class1=CWaitProcessApp
Class2=CWaitProcessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WAITPROCESS_DIALOG

[CLS:CWaitProcessApp]
Type=0
HeaderFile=WaitProcess.h
ImplementationFile=WaitProcess.cpp
Filter=N

[CLS:CWaitProcessDlg]
Type=0
HeaderFile=WaitProcessDlg.h
ImplementationFile=WaitProcessDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=WaitProcessDlg.h
ImplementationFile=WaitProcessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WAITPROCESS_DIALOG]
Type=1
Class=CWaitProcessDlg
ControlCount=1
Control1=IDC_EXECUTE,button,1342275584

