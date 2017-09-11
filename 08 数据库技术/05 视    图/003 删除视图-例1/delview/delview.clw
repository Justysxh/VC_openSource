; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDelviewDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "delview.h"

ClassCount=3
Class1=CDelviewApp
Class2=CDelviewDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DELVIEW_DIALOG

[CLS:CDelviewApp]
Type=0
HeaderFile=delview.h
ImplementationFile=delview.cpp
Filter=N

[CLS:CDelviewDlg]
Type=0
HeaderFile=delviewDlg.h
ImplementationFile=delviewDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=delviewDlg.h
ImplementationFile=delviewDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DELVIEW_DIALOG]
Type=1
Class=CDelviewDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728835

