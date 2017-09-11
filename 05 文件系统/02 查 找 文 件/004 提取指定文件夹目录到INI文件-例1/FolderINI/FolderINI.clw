; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFolderINIDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FolderINI.h"

ClassCount=3
Class1=CFolderINIApp
Class2=CFolderINIDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FOLDERINI_DIALOG

[CLS:CFolderINIApp]
Type=0
HeaderFile=FolderINI.h
ImplementationFile=FolderINI.cpp
Filter=N

[CLS:CFolderINIDlg]
Type=0
HeaderFile=FolderINIDlg.h
ImplementationFile=FolderINIDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FolderINIDlg.h
ImplementationFile=FolderINIDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FOLDERINI_DIALOG]
Type=1
Class=CFolderINIDlg
ControlCount=3
Control1=IDC_BUTSELECT,button,1342242816
Control2=IDC_BUTDISTILL,button,1342242816
Control3=IDC_LIST1,listbox,1353777411

