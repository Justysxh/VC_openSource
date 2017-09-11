; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CButtonGif
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GIFButton.h"

ClassCount=4
Class1=CGIFButtonApp
Class2=CGIFButtonDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CButtonGif
Resource3=IDD_GIFBUTTON_DIALOG

[CLS:CGIFButtonApp]
Type=0
HeaderFile=GIFButton.h
ImplementationFile=GIFButton.cpp
Filter=N

[CLS:CGIFButtonDlg]
Type=0
HeaderFile=GIFButtonDlg.h
ImplementationFile=GIFButtonDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GIFButtonDlg.h
ImplementationFile=GIFButtonDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GIFBUTTON_DIALOG]
Type=1
Class=CGIFButtonDlg
ControlCount=1
Control1=IDC_GIF,button,1342242827

[CLS:CButtonGif]
Type=0
HeaderFile=ButtonGif.h
ImplementationFile=ButtonGif.cpp
BaseClass=CButton
Filter=W
LastObject=CButtonGif
VirtualFilter=BWC

