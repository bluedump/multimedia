// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MP3Song.h"
#include "AddSingerDlg.h"
#include "MainFrm.h"
#include "LeftTreeView.h"
#include "RightListView.h"
#include "GenreTab.h"
#include "QueryDlg.h"
#include "vfw.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ADD_SINGER, OnAddSinger)
	ON_COMMAND(ID_DEL_SINGER, OnDelSinger)
	ON_COMMAND(ID_EDIT_SONG, OnEditSong)
	ON_COMMAND(ID_DEL_SONG, OnDelSong)
	ON_COMMAND(ID_QUERY, OnQuery)
	ON_BN_CLICKED(IDC_OPEN_SINGLE, OnOpenSingle)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// create dialog bar
	if (!m_wndPlayBar.Create(this, IDD_PLAY_BAR, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR)||
		!m_wndPlayBar.InitDialog())
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndPlayBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}
	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle()|
		CBRS_TOOLTIPS | CBRS_FLYBY);
//	m_wndPlayBar.ShowWindow(true);
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnAddSinger() 
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("我爸是李刚"));
	TRACE0(_T("我爸是李刚"));
	LPBROWSEINFO lpbi = new BROWSEINFO;
	lpbi->hwndOwner = GetSafeHwnd();
	lpbi->pidlRoot = NULL;
	lpbi->pszDisplayName = NULL;
	lpbi->lpszTitle = "请选择演唱者目录:";
	lpbi->ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX;
	lpbi->lpfn = NULL;
	//显示外壳文件夹以便用户选择
	LPITEMIDLIST lpitemidlist = SHBrowseForFolder(lpbi);

	if (lpitemidlist == NULL)
	{
		delete lpbi;
		lpbi = NULL;
		return;
	}

	char path[MAX_PATH];
	SHGetPathFromIDList(lpitemidlist, path);
	delete lpbi;

	//添加歌手对话框
	CAddSingerDlg addSingerDlg;
	m_strPath.Format(_T("%s"), path);
	m_strSinger = m_strPath.Mid(m_strPath.ReverseFind('\\')+1);
	if (m_strSinger.IsEmpty())
	{
		AfxMessageBox(_T("不是有效的歌手"));
		return;
	}

	addSingerDlg.m_strDir = m_strSinger;
	if (addSingerDlg.DoModal() != IDOK)
	{
		return;
	}
	m_strComment = addSingerDlg.m_strComment;
	m_bCheckCom = addSingerDlg.m_bCheckComment;
	//添加树项
	CLeftTreeView* pLeftView = (CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	pLeftView->AddSingerToTree(m_strSinger, m_strSingerSex);

//	AfxMessageBox("browse");
	BrowseDir(m_strPath);
	CTreeCtrl& treeCtrl = pLeftView->GetTreeCtrl();
	treeCtrl.DeleteAllItems();
	treeCtrl.InsertItem("歌手列表", 0, 1);
	CSongRecordSet db;
	try
	{
		if (db.IsOpen())
		{
			db.Close();
		}
		db.Open(CRecordset::snapshot, NULL, CRecordset::none);
		while (!db.IsEOF())
		{
			pLeftView->AddSingerToTree(db.m_Singer, db.m_SingerSex);
			pLeftView->m_strSinger = db.m_Singer;
			db.MoveNext();
		}
		db.Close();
	}
	catch (CDBException* e)
	{
		e->ReportError();
	}

	AfxMessageBox("歌手更新完毕");
	//pLeftView->add
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		return FALSE;
	}
	
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftTreeView),CSize(150,150),pContext))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CRightListView),CSize(100,100),pContext))
		return FALSE;
		
//	return CFrameWnd::OnCreateClient(lpcs, pContext);
	return TRUE;
}

void CMainFrame::BrowseDir(CString &strDir)
{
	CFileFind cff;
	CString path = strDir;
	
	if (path.Right(1) != "\\")
	{
		path += "\\";
	}
	path += "*.*";
	BOOL findResult = cff.FindFile(path);
	CString strTemp;
			
	while (findResult)
	{
	//	AfxMessageBox("while");
		findResult = cff.FindNextFile();
		if (cff.IsDirectory() && !cff.IsDots())
		{
			m_strPath = cff.GetFilePath();
			BrowseDir(m_strPath);
		}
		else if (!cff.IsDirectory() && !cff.IsDots())
		{
			//AfxMessageBox(_T("读出所有的文件"));
		//	CString strTemp;
			
			strTemp.Format("%s",cff.GetFilePath());
			m_strFN.Format("%s", cff.GetFileName());
		//	AfxMessageBox("strTmp");
			if (strTemp.Right(3) == "mp3" || strTemp.Right(3) == "Mp3" ||
				strTemp.Right(3) == "MP3" || strTemp.Right(3) == "mP3")
			{
				HANDLE hFile = ::CreateFile(strTemp, GENERIC_READ, FILE_SHARE_READ, NULL,
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				DWORD fileSize = ::GetFileSize(hFile, NULL);
				ReadTag(hFile, fileSize, m_tagID1, 0);
				CSongRecordSet songDb;
				AddToDb(songDb, m_tagID1);
			}
		}
		strTemp = "";
	}
	cff.Close();
}

void CMainFrame::ReadTag(HANDLE hFile, DWORD fileSize, MP3_TAG_ID1 &tagID1, UINT uMethod)
{
//	AfxMessageBox("readtag");
	SetFilePointer(hFile, fileSize-128, NULL, FILE_BEGIN);
	DWORD dCount = 0;

	switch (uMethod)
	{
	case 0:
		dCount = 3;
		ReadFile(hFile, tagID1.head, dCount, &dCount, NULL);
		dCount = 30;
		ReadFile(hFile, tagID1.title, dCount, &dCount, NULL);
		ReadFile(hFile, tagID1.artist, dCount, &dCount, NULL);
		ReadFile(hFile, tagID1.album, dCount, &dCount, NULL);
		dCount = 4;
		ReadFile(hFile, tagID1.year, dCount, &dCount, NULL);
		dCount = 30;
		ReadFile(hFile, tagID1.comment, dCount, &dCount, NULL);
		dCount = 1;
	//	ReadFile(hFile, tagID1.reserve, dCount, &dCount, NULL);
	//	ReadFile(hFile, tagID1.track, dCount, &dCount, NULL);
		ReadFile(hFile, tagID1.genre, dCount, &dCount, NULL);
		break;
	case 1:
		dCount = 128;
		ReadFile(hFile, &tagID1, dCount, &dCount, NULL);
		break;
	default:
		break;
	}

}


void CMainFrame::AddToDb(CSongRecordSet &db, MP3_TAG_ID1 &tagID1)
{
//	AfxMessageBox("addtodb");
	try
	{
		if (db.IsOpen())
		{
			db.Close();
		}
		db.Open(CRecordset::snapshot, NULL, CRecordset::none);
		db.AddNew();
		CString strItem;
		strItem.Format("%s", tagID1.title);
		strItem.TrimLeft();
		strItem.TrimRight();
	
		db.m_Title = strItem;
		db.m_Artist = (LPCSTR)tagID1.artist;
		db.m_Album = (LPCSTR)tagID1.album;
		db.m_Year = (LPCSTR)tagID1.year;
		db.m_Comment = (LPCSTR)tagID1.comment;
	
		CString strGenre;
		strGenre.Format("%d",tagID1.genre[0]);
		int iGenreNum = atoi(strGenre);
		if (iGenreNum >= 0 && iGenreNum <=147)
		{
			db.m_Genre = (LPCSTR)genretab[iGenreNum];
		}
		else
		{
			db.m_Genre = (LPCSTR)genretab[148];
		}
	
		db.m_Folder = m_strPath;
		m_strFN = m_strFN.Left(m_strFN.GetLength()-4); //去掉扩展名

		db.m_strFileName = m_strFN;
	

		//备注歌手，性别
		
		if (m_bCheckCom)
		{
			db.m_Comment = m_strComment;
		}

		db.m_Singer = m_strSinger;

		db.m_SingerSex = m_strSingerSex;
		//最后将歌曲信息更新到数据库中
	
		if (db.CanUpdate())
		{
			db.Update();
		}
		
		db.Close();


	}
	catch (CDBException* e)
	{
		e->ReportError();
		return;
	}
	
}

void CMainFrame::OnDelSinger() 
{
	// TODO: Add your command handler code here
	CLeftTreeView* pLeftTreeview = (CLeftTreeView*)m_wndSplitter.GetPane(0, 0);
	pLeftTreeview->DeleteSinger();
}

void CMainFrame::OnEditSong() 
{
	// TODO: Add your command handler code here
	CRightListView *pRightView = (CRightListView*)m_wndSplitter.GetPane(0, 1);
	pRightView->EditSong();
}

void CMainFrame::OnDelSong() 
{
	// TODO: Add your command handler code here
	CRightListView* pRightView = (CRightListView*)m_wndSplitter.GetPane(0, 1);
	pRightView->DeleteSong();
}

void CMainFrame::OnQuery() 
{
	// TODO: Add your command handler code here
	CQueryDlg queryDlg;
	if (queryDlg.DoModal() != IDOK)
	{
		return;
	}
	CSongRecordSet db;
	CRightListView* pListView;
	pListView = (CRightListView*)m_wndSplitter.GetPane(0, 1);
	CString sql;
	sql = queryDlg.m_SQL;
	pListView->AddList(db, sql);
	
}

void CMainFrame::OnOpenSingle() 
{
	// TODO: Add your control notification handler code here
	if (m_wndPlayBar.m_hMp3 !=NULL)
	{
		MCIWndDestroy(m_wndPlayBar.m_hMp3);
		m_wndPlayBar.m_hMp3 = NULL;
	}
	CFileDialog mp3(TRUE, _T("mp3"), _T("*.mp3"), 
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("mp3 files (*.mp3)|*.mp3|all files (*.*)|*.*|"));
	if (mp3.DoModal() != IDOK)
	{
		return;
	}
	m_wndPlayBar.m_strPath = mp3.GetPathName();
	m_wndPlayBar.Play(m_wndPlayBar.m_strPath);
}

void CMainFrame::OnPlay() 
{
	// TODO: Add your control notification handler code here
	
}


void CMainFrame::OnPause() 
{
	// TODO: Add your control notification handler code here
	
}

void CMainFrame::OnStop() 
{
	// TODO: Add your control notification handler code here
	
}
