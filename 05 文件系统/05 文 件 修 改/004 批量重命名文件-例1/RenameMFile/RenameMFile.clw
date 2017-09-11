; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRenameMFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RenameMFile.h"

ClassCount=3
Class1=CRenameMFileApp
Class2=CRenameMFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_RENAMEMFILE_DIALOG

[CLS:CRenameMFileApp]
Type=0
HeaderFile=RenameMFile.h
ImplementationFile=RenameMFile.cpp
Filter=N

[CLS:CRenameMFileDlg]
Type=0
HeaderFile=RenameMFileDlg.h
ImplementationFile=RenameMFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FILELIST

[CLS:CAboutDlg]
Type=0
HeaderFile=RenameMFileDlg.h
ImplementationFile=RenameMFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RENAMEMFILE_DIALOG]
Type=1
Class=CRenameMFileDlg
ControlCount=4
Control1=IDC_FILELIST,SysListView32,1350631425
Control2=IDC_BTADDFILE,button,1342242816
Control3=IDC_BTRENAME,button,1342242816
Control4=IDC_EDNAME,edit,1350631552

