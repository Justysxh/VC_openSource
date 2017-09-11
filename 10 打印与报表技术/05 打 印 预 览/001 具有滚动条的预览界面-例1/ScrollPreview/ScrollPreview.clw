; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPreviewDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ScrollPreview.h"

ClassCount=4
Class1=CScrollPreviewApp
Class2=CScrollPreviewDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SCROLLPREVIEW_DIALOG
Class4=CPreviewDialog
Resource4=IDD_PreviewDialog

[CLS:CScrollPreviewApp]
Type=0
HeaderFile=ScrollPreview.h
ImplementationFile=ScrollPreview.cpp
Filter=N

[CLS:CScrollPreviewDlg]
Type=0
HeaderFile=ScrollPreviewDlg.h
ImplementationFile=ScrollPreviewDlg.cpp
Filter=D
LastObject=IDC_BUTTON1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ScrollPreviewDlg.h
ImplementationFile=ScrollPreviewDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SCROLLPREVIEW_DIALOG]
Type=1
Class=CScrollPreviewDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

[CLS:CPreviewDialog]
Type=0
HeaderFile=PreviewDialog.h
ImplementationFile=PreviewDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CPreviewDialog
VirtualFilter=dWC

[DLG:IDD_PreviewDialog]
Type=1
Class=CPreviewDialog
ControlCount=0

