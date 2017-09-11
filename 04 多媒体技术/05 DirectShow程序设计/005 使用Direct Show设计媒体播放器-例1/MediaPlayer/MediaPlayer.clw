; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMediaPlayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MediaPlayer.h"

ClassCount=4
Class1=CMediaPlayerApp
Class2=CMediaPlayerDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIRECTSHOWEVENT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DISPLAYWND_DIALOG
Resource4=IDD_ABOUTBOX
Resource5=IDD_MEDIAPLAYER_DIALOG
Resource6=IDD_VIDEOSET_DIALOG

[CLS:CMediaPlayerApp]
Type=0
HeaderFile=MediaPlayer.h
ImplementationFile=MediaPlayer.cpp
Filter=N

[CLS:CMediaPlayerDlg]
Type=0
HeaderFile=MediaPlayerDlg.h
ImplementationFile=MediaPlayerDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=MediaPlayerDlg.h
ImplementationFile=MediaPlayerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MEDIAPLAYER_DIALOG]
Type=1
Class=CMediaPlayerDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIRECTSHOWEVENT_DIALOG]
Type=1
Class=?
ControlCount=19
Control1=IDCANCEL,button,1342242816
Control2=IDC_SETFILE,button,1342242816
Control3=IDC_SNAP,button,1342242816
Control4=IDC_FULLSCREEN,button,1342242816
Control5=IDC_MUTE,button,1342242816
Control6=IDC_VOLUMNMAX,button,1342242816
Control7=IDC_VOLUMNMIN,button,1342242816
Control8=IDC_PROCESSCTRL,msctls_trackbar32,1342242840
Control9=IDC_GRAY,button,1342242816
Control10=IDC_ADDSPEED,button,1342242816
Control11=IDC_ADDBACK,button,1342242816
Control12=IDC_VIDEOSET,button,1342242816
Control13=IDC_TB_PAUSE,button,1342242816
Control14=IDC_TB_STOP,button,1342242816
Control15=IDC_PROCESS,static,1342308352
Control16=IDC_CURPOS,static,1342308352
Control17=IDC_SHOWWND,button,1342242816
Control18=IDC_GROUPPOS,static,1342308352
Control19=IDC_CTLLIST,static,1342308352

[DLG:IDD_DISPLAYWND_DIALOG]
Type=1
Class=?
ControlCount=1
Control1=IDC_PANEL,static,1342181646

[DLG:IDD_VIDEOSET_DIALOG]
Type=1
Class=?
ControlCount=15
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_HUE,msctls_trackbar32,1342242833
Control7=IDC_SATURATION,msctls_trackbar32,1342242833
Control8=IDC_BRIGHTNESS,msctls_trackbar32,1342242833
Control9=IDC_CONTRAST,msctls_trackbar32,1342242833
Control10=IDC_HUENUM,edit,1350631552
Control11=IDC_SATNUM,edit,1350631552
Control12=IDC_BRIGHTNUM,edit,1350631552
Control13=IDC_CONTRASTNUM,edit,1350631552
Control14=IDC_DEFAULT,button,1342242816
Control15=IDC_TB_CANCEL,button,1342242816

