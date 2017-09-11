; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProgressDlg
LastTemplate=CProgressCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Progress.h"

ClassCount=4
Class1=CProgressApp
Class2=CProgressDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CColorProgress
Resource3=IDD_PROGRESS_DIALOG

[CLS:CProgressApp]
Type=0
HeaderFile=Progress.h
ImplementationFile=Progress.cpp
Filter=N

[CLS:CProgressDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CProgressDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROGRESS_DIALOG]
Type=1
Class=CProgressDlg
ControlCount=1
Control1=IDC_PROGRESS1,msctls_progress32,1350565889

[CLS:CColorProgress]
Type=0
HeaderFile=ColorProgress.h
ImplementationFile=ColorProgress.cpp
BaseClass=CProgressCtrl
Filter=W
VirtualFilter=NWC

