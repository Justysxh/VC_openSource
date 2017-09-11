; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUseTabDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UseTab.h"

ClassCount=6
Class1=CUseTabApp
Class2=CUseTabDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG_EMP
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_CLI
Resource4=IDD_USETAB_DIALOG
Resource5=IDD_ABOUTBOX
Class4=CProvidedlg
Class5=CEmployee
Class6=CClient
Resource6=IDD_DIALOG_PRO

[CLS:CUseTabApp]
Type=0
HeaderFile=UseTab.h
ImplementationFile=UseTab.cpp
Filter=N

[CLS:CUseTabDlg]
Type=0
HeaderFile=UseTabDlg.h
ImplementationFile=UseTabDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=UseTabDlg.h
ImplementationFile=UseTabDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_USETAB_DIALOG]
Type=1
Class=CUseTabDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_DIALOG_EMP]
Type=1
Class=CEmployee
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552

[DLG:IDD_DIALOG_CLI]
Type=1
Class=CClient
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552

[DLG:IDD_DIALOG_PRO]
Type=1
Class=CProvidedlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552

[CLS:CProvidedlg]
Type=0
HeaderFile=Providedlg.h
ImplementationFile=Providedlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CEmployee]
Type=0
HeaderFile=Employee.h
ImplementationFile=Employee.cpp
BaseClass=CDialog
Filter=D

[CLS:CClient]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
BaseClass=CDialog
Filter=D

