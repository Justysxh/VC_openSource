; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPreview
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "envelopprint.h"

ClassCount=4
Class1=CEnvelopprintApp
Class2=CEnvelopprintDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ENVELOPPRINT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CPreview
Resource4=IDD_DIAPREVIEW

[CLS:CEnvelopprintApp]
Type=0
HeaderFile=envelopprint.h
ImplementationFile=envelopprint.cpp
Filter=N

[CLS:CEnvelopprintDlg]
Type=0
HeaderFile=envelopprintDlg.h
ImplementationFile=envelopprintDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CEnvelopprintDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=envelopprintDlg.h
ImplementationFile=envelopprintDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ENVELOPPRINT_DIALOG]
Type=1
Class=CEnvelopprintDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTPRINT,button,1342242816
Control3=IDC_BUTPREVIEW,button,1342242816
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_LIST1,SysListView32,1350631813

[DLG:IDD_DIAPREVIEW]
Type=1
Class=CPreview
ControlCount=0

[CLS:CPreview]
Type=0
HeaderFile=Preview.h
ImplementationFile=Preview.cpp
BaseClass=CDialog
Filter=D
LastObject=CPreview
VirtualFilter=dWC

