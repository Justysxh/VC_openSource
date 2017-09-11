; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrintBarcodeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PrintBarcode.h"

ClassCount=3
Class1=CPrintBarcodeApp
Class2=CPrintBarcodeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PRINTBARCODE_DIALOG

[CLS:CPrintBarcodeApp]
Type=0
HeaderFile=PrintBarcode.h
ImplementationFile=PrintBarcode.cpp
Filter=N

[CLS:CPrintBarcodeDlg]
Type=0
HeaderFile=PrintBarcodeDlg.h
ImplementationFile=PrintBarcodeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BARCODE

[CLS:CAboutDlg]
Type=0
HeaderFile=PrintBarcodeDlg.h
ImplementationFile=PrintBarcodeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRINTBARCODE_DIALOG]
Type=1
Class=CPrintBarcodeDlg
ControlCount=6
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_PRINT,button,1342275584
Control3=IDC_BARCODE,{D9347033-9612-11D1-9D75-00C04FCC8CDC},1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CANCEL,button,1342275584

