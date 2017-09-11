; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageConvertDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageConvert.h"

ClassCount=3
Class1=CImageConvertApp
Class2=CImageConvertDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_IMAGECONVERT_DIALOG

[CLS:CImageConvertApp]
Type=0
HeaderFile=ImageConvert.h
ImplementationFile=ImageConvert.cpp
Filter=N

[CLS:CImageConvertDlg]
Type=0
HeaderFile=ImageConvertDlg.h
ImplementationFile=ImageConvertDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_FILEDIR

[CLS:CAboutDlg]
Type=0
HeaderFile=ImageConvertDlg.h
ImplementationFile=ImageConvertDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_IMAGECONVERT_DIALOG]
Type=1
Class=CImageConvertDlg
ControlCount=11
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FILEDIR,edit,1350631552
Control5=IDC_BROWSE,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_BMPTOJPEG,button,1342177289
Control8=IDC_JPEGTOBMP,button,1342177289
Control9=IDC_BMPTOPNG,button,1342177289
Control10=IDC_PNGTOBMP,button,1342177289
Control11=IDC_TRANSFORM,button,1342242816

