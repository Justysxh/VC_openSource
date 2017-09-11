; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBarcodeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "barcode.h"

ClassCount=3
Class1=CBarcodeApp
Class2=CBarcodeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_BARCODE_DIALOG

[CLS:CBarcodeApp]
Type=0
HeaderFile=barcode.h
ImplementationFile=barcode.cpp
Filter=N

[CLS:CBarcodeDlg]
Type=0
HeaderFile=barcodeDlg.h
ImplementationFile=barcodeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=barcodeDlg.h
ImplementationFile=barcodeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BARCODE_DIALOG]
Type=1
Class=CBarcodeDlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON3,button,1342242816
Control5=IDC_LIST1,SysListView32,1350631425

