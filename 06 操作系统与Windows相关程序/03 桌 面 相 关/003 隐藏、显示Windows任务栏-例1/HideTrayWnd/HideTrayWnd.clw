; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHideTrayWndDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HideTrayWnd.h"

ClassCount=3
Class1=CHideTrayWndApp
Class2=CHideTrayWndDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_HIDETRAYWND_DIALOG

[CLS:CHideTrayWndApp]
Type=0
HeaderFile=HideTrayWnd.h
ImplementationFile=HideTrayWnd.cpp
Filter=N

[CLS:CHideTrayWndDlg]
Type=0
HeaderFile=HideTrayWndDlg.h
ImplementationFile=HideTrayWndDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BTHIDE

[CLS:CAboutDlg]
Type=0
HeaderFile=HideTrayWndDlg.h
ImplementationFile=HideTrayWndDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HIDETRAYWND_DIALOG]
Type=1
Class=CHideTrayWndDlg
ControlCount=2
Control1=IDC_BTHIDE,button,1342242816
Control2=IDC_BTSHOW,button,1342242816

