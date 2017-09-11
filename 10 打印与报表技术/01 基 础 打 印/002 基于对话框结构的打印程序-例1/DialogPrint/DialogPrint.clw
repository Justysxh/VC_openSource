; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialogPrintDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DialogPrint.h"

ClassCount=4
Class1=CDialogPrintApp
Class2=CDialogPrintDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOGPRINT_DIALOG

[CLS:CDialogPrintApp]
Type=0
HeaderFile=DialogPrint.h
ImplementationFile=DialogPrint.cpp
Filter=N

[CLS:CDialogPrintDlg]
Type=0
HeaderFile=DialogPrintDlg.h
ImplementationFile=DialogPrintDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DialogPrintDlg.h
ImplementationFile=DialogPrintDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGPRINT_DIALOG]
Type=1
Class=CDialogPrintDlg
ControlCount=1
Control1=IDC_BUTPRINT,button,1342275584

