; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMutexSynchDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MutexSynch.h"

ClassCount=3
Class1=CMutexSynchApp
Class2=CMutexSynchDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MUTEXSYNCH_DIALOG

[CLS:CMutexSynchApp]
Type=0
HeaderFile=MutexSynch.h
ImplementationFile=MutexSynch.cpp
Filter=N

[CLS:CMutexSynchDlg]
Type=0
HeaderFile=MutexSynchDlg.h
ImplementationFile=MutexSynchDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MUTEX

[CLS:CAboutDlg]
Type=0
HeaderFile=MutexSynchDlg.h
ImplementationFile=MutexSynchDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MUTEXSYNCH_DIALOG]
Type=1
Class=CMutexSynchDlg
ControlCount=4
Control1=IDC_RESULT,edit,1353781444
Control2=IDC_MUTEX,button,1342242819
Control3=IDC_BTSTARTONE,button,1342242816
Control4=IDC_BTSTARTTWO,button,1342242816

