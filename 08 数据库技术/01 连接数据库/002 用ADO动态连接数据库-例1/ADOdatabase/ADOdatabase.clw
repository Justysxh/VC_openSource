; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CADOdatabaseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ADOdatabase.h"

ClassCount=3
Class1=CADOdatabaseApp
Class2=CADOdatabaseDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ADODATABASE_DIALOG

[CLS:CADOdatabaseApp]
Type=0
HeaderFile=ADOdatabase.h
ImplementationFile=ADOdatabase.cpp
Filter=N

[CLS:CADOdatabaseDlg]
Type=0
HeaderFile=ADOdatabaseDlg.h
ImplementationFile=ADOdatabaseDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ADOdatabaseDlg.h
ImplementationFile=ADOdatabaseDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADODATABASE_DIALOG]
Type=1
Class=CADOdatabaseDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTCONNECT,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LIST1,listbox,1353777411

