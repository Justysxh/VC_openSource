; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CODBCDSNDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ODBCDSN.h"

ClassCount=3
Class1=CODBCDSNApp
Class2=CODBCDSNDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ODBCDSN_DIALOG

[CLS:CODBCDSNApp]
Type=0
HeaderFile=ODBCDSN.h
ImplementationFile=ODBCDSN.cpp
Filter=N

[CLS:CODBCDSNDlg]
Type=0
HeaderFile=ODBCDSNDlg.h
ImplementationFile=ODBCDSNDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=ODBCDSNDlg.h
ImplementationFile=ODBCDSNDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ODBCDSN_DIALOG]
Type=1
Class=CODBCDSNDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631813

