; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShutWindowDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShutWindow.h"

ClassCount=4
Class1=CShutWindowApp
Class2=CShutWindowDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SHUTWINDOW_DIALOG

[CLS:CShutWindowApp]
Type=0
HeaderFile=ShutWindow.h
ImplementationFile=ShutWindow.cpp
Filter=N

[CLS:CShutWindowDlg]
Type=0
HeaderFile=ShutWindowDlg.h
ImplementationFile=ShutWindowDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ShutWindowDlg.h
ImplementationFile=ShutWindowDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHUTWINDOW_DIALOG]
Type=1
Class=CShutWindowDlg
ControlCount=3
Control1=IDC_BTCLOSE,button,1342242816
Control2=IDC_BTRESET,button,1342242816
Control3=IDC_BTLOGOUT,button,1342242816

