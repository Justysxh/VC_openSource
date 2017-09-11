; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFloatMenu
LastTemplate=CToolBarCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FloatMenu.h"
LastPage=0

ClassCount=8
Class1=CFloatMenuApp
Class2=CFloatMenuDoc
Class3=CFloatMenuView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DIALOG1
Resource2=IDD_ABOUTBOX
Resource3=IDR_MENU1
Class5=CAboutDlg
Class6=CMyDock
Resource4=IDR_MAINFRAME
Class7=CFloatDlg
Resource5=IDR_FLOATMENU
Class8=CFloatMenu
Resource6=IDD_FLOATDLG_DIALOG

[CLS:CFloatMenuApp]
Type=0
HeaderFile=FloatMenu.h
ImplementationFile=FloatMenu.cpp
Filter=N

[CLS:CFloatMenuDoc]
Type=0
HeaderFile=FloatMenuDoc.h
ImplementationFile=FloatMenuDoc.cpp
Filter=N

[CLS:CFloatMenuView]
Type=0
HeaderFile=FloatMenuView.h
ImplementationFile=FloatMenuView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=D
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_BUTTON1




[CLS:CAboutDlg]
Type=0
HeaderFile=FloatMenu.cpp
ImplementationFile=FloatMenu.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

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

[TB:IDR_FLOATMENU]
Type=1
Class=?
Command1=ID_BUTTON1
Command2=ID_BUTTON32773
Command3=ID_BUTTON32774
Command4=ID_BUTTON32775
Command5=ID_BUTTON32782
CommandCount=5

[CLS:CMyDock]
Type=0
HeaderFile=MyDock.h
ImplementationFile=MyDock.cpp
BaseClass=CToolBarCtrl
Filter=W
LastObject=CMyDock

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=0

[DLG:IDD_FLOATDLG_DIALOG]
Type=1
Class=CFloatDlg
ControlCount=0

[CLS:CFloatDlg]
Type=0
HeaderFile=FloatDlg.h
ImplementationFile=FloatDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_BUTTON32776

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM32780111
Command2=ID_MENUITEM32781
Command3=ID_MENUITEM32778
Command4=ID_MENUITEM32779
CommandCount=4

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_BUTTON32776
CommandCount=9

[CLS:CFloatMenu]
Type=0
HeaderFile=FloatMenu1.h
ImplementationFile=FloatMenu1.cpp
BaseClass=CToolBar
Filter=W

