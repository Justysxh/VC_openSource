; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInternetSetTimeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "InternetSetTime.h"

ClassCount=3
Class1=CInternetSetTimeApp
Class2=CInternetSetTimeDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_INTERNETSETTIME_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_TRAYMENU

[CLS:CInternetSetTimeApp]
Type=0
HeaderFile=InternetSetTime.h
ImplementationFile=InternetSetTime.cpp
Filter=N

[CLS:CInternetSetTimeDlg]
Type=0
HeaderFile=InternetSetTimeDlg.h
ImplementationFile=InternetSetTimeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CInternetSetTimeDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=InternetSetTimeDlg.h
ImplementationFile=InternetSetTimeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_INTERNETSETTIME_DIALOG]
Type=1
Class=CInternetSetTimeDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDADDRESS,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BTENTER,button,1342242816
Control7=IDC_BTEXIT,button,1342242816
Control8=IDC_CMBHOUR,combobox,1344340226
Control9=IDC_CMBMINU,combobox,1344340226

[MNU:IDR_TRAYMENU]
Type=1
Class=?
Command1=ID_SHOW
Command2=ID_EXIT
CommandCount=2

