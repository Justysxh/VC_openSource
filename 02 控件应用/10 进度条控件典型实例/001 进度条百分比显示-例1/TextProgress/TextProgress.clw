; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextProgressDlg
LastTemplate=CProgressCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TextProgress.h"

ClassCount=4
Class1=CTextProgressApp
Class2=CTextProgressDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CTextProgress
Resource3=IDD_TEXTPROGRESS_DIALOG

[CLS:CTextProgressApp]
Type=0
HeaderFile=TextProgress.h
ImplementationFile=TextProgress.cpp
Filter=N

[CLS:CTextProgressDlg]
Type=0
HeaderFile=TextProgressDlg.h
ImplementationFile=TextProgressDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTextProgressDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TextProgressDlg.h
ImplementationFile=TextProgressDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEXTPROGRESS_DIALOG]
Type=1
Class=CTextProgressDlg
ControlCount=1
Control1=IDC_PROGRESS1,msctls_progress32,1350565889

[CLS:CTextProgress]
Type=0
HeaderFile=TextProgress1.h
ImplementationFile=TextProgress1.cpp
BaseClass=CProgressCtrl
Filter=W
VirtualFilter=NWC

