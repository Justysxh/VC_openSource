; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAVIButtonDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AVIButton.h"

ClassCount=4
Class1=CAVIButtonApp
Class2=CAVIButtonDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CButtonAvi
Resource3=IDD_AVIBUTTON_DIALOG

[CLS:CAVIButtonApp]
Type=0
HeaderFile=AVIButton.h
ImplementationFile=AVIButton.cpp
Filter=N

[CLS:CAVIButtonDlg]
Type=0
HeaderFile=AVIButtonDlg.h
ImplementationFile=AVIButtonDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTONAVI

[CLS:CAboutDlg]
Type=0
HeaderFile=AVIButtonDlg.h
ImplementationFile=AVIButtonDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AVIBUTTON_DIALOG]
Type=1
Class=CAVIButtonDlg
ControlCount=1
Control1=IDC_BUTTONAVI,button,1342242827

[CLS:CButtonAvi]
Type=0
HeaderFile=ButtonAvi.h
ImplementationFile=ButtonAvi.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CButtonAvi

