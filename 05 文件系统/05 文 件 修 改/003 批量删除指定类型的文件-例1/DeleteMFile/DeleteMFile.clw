; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDeleteMFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DeleteMFile.h"

ClassCount=3
Class1=CDeleteMFileApp
Class2=CDeleteMFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DELETEMFILE_DIALOG

[CLS:CDeleteMFileApp]
Type=0
HeaderFile=DeleteMFile.h
ImplementationFile=DeleteMFile.cpp
Filter=N

[CLS:CDeleteMFileDlg]
Type=0
HeaderFile=DeleteMFileDlg.h
ImplementationFile=DeleteMFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FILELIST

[CLS:CAboutDlg]
Type=0
HeaderFile=DeleteMFileDlg.h
ImplementationFile=DeleteMFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DELETEMFILE_DIALOG]
Type=1
Class=CDeleteMFileDlg
ControlCount=3
Control1=IDC_FILELIST,SysListView32,1350631425
Control2=IDC_BTADDFILE,button,1342242816
Control3=IDC_BTDEL,button,1342242816

