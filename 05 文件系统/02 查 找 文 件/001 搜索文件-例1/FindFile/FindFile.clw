; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFindFileDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FindFile.h"

ClassCount=3
Class1=CFindFileApp
Class2=CFindFileDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FINDFILE_DIALOG

[CLS:CFindFileApp]
Type=0
HeaderFile=FindFile.h
ImplementationFile=FindFile.cpp
Filter=N

[CLS:CFindFileDlg]
Type=0
HeaderFile=FindFileDlg.h
ImplementationFile=FindFileDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFindFileDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FindFileDlg.h
ImplementationFile=FindFileDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FINDFILE_DIALOG]
Type=1
Class=CFindFileDlg
ControlCount=9
Control1=IDC_CATA,static,1342308352
Control2=IDC_FILE,static,1342308352
Control3=IDC_EDADD,edit,1350631552
Control4=IDC_EDFILENAME,edit,1350631552
Control5=IDC_ADD,button,1342242816
Control6=IDC_FILELIST,listbox,1352728835
Control7=IDC_FIND,button,1342242816
Control8=IDC_BTSTOP,button,1342242816
Control9=IDC_CURFILENAME,static,1342308352

