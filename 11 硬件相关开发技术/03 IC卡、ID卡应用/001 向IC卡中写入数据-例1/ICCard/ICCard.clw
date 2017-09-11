; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CICCardDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ICCard.h"

ClassCount=4
Class1=CICCardApp
Class2=CICCardDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CColorLabel
Resource3=IDD_ICCARD_DIALOG

[CLS:CICCardApp]
Type=0
HeaderFile=ICCard.h
ImplementationFile=ICCard.cpp
Filter=N

[CLS:CICCardDlg]
Type=0
HeaderFile=ICCardDlg.h
ImplementationFile=ICCardDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_HINT

[CLS:CAboutDlg]
Type=0
HeaderFile=ICCardDlg.h
ImplementationFile=ICCardDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ICCARD_DIALOG]
Type=1
Class=CICCardDlg
ControlCount=6
Control1=IDOK,button,1342275584
Control2=IDC_ICDATA,edit,1350631552
Control3=IDCANCEL,button,1342275584
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_HINT,static,1342308620

[CLS:CColorLabel]
Type=0
HeaderFile=ColorLabel.h
ImplementationFile=ColorLabel.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

