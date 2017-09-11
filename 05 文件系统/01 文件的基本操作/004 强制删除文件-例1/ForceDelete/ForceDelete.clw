; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CForceDeleteDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ForceDelete.h"

ClassCount=3
Class1=CForceDeleteApp
Class2=CForceDeleteDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FORCEDELETE_DIALOG

[CLS:CForceDeleteApp]
Type=0
HeaderFile=ForceDelete.h
ImplementationFile=ForceDelete.cpp
Filter=N

[CLS:CForceDeleteDlg]
Type=0
HeaderFile=ForceDeleteDlg.h
ImplementationFile=ForceDeleteDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BROWSE

[CLS:CAboutDlg]
Type=0
HeaderFile=ForceDeleteDlg.h
ImplementationFile=ForceDeleteDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FORCEDELETE_DIALOG]
Type=1
Class=CForceDeleteDlg
ControlCount=6
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FILENAME,edit,1350631552
Control5=IDC_BROWSE,button,1342242816
Control6=IDC_CLEAR,button,1342242816

