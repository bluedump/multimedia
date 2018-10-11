// LeftTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "LeftTreeView.h"
#include "SongRecordSet.h"
#include "RightListView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView

IMPLEMENT_DYNCREATE(CLeftTreeView, CTreeView)

CLeftTreeView::CLeftTreeView()
{
}

CLeftTreeView::~CLeftTreeView()
{
}


BEGIN_MESSAGE_MAP(CLeftTreeView, CTreeView)
	//{{AFX_MSG_MAP(CLeftTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView drawing

void CLeftTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView diagnostics

#ifdef _DEBUG
void CLeftTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView message handlers

void CLeftTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	::SetWindowLong(m_hWnd, GWL_STYLE, WS_VISIBLE | WS_CHILD | WS_TABSTOP
		| WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES);
	CTreeCtrl& treeCtrl = GetTreeCtrl();
	m_theImageList.Create(IDB_BITMAP, 32,1, RGB(0, 244, 0));
	treeCtrl.SetImageList(&m_theImageList, TVSIL_NORMAL);

	treeCtrl.SetBkColor(RGB(232, 233, 234));
	treeCtrl.InsertItem("歌手列表", 0, 1);

	CSongRecordSet db;

	try
	{
		if (db.IsOpen())
		{
			db.Close();
		}
		CString strSQL = "select * from songMP3";
		db.Open(CRecordset::snapshot, NULL, CRecordset::none);
		while (!db.IsEOF())
		{
			AddSingerToTree(db.m_Singer, db.m_SingerSex);
			m_strSinger = db.m_Singer;
			db.MoveNext();
		}
		db.Close();
	}
	catch(CDBException* e)
	{
		e->ReportError();
		return;
	}
	//::SetWindowLong(m_hWnd, )
}

void CLeftTreeView::AddSingerToTree(CString &strSinger, CString &strSex)
{
	CTreeCtrl& treeCtrl = GetTreeCtrl();

	BOOL sex;
	sex = (strSex.Find("女") ? 1 : 0);
	HTREEITEM hSingerItem = treeCtrl.GetRootItem();
	if (hSingerItem)
	{
		while (hSingerItem)
		{
			CString strItemText = treeCtrl.GetItemText(hSingerItem);
			if (strItemText == strSinger)
			{
				return;
			}
			hSingerItem = treeCtrl.GetNextSiblingItem(hSingerItem);
		}
	}
	if (sex)
	{
		treeCtrl.InsertItem(strSinger, 4, 5);
	}
	else
	{
		treeCtrl.InsertItem(strSinger, 2, 3);
	}
}

void CLeftTreeView::DeleteSinger()
{
	CTreeCtrl& treeCtrl = GetTreeCtrl();
	HTREEITEM hItem = treeCtrl.GetSelectedItem();
	if (NULL == hItem )
	{
		AfxMessageBox("请先选择歌手");
		return;
	}

	CString itemText = treeCtrl.GetItemText(hItem);
	if (itemText.Find("歌手列表") != -1)
	{
		AfxMessageBox("您选择的不是有效的歌手名");
		return;
	}
	CSongRecordSet db;
	try
	{
		if (db.IsOpen())
		{
			db.Close();
		}
		db.m_strFilter.Format("演唱='%s'", itemText);
		//	AfxMessageBox("ge");
		db.Open(CRecordset::snapshot, NULL, CRecordset::none);
		while (!db.IsEOF())
		{
			db.Delete();
			db.MoveNext();
		}
		//db.Update();
		db.Close();
	}
	catch (CDBException* e)
	{
		e->ReportError();
		return;
	}
	treeCtrl.DeleteItem(hItem);
	AfxMessageBox("删除歌手成功");
}

void CLeftTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	CTreeCtrl& treeCtrl = GetTreeCtrl();
	CString strItem = treeCtrl.GetItemText(hItem);

	CSplitterWnd* pLitter = (CSplitterWnd*)GetParent();
	CRightListView *pRightView =(CRightListView*) pLitter->GetPane(0, 1);
	CSongRecordSet db;
	CString sql;
	sql.Format("演唱='%s'", strItem);
	pRightView->AddList(db, sql);
	*pResult = 0;
}
