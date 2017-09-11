; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBmpBKEditDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BmpBKEdit.h"

ClassCount=4
Class1=CBmpBKEditApp
Class2=CBmpBKEditDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CBmpEdit
Resource3=IDD_BMPBKEDIT_DIALOG

[CLS:CBmpBKEditApp]
Type=0
HeaderFile=BmpBKEdit.h
ImplementationFile=BmpBKEdit.cpp
Filter=N

[CLS:CBmpBKEditDlg]
Type=0
HeaderFile=BmpBKEditDlg.h
ImplementationFile=BmpBKEditDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=BmpBKEditDlg.h
ImplementationFile=BmpBKEditDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BMPBKEDIT_DIALOG]
Type=1
Class=CBmpBKEditDlg
ControlCount=1
Control1=IDC_EDIT1,edit,1350635652

[CLS:CBmpEdit]
Type=0
HeaderFile=BmpEdit.h
ImplementationFile=BmpEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

