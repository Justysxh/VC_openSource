; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPreviewDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PagesPreview.h"

ClassCount=5
Class1=CPagesPreviewApp
Class2=CPagesPreviewDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_PreviewView
Resource2=IDR_MAINFRAME
Resource3=IDD_PREVIEW
Resource4=IDD_PAGESPREVIEW_DIALOG
Class4=CPreviewDialog
Resource5=IDD_ABOUTBOX
Class5=CPreView
Resource6=IDR_TOOLBAR1

[CLS:CPagesPreviewApp]
Type=0
HeaderFile=PagesPreview.h
ImplementationFile=PagesPreview.cpp
Filter=N

[CLS:CPagesPreviewDlg]
Type=0
HeaderFile=PagesPreviewDlg.h
ImplementationFile=PagesPreviewDlg.cpp
Filter=D
LastObject=CPagesPreviewDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PagesPreviewDlg.h
ImplementationFile=PagesPreviewDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PAGESPREVIEW_DIALOG]
Type=1
Class=CPagesPreviewDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_PRINTSETUP
Command2=ID_PAGESETUP
Command3=ID_FIRST
Command4=ID_NEXT
Command5=ID_ZOOMOUT
Command6=ID_ZOOMIN
Command7=ID_CLOSE
CommandCount=7

[DLG:IDD_PREVIEW]
Type=1
Class=CPreviewDialog
ControlCount=0

[CLS:CPreviewDialog]
Type=0
HeaderFile=PreviewDialog.h
ImplementationFile=PreviewDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPreviewDialog

[DLG:IDD_PreviewView]
Type=1
Class=CPreView
ControlCount=0

[CLS:CPreView]
Type=0
HeaderFile=PreView.h
ImplementationFile=PreView.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_ZOOMIN
VirtualFilter=dWC

