; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotqueryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "notquery.h"

ClassCount=3
Class1=CNotqueryApp
Class2=CNotqueryDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NOTQUERY_DIALOG

[CLS:CNotqueryApp]
Type=0
HeaderFile=notquery.h
ImplementationFile=notquery.cpp
Filter=N

[CLS:CNotqueryDlg]
Type=0
HeaderFile=notqueryDlg.h
ImplementationFile=notqueryDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=notqueryDlg.h
ImplementationFile=notqueryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NOTQUERY_DIALOG]
Type=1
Class=CNotqueryDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control7=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1342177280

