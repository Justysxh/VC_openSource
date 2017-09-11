; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDriverAttriDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DriverAttri.h"

ClassCount=3
Class1=CDriverAttriApp
Class2=CDriverAttriDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DRIVERATTRI_DIALOG

[CLS:CDriverAttriApp]
Type=0
HeaderFile=DriverAttri.h
ImplementationFile=DriverAttri.cpp
Filter=N

[CLS:CDriverAttriDlg]
Type=0
HeaderFile=DriverAttriDlg.h
ImplementationFile=DriverAttriDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DRIVERCOMB

[CLS:CAboutDlg]
Type=0
HeaderFile=DriverAttriDlg.h
ImplementationFile=DriverAttriDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRIVERATTRI_DIALOG]
Type=1
Class=CDriverAttriDlg
ControlCount=4
Control1=IDC_DRIVERCOMB,combobox,1344340226
Control2=IDC_DRIVELIST,static,1342308352
Control3=IDC_DRIVERTYPE,static,1342308352
Control4=IDC_TYPE,static,1342308352

