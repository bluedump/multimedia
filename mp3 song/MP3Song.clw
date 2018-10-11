; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAddSingerDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MP3Song.h"
LastPage=0

ClassCount=12
Class1=CMP3SongApp
Class2=CMP3SongDoc
Class3=CMP3SongView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_EDIT_SONG
Resource2=IDD_PLAY_BAR
Class5=CAboutDlg
Class6=CAddSingerDlg
Resource3=IDD_ABOUTBOX
Resource4=IDR_MAINFRAME
Class7=CDialogBarPlay
Class8=CEditSong
Resource5=IDD_DLG_SINGER
Class9=CQueryDlg
Class10=CLeftTreeView
Class11=CRightListView
Class12=CSongRecordSet
Resource6=IDD_QUERY

[CLS:CMP3SongApp]
Type=0
HeaderFile=MP3Song.h
ImplementationFile=MP3Song.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMP3SongDoc]
Type=0
HeaderFile=MP3SongDoc.h
ImplementationFile=MP3SongDoc.cpp
Filter=N

[CLS:CMP3SongView]
Type=0
HeaderFile=MP3SongView.h
ImplementationFile=MP3SongView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MP3Song.cpp
ImplementationFile=MP3Song.cpp
Filter=D
LastObject=CAboutDlg

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
Command1=ID_QUERY
Command2=ID_APP_EXIT
Command3=ID_ADD_SINGER
Command4=ID_DEL_SINGER
Command5=ID_EDIT_SONG
Command6=ID_DEL_SONG
Command7=ID_APP_ABOUT
CommandCount=7

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
Command1=ID_APP_ABOUT
CommandCount=1

[DLG:IDD_DLG_SINGER]
Type=1
Class=CAddSingerDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_DIR,edit,1350631552
Control6=IDC_EDIT_COMMENT,edit,1350631556
Control7=IDC_COMBO_SEX,combobox,1344340226
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CHECK_COMMENT,button,1342242819

[CLS:CAddSingerDlg]
Type=0
HeaderFile=AddSingerDlg.h
ImplementationFile=AddSingerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddSingerDlg

[DLG:IDD_PLAY_BAR]
Type=1
Class=CDialogBarPlay
ControlCount=7
Control1=IDC_OPEN_SINGLE,button,1342242827
Control2=IDC_PLAY,button,1342242827
Control3=IDC_PAUSE,button,1342242827
Control4=IDC_STOP,button,1342242827
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SLIDER_VOLUM,msctls_trackbar32,1342242840
Control7=IDC_PLAY_PICTURE,static,1342177283

[CLS:CDialogBarPlay]
Type=0
HeaderFile=DialogBarPlay.h
ImplementationFile=DialogBarPlay.cpp
BaseClass=CDialogBar
Filter=D
LastObject=IDC_SLIDER_VOLUM
VirtualFilter=dWC

[DLG:IDD_EDIT_SONG]
Type=1
Class=CEditSong
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_ALBUM,edit,1350631552
Control7=IDC_EDIT_TITTLE,edit,1350631552
Control8=IDC_EDIT_COMMENT,edit,1350631552

[CLS:CEditSong]
Type=0
HeaderFile=EditSong.h
ImplementationFile=EditSong.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_QUERY]
Type=1
Class=CQueryDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FIELD_COMBO,combobox,1344340226
Control7=IDC_RELATION_COMBO,combobox,1344340226
Control8=IDC_FIELD_EDIT,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_SQL_LIST,listbox,1352728835
Control11=IDC_ADD_SQL,button,1342242816
Control12=IDC_REMOVE_SQL,button,1342242816

[CLS:CQueryDlg]
Type=0
HeaderFile=QueryDlg.h
ImplementationFile=QueryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SQL_LIST

[CLS:CLeftTreeView]
Type=0
HeaderFile=LeftTreeView.h
ImplementationFile=LeftTreeView.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=CLeftTreeView

[CLS:CRightListView]
Type=0
HeaderFile=RightListView.h
ImplementationFile=RightListView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=CRightListView

[CLS:CSongRecordSet]
Type=0
HeaderFile=SongRecordSet.h
ImplementationFile=SongRecordSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CSongRecordSet]
DB=1
DBType=ODBC
ColumnCount=11
Column1=[序号], 4, 4
Column2=[文件名], 12, 200
Column3=[演唱], 12, 100
Column4=[专辑], 12, 100
Column5=[标题], 12, 100
Column6=[备注], 12, 100
Column7=[艺术家], 12, 100
Column8=[年代], 12, 100
Column9=[流派], 12, 100
Column10=[文件夹], 12, 510
Column11=[性别], 12, 100

