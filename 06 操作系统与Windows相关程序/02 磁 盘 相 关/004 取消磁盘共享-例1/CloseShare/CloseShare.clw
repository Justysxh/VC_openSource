; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCloseShareDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CloseShare.h"

ClassCount=3
Class1=CCloseShareApp
Class2=CCloseShareDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CLOSESHARE_DIALOG

[CLS:CCloseShareApp]
Type=0
HeaderFile=CloseShare.h
ImplementationFile=CloseShare.cpp
Filter=N

[CLS:CCloseShareDlg]
Type=0
HeaderFile=CloseShareDlg.h
ImplementationFile=CloseShareDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CMBDRIVER

[CLS:CAboutDlg]
Type=0
HeaderFile=CloseShareDlg.h
ImplementationFile=CloseShareDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLOSESHARE_DIALOG]
Type=1
Class=CCloseShareDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CMBDRIVER,combobox,1344340227
Control3=IDC_BTCLOSE,button,1342242816

