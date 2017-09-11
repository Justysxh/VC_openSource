; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImagesharpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Imagesharp.h"

ClassCount=3
Class1=CImagesharpApp
Class2=CImagesharpDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_IMAGESHARP_DIALOG

[CLS:CImagesharpApp]
Type=0
HeaderFile=Imagesharp.h
ImplementationFile=Imagesharp.cpp
Filter=N

[CLS:CImagesharpDlg]
Type=0
HeaderFile=ImagesharpDlg.h
ImplementationFile=ImagesharpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ImagesharpDlg.h
ImplementationFile=ImagesharpDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_IMAGESHARP_DIALOG]
Type=1
Class=CImagesharpDlg
ControlCount=3
Control1=IDC_IMAGE1,static,1342177294
Control2=IDC_SHARP,button,1342275584
Control3=IDC_CANCEL,button,1342275584

