; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCutImageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CutImage.h"

ClassCount=3
Class1=CCutImageApp
Class2=CCutImageDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CUTIMAGE_DIALOG

[CLS:CCutImageApp]
Type=0
HeaderFile=CutImage.h
ImplementationFile=CutImage.cpp
Filter=N

[CLS:CCutImageDlg]
Type=0
HeaderFile=CutImageDlg.h
ImplementationFile=CutImageDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCutImageDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CutImageDlg.h
ImplementationFile=CutImageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CUTIMAGE_DIALOG]
Type=1
Class=CCutImageDlg
ControlCount=3
Control1=IDOK,button,1342275584
Control2=IDC_SOURCEIMAGE,static,1342181390
Control3=IDC_CUTIMAGE,static,1342177294

