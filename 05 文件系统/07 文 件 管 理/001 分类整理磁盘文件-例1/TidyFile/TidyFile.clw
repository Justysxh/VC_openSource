; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTidyFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TidyFile.h"

ClassCount=3
Class1=CTidyFileApp
Class2=CTidyFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIDYFILE_DIALOG

[CLS:CTidyFileApp]
Type=0
HeaderFile=TidyFile.h
ImplementationFile=TidyFile.cpp
Filter=N

[CLS:CTidyFileDlg]
Type=0
HeaderFile=TidyFileDlg.h
ImplementationFile=TidyFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COFILEEXT

[CLS:CAboutDlg]
Type=0
HeaderFile=TidyFileDlg.h
ImplementationFile=TidyFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TIDYFILE_DIALOG]
Type=1
Class=CTidyFileDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDDIR,edit,1350631552
Control3=IDC_BTADD,button,1342242816
Control4=IDC_COFILEEXT,combobox,1344340226
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FILELIST,SysListView32,1350631425
Control7=IDC_BTSAVE,button,1342242816

