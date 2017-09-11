; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTreeTipDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TreeTip.h"

ClassCount=5
Class1=CTreeTipApp
Class2=CTreeTipDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=tipwnd
Class5=treetipedit
Resource3=IDD_TREETIP_DIALOG

[CLS:CTreeTipApp]
Type=0
HeaderFile=TreeTip.h
ImplementationFile=TreeTip.cpp
Filter=N

[CLS:CTreeTipDlg]
Type=0
HeaderFile=TreeTipDlg.h
ImplementationFile=TreeTipDlg.cpp
Filter=D
LastObject=IDC_EDSEP
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TreeTipDlg.h
ImplementationFile=TreeTipDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TREETIP_DIALOG]
Type=1
Class=CTreeTipDlg
ControlCount=4
Control1=IDC_EDSTR,edit,1350631552
Control2=IDC_SEPAR,static,1342308352
Control3=IDC_EDSEP,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:tipwnd]
Type=0
HeaderFile=tipwnd.h
ImplementationFile=tipwnd.cpp
BaseClass=CTreeCtrl
Filter=W
LastObject=tipwnd
VirtualFilter=GWC

[CLS:treetipedit]
Type=0
HeaderFile=tipwnd.h
ImplementationFile=tipwnd.cpp
BaseClass=CEdit
Filter=W
LastObject=treetipedit
VirtualFilter=WC

