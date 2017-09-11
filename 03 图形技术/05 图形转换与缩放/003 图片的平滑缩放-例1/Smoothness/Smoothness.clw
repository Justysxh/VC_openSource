; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSmoothnessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Smoothness.h"

ClassCount=4
Class1=CSmoothnessApp
Class2=CSmoothnessDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SMOOTHNESS_DIALOG
Class4=CFrameDlg
Resource4=IDD_DIALOGFRAME

[CLS:CSmoothnessApp]
Type=0
HeaderFile=Smoothness.h
ImplementationFile=Smoothness.cpp
Filter=N

[CLS:CSmoothnessDlg]
Type=0
HeaderFile=SmoothnessDlg.h
ImplementationFile=SmoothnessDlg.cpp
Filter=D
LastObject=IDC_SLIDER1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SmoothnessDlg.h
ImplementationFile=SmoothnessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SMOOTHNESS_DIALOG]
Type=1
Class=CSmoothnessDlg
ControlCount=6
Control1=IDC_BUTOPEN,button,1342242816
Control2=IDC_SLIDER1,msctls_trackbar32,1342242840
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BUTDRAW,button,1342242816
Control5=IDC_FRAME,static,1342177287
Control6=IDC_PICTURE,static,1342177294

[DLG:IDD_DIALOGFRAME]
Type=1
Class=CFrameDlg
ControlCount=0

[CLS:CFrameDlg]
Type=0
HeaderFile=FrameDlg.h
ImplementationFile=FrameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrameDlg
VirtualFilter=dWC

