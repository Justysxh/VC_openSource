; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DocViewPrint.h"
LastPage=0

ClassCount=6
Class1=CDocViewPrintApp
Class2=CDocViewPrintDoc
Class3=CDocViewPrintView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CMainDlg
Resource3=IDD_MAINDLG_DIALOG

[CLS:CDocViewPrintApp]
Type=0
HeaderFile=DocViewPrint.h
ImplementationFile=DocViewPrint.cpp
Filter=N

[CLS:CDocViewPrintDoc]
Type=0
HeaderFile=DocViewPrintDoc.h
ImplementationFile=DocViewPrintDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CDocViewPrintView]
Type=0
HeaderFile=DocViewPrintView.h
ImplementationFile=DocViewPrintView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=DocViewPrint.cpp
ImplementationFile=DocViewPrint.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_SETUP
Command3=ID_FILE_PRINT_PREVIEW
CommandCount=3

[DLG:IDD_MAINDLG_DIALOG]
Type=1
Class=CMainDlg
ControlCount=3
Control1=IDC_PRINT,button,1342275584
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_QUIT,button,1342275584

[CLS:CMainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainDlg

