; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMp3FileStudioDlg
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mp3filestudio.h"
LastPage=0

ClassCount=12
Class1=CAutoFileName
Class2=CAutoTagEdit
Class3=CFileComboBox
Class4=CFileListView
Class5=CFileOrginizer
Class6=CMp3FileStudioApp
Class7=CAboutDlg
Class8=CMp3FileStudioDlg
Class9=CTagEdit

ResourceCount=10
Resource1=IDR_MAIN
Resource2=IDD_FILEORGINIZER
Resource3=IDD_AUTOTAGEDIT
Resource4=IDD_SETTINGS
Resource5=IDD_PROGRESS
Resource6=IDD_ABOUTBOX (English (U.S.))
Class10=Kalle
Resource7=IDD_TAGEDIT
Class11=CProgress
Resource8=IDD_AUTOFILENAME
Resource9=IDD_MP3FILESTUDIO (English (U.S.))
Class12=CSettings
Resource10=IDR_POPUP

[CLS:CAutoFileName]
Type=0
BaseClass=CPropertyPage
HeaderFile=AutoFileName.h
ImplementationFile=AutoFileName.cpp
Filter=D
VirtualFilter=idWC
LastObject=CAutoFileName

[CLS:CAutoTagEdit]
Type=0
BaseClass=CPropertyPage
HeaderFile=AutoTagEdit.h
ImplementationFile=AutoTagEdit.cpp
LastObject=CAutoTagEdit
Filter=D
VirtualFilter=idWC

[CLS:CFileComboBox]
Type=0
BaseClass=CComboBoxEx
HeaderFile=FileComboBox.h
ImplementationFile=FileComboBox.cpp

[CLS:CFileListView]
Type=0
BaseClass=CListCtrl
HeaderFile=FileListView.h
ImplementationFile=FileListView.cpp
Filter=W
VirtualFilter=FWC
LastObject=ID_EDIT_REMOVEID3TAG

[CLS:CFileOrginizer]
Type=0
BaseClass=CPropertyPage
HeaderFile=FileOrginizer.h
ImplementationFile=FileOrginizer.cpp
Filter=D
VirtualFilter=idWC
LastObject=CFileOrginizer

[CLS:CMp3FileStudioApp]
Type=0
BaseClass=CWinApp
HeaderFile=Mp3FileStudio.h
ImplementationFile=Mp3FileStudio.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Mp3FileStudioDlg.cpp
ImplementationFile=Mp3FileStudioDlg.cpp
LastObject=ID_FILE_SAVE
Filter=D
VirtualFilter=dWC

[CLS:CMp3FileStudioDlg]
Type=0
BaseClass=CDialog
HeaderFile=Mp3FileStudioDlg.h
ImplementationFile=Mp3FileStudioDlg.cpp
LastObject=CMp3FileStudioDlg
Filter=D
VirtualFilter=dWC

[CLS:CTagEdit]
Type=0
BaseClass=CPropertyPage
HeaderFile=TagEdit.h
ImplementationFile=TagEdit.cpp
LastObject=CTagEdit

[DLG:IDD_AUTOFILENAME]
Type=1
Class=CAutoFileName
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_FILENAME_EDIT_FILENAMELAYOUT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO_FILENAME_CURFILE,button,1342308361
Control7=IDC_RADIO_FILENAME_CURDIR,button,1342308361
Control8=IDC_RADIO_FILENAME_SUBDIR,button,1342308361
Control9=IDC_BUTTON_CREATEFILENAME,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_AUTOTAGEDIT]
Type=1
Class=CAutoTagEdit
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_TAG_EDIT_FILEFILTER,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_TAG_CHECK_ARTIST,button,1342242851
Control8=IDC_TAG_EDIT_ARTIST,edit,1484849280
Control9=IDC_STATIC,static,1342308352
Control10=IDC_TAG_CHECK_ALBUM,button,1342242851
Control11=IDC_TAG_EDIT_ALBUM,edit,1484849280
Control12=IDC_STATIC,static,1342308352
Control13=IDC_TAG_CHECK_YEAR,button,1342242851
Control14=IDC_TAG_EDIT_YEAR,edit,1484849280
Control15=IDC_STATIC,button,1342177287
Control16=IDC_RADIO_CURFILE,button,1342308361
Control17=IDC_RADIO_CURDIR,button,1342308361
Control18=IDC_RADIO_SUBDIR,button,1342308361
Control19=IDC_BUTTON_CREATETAG,button,1342242816
Control20=IDC_STATIC,button,1342177287

[DLG:IDD_FILEORGINIZER]
Type=1
Class=CFileOrginizer
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_FOLDERLAYOUT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO_ORGINIZER_CURFILE,button,1342308361
Control7=IDC_RADIO_ORGINIZER_CURDIR,button,1342308361
Control8=IDC_RADIO_ORGINIZER_SUBDIR,button,1342308361
Control9=IDC_BUTTON_ORGINIZEFILES,button,1476460544
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_FILEORGINIZER_PREVIEW,SysTreeView32,1350631459
Control13=IDC_FILEORGINIZER_TARGETDIR,edit,1350633600
Control14=IDC_STATIC,button,1342177287
Control15=IDC_FILEORGINIZER_BROWSE,button,1342242816
Control16=IDC_RADIO_COPY,button,1342308361
Control17=IDC_RADIO_MOVE,button,1342308361

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_MP3FILESTUDIO]
Type=1
Class=CMp3FileStudioDlg

[DLG:IDD_TAGEDIT]
Type=1
Class=CTagEdit
ControlCount=26
Control1=IDC_STATIC_TAGFRAME,button,1342177287
Control2=IDC_STATIC_ARTIST,static,1342308352
Control3=IDC_STATIC_ALBUM,static,1342308352
Control4=IDC_STATIC_YEAR,static,1342308352
Control5=IDC_STATIC_TITLE,static,1342308352
Control6=IDC_STATIC_GENRE,static,1342308352
Control7=IDC_STATIC_COMMENTS,static,1342308352
Control8=IDC_TITLE,edit,1350631552
Control9=IDC_ARTIST,edit,1350631552
Control10=IDC_ALBUM,edit,1350631552
Control11=IDC_YEAR,edit,1350631552
Control12=IDC_COMMENTS,edit,1350631552
Control13=IDC_GENRE,combobox,1344339971
Control14=IDC_STATIC_FILEINFO,button,1342177287
Control15=IDC_FILESIZE,static,1342308352
Control16=IDC_LENGTH,static,1342308352
Control17=IDC_MPEGVERSION,static,1342308352
Control18=IDC_BITRATE,static,1342308352
Control19=IDC_FREQUENCY,static,1342308352
Control20=IDC_CRC,static,1342308352
Control21=IDC_COPYRIGHT,static,1342308352
Control22=IDC_ORIGINAL,static,1342308352
Control23=IDC_EMPHASIS,static,1342308352
Control24=IDC_AUTOSAVE,button,1342242851
Control25=IDC_STATIC_TRACK,static,1342308352
Control26=IDC_TRACK,edit,1350631552

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287

[DLG:IDD_MP3FILESTUDIO (English (U.S.))]
Type=1
Class=?
ControlCount=5
Control1=IDC_DRIVEPICKER,ComboBoxEx32,1344340227
Control2=IDC_FILELIST,SysListView32,1350631503
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342177287
Control5=IDC_TEST,button,1073807360

[MNU:IDR_MAIN]
Type=1
Class=?
Command1=ID_FILE_SAVE
Command2=ID_APP_EXIT
Command3=ID_VIEW_LARGEICONS
Command4=ID_VIEW_LIST
Command5=ID_VIEW_DETAILS
Command6=ID_VIEW_REFRESH
Command7=ID_VIEW_ALWAYSONTOP
Command8=ID_HELP_ONLINE
Command9=ID_APP_HELP
Command10=ID_APP_ABOUT
CommandCount=10

[CLS:Kalle]
Type=0
HeaderFile=Kalle.h
ImplementationFile=Kalle.cpp
BaseClass=generic CWnd
Filter=W

[CLS:CProgress]
Type=0
HeaderFile=Progress.h
ImplementationFile=Progress.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HEADER
VirtualFilter=dWC

[DLG:IDD_PROGRESS]
Type=1
Class=CProgress
ControlCount=4
Control1=IDC_PROGRESS_TEXT,static,1342308352
Control2=IDC_STATIC,static,1342177283
Control3=IDC_PROGRESS_BAR,msctls_progress32,1350565889
Control4=IDC_HEADER,static,1342308352

[MNU:IDR_POPUP]
Type=1
Class=?
Command1=ID_EDIT_PLAY
Command2=ID_EDIT_COPY
Command3=ID_EDIT_CUT
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_DELETE
Command6=ID_EDIT_REMOVEID3TAG
Command7=ID_EDIT_CLEARID3TAG
Command8=ID_EDIT_PASTE
CommandCount=8

[DLG:IDD_SETTINGS]
Type=1
Class=CSettings
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_CHECK1,button,1073807363
Control3=IDC_MP3PLAYER,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_BROWSE_MP3PLAYER,button,1342242816

[CLS:CSettings]
Type=0
HeaderFile=Settings.h
ImplementationFile=Settings.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CSettings
VirtualFilter=idWC

