; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIECaptionDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "IECaption.h"

ClassCount=4
Class1=CIECaptionApp
Class2=CIECaptionDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_IECAPTION_DIALOG

[CLS:CIECaptionApp]
Type=0
HeaderFile=IECaption.h
ImplementationFile=IECaption.cpp
Filter=N

[CLS:CIECaptionDlg]
Type=0
HeaderFile=IECaptionDlg.h
ImplementationFile=IECaptionDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=IECaptionDlg.h
ImplementationFile=IECaptionDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_IECAPTION_DIALOG]
Type=1
Class=CIECaptionDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDCAPTION,edit,1350631552
Control3=IDC_BTSET,button,1342242816
Control4=IDC_BTEXIT,button,1342242816

