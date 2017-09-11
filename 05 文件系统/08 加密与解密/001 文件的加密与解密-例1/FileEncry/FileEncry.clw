; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileEncryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileEncry.h"

ClassCount=3
Class1=CFileEncryApp
Class2=CFileEncryDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILEENCRY_DIALOG

[CLS:CFileEncryApp]
Type=0
HeaderFile=FileEncry.h
ImplementationFile=FileEncry.cpp
Filter=N

[CLS:CFileEncryDlg]
Type=0
HeaderFile=FileEncryDlg.h
ImplementationFile=FileEncryDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=FileEncryDlg.h
ImplementationFile=FileEncryDlg.cpp
Filter=D
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEENCRY_DIALOG]
Type=1
Class=CFileEncryDlg
ControlCount=5
Control1=IDC_EDBODY,edit,1353777348
Control2=IDC_BTOPEN,button,1342242816
Control3=IDC_BTENCRY,button,1342242816
Control4=IDC_BTUNENCRY,button,1342242816
Control5=IDC_FILEPATH,static,1342308352

