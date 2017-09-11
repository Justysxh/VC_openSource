; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAviCompressDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AviCompress.h"

ClassCount=3
Class1=CAviCompressApp
Class2=CAviCompressDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AVICOMPRESS_DIALOG

[CLS:CAviCompressApp]
Type=0
HeaderFile=AviCompress.h
ImplementationFile=AviCompress.cpp
Filter=N

[CLS:CAviCompressDlg]
Type=0
HeaderFile=AviCompressDlg.h
ImplementationFile=AviCompressDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAviCompressDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AviCompressDlg.h
ImplementationFile=AviCompressDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AVICOMPRESS_DIALOG]
Type=1
Class=CAviCompressDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SRCFile,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DSTFILE,edit,1350631552
Control7=IDC_SRCBROWN,button,1342242816
Control8=IDC_DSTBROWN,button,1342242816
Control9=IDC_COMPRESS,button,1342242816

