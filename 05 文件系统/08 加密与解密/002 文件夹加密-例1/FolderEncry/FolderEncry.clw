; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFolderEncryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FolderEncry.h"

ClassCount=4
Class1=CFolderEncryApp
Class2=CFolderEncryDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FOLDERENCRY_DIALOG

[CLS:CFolderEncryApp]
Type=0
HeaderFile=FolderEncry.h
ImplementationFile=FolderEncry.cpp
Filter=N

[CLS:CFolderEncryDlg]
Type=0
HeaderFile=FolderEncryDlg.h
ImplementationFile=FolderEncryDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FolderEncryDlg.h
ImplementationFile=FolderEncryDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FOLDERENCRY_DIALOG]
Type=1
Class=CFolderEncryDlg
ControlCount=4
Control1=IDC_EDDIR,edit,1350631552
Control2=ID_ADD,button,1342242816
Control3=IDC_BTENCRY,button,1342242816
Control4=IDC_BTUNENCRY,button,1342242816

