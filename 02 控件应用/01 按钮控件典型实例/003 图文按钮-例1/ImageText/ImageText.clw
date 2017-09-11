; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageTextDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageText.h"

ClassCount=4
Class1=CImageTextApp
Class2=CImageTextDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=ImageButton
Resource3=IDD_IMAGETEXT_DIALOG

[CLS:CImageTextApp]
Type=0
HeaderFile=ImageText.h
ImplementationFile=ImageText.cpp
Filter=N

[CLS:CImageTextDlg]
Type=0
HeaderFile=ImageTextDlg.h
ImplementationFile=ImageTextDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CImageTextDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ImageTextDlg.h
ImplementationFile=ImageTextDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_IMAGETEXT_DIALOG]
Type=1
Class=CImageTextDlg
ControlCount=4
Control1=IDC_BUTTON1,button,1342242827
Control2=IDC_BUTTON2,button,1342242827
Control3=IDC_BUTTON3,button,1342242827
Control4=IDC_BUTTON4,button,1342242816

[CLS:ImageButton]
Type=0
HeaderFile=ImageButton.h
ImplementationFile=ImageButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

