// RightListView.cpp : implementation file
//
#include "stdafx.h"
#include "MP3Song.h"
#include "RightListView.h"
#include "EditSong.h"
#include "MainFrm.h"
//#include <windows.h>
#include <vfw.h>
#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightListView

IMPLEMENT_DYNCREATE(CRightListView, CListView)

CRightListView::CRightListView()
{
}

CRightListView::~CRightListView()
{
}


BEGIN_MESSAGE_MAP(CRightListView, CListView)
	//{{AFX_MSG_MAP(CRightListView)
	ON_WM_LBUTTONDBLCLK()
	//ON_MESSAGE(MCIWNDM_NOTIFYMODE, OnMCINotify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightListView drawing

void CRightListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CRightListView diagnostics

#ifdef _DEBUG
void CRightListView::AssertValid() const
{
	CListView::AssertValid();
}

void CRightListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightListView message handlers

void CRightListView::AddList(CSongRecordSet &db, CString &strSql)
{
	CListCtrl& listCtrl = GetListCtrl();
	listCtrl.DeleteAllItems();
	try
	{
		if (db.IsOpen())
		{
			db.Close();
		}
		int mCur = 0;
		db.m_strFilter = strSql;
		db.Open(CRecordset::snapshot, NULL, CRecordset::none);
		while (!db.IsEOF())
		{
			AddItem(db, mCur, 0);
			++mCur;
			db.MoveNext();
		}
		db.Close();
	}
	catch (CDBException* e)
	{
		e->ReportError();
		return;
	}
}

void CRightListView::AddItem(CSongRecordSet &db, UINT mCur, UINT uMethod)
{
	CListCtrl& listCtrl = GetListCtrl();
	switch (uMethod)
	{
	case 0:
		{
			CString strFieldValue;
			listCtrl.InsertItem(mCur, strFieldValue);
			listCtrl.SetItemText(mCur, 0, db.m_strFileName);
			listCtrl.SetItemText(mCur, 1, db.m_Singer);
			listCtrl.SetItemText(mCur, 2, db.m_Album);
			listCtrl.SetItemText(mCur, 3, db.m_Title);
			listCtrl.SetItemText(mCur, 4, db.m_Comment);
			listCtrl.SetItemText(mCur, 5, db.m_Artist);
			listCtrl.SetItemText(mCur, 6, db.m_Year);
			listCtrl.SetItemText(mCur, 7, db.m_Genre);
			listCtrl.SetItemText(mCur, 8, db.m_Folder);
			listCtrl.SetItemText(mCur, 9, db.m_SingerSex);
			break;
		}
	
	}
}

void CRightListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	// TODO: Add your specialized code here and/or call the base class
	CListCtrl& ctl=GetListCtrl();
	// TODO: Add your specialized code here and/or call the base class	
	//�����б�ؼ����
	DWORD dwStyle=::GetWindowLong(m_hWnd,GWL_STYLE);
    dwStyle|=LVS_REPORT|LVS_SHOWSELALWAYS|LVS_EDITLABELS;	
	::SetWindowLong(m_hWnd,GWL_STYLE,dwStyle);
	dwStyle = ctl.GetExtendedStyle();
	//dwStyle=ctl.GetExtendedStyle();
	dwStyle|=LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT;
    //������չ���
	ctl.SetExtendedStyle(dwStyle);
	//	ctl.SetBkColor(RGB(232,232,232));
	//�б�ؼ�ͷ����
	TCHAR tittle[10][10] = {_T("�ļ���"),_T("�ݳ�"),_T("ר��"),_T("����"),
		_T("��ע"),_T("������"),_T("���"),_T("����"),_T("�ļ���"),_T("�Ա�")};	
	LV_COLUMN lvcolumn;
	CRect rect;
	GetWindowRect(&rect);	
	//����б�ؼ�ͷ
	for(int i=0;i<10;i++)
	{
		lvcolumn.mask =LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT 
			|LVCF_WIDTH|LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = tittle[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width()/6;
		GetListCtrl().InsertColumn(i, &lvcolumn);
	}
	m_mciWnd = NULL;
	
}

void CRightListView::EditSong()
{
	CListCtrl &listCtrl = GetListCtrl();
	POSITION nPos = listCtrl.GetFirstSelectedItemPosition();//�˺�������ѡ������ʱ����ȡ��һ��ѡ�е�
	if (NULL == nPos)
	{
		AfxMessageBox("��ѡ��Ҫ�༭�ĸ���!:)");
		return;
	}
	

//	CString strAlbum;
//	CString strTittle;
//	CString strComment;
	CString strFileName;
	CString strDir;
	while (nPos)
	{
		int nIndex = listCtrl.GetNextSelectedItem(nPos); //����nposָ������index,npos��ǰһ�����õ�npos�޸ĺ��ֵȻ��npos++
		strFileName = listCtrl.GetItemText(nIndex, 0);//���ڲ�ѯ���ݿ���Ӧ��¼
		strDir = listCtrl.GetItemText(nIndex, 8); //���ڲ�ѯ���ݿ�����Ӧ��¼
		
	//	strAlbum = listCtrl.GetItemText(nIndex, 2);
	//	strComment = listCtrl.GetItemText(nIndex, 4);
	//	strTittle = listCtrl.GetItemText(nIndex, 3);

		CEditSong editDlg;//�����ǽ�editDlg�ŵ�whileѭ���⻹��whileѭ���ڣ�
		editDlg.m_strEditAlbum = listCtrl.GetItemText(nIndex, 2);
		editDlg.m_strEditComment = listCtrl.GetItemText(nIndex, 4);
		editDlg.m_strEditTittle = listCtrl.GetItemText(nIndex, 3);
		//�����༭�Ի��򣬱༭������Ϣ
		if (IDOK != editDlg.DoModal())
		{
			return;
		}


		CSongRecordSet db;
		try
		{
			if (db.IsOpen())
			{
				db.Close();
			}
			db.m_strFilter.Format("�ļ���='%s' and �ļ���='%s'", strFileName, strDir); //m_strFilter�൱��SQL����е�where����
			db.Open(CRecordset::snapshot, NULL, CRecordset::none);
			if(!db.IsEOF())
			{
				//AfxMessageBox("1");
				db.Edit();
				db.m_Album = editDlg.m_strEditAlbum;
				db.m_Title = editDlg.m_strEditTittle;
				db.m_Comment = editDlg.m_strEditComment;
				//д�����ݿ��ͬʱ�����б�
				listCtrl.SetItemText(nIndex, 2, db.m_Album);
				listCtrl.SetItemText(nIndex, 3, db.m_Title);
				listCtrl.SetItemText(nIndex, 4, db.m_Comment);
			//	AfxMessageBox("2");
				//db.MoveNext();//����˴�ʹ��whileѭ���������쳣
			}
			if (db.CanUpdate())
			{
				db.Update();
			}	
			db.Close();
		}
		catch (CDBException* e)
		{
			e->ReportError();
		}
	
	}

}

void CRightListView::DeleteSong()
{
	CListCtrl &listCtr = GetListCtrl();
	POSITION pos = listCtr.GetFirstSelectedItemPosition();
	if (NULL == pos)
	{
		AfxMessageBox("��ѡ��Ҫɾ���ĸ���");
		return;
	}

	CString strFileName;
	CString strDir;
	while (pos)
	{
		int nIndex = listCtr.GetNextSelectedItem(pos);
		strFileName = listCtr.GetItemText(nIndex, 0);
		strDir = listCtr.GetItemText(nIndex, 8);
		CSongRecordSet db;
		try
		{
			if (db.IsOpen())
			{
				db.Close();
			}
			db.m_strFilter.Format("�ļ���='%s' and �ļ���='%s'", strFileName, strDir);
			db.Open(CRecordset::snapshot, NULL, CRecordset::none);
			while (!db.IsEOF())
			{
				db.Delete();
				listCtr.DeleteItem(nIndex);
				db.MoveNext();
			}
			db.Close();
		}
		catch (CDBException* e)
		{
			e->ReportError();
		}
	}
}

void CRightListView::OnMCINotify(WPARAM wParam, LPARAM lParam)
{
	/*
	switch (lParam)
	{
	case MCI_MODE_STOP:
		AfxMessageBox("OnMcinotify");
		m_mciWnd = NULL;
		break;
	default:
		break;
	}
	*/
}


void CRightListView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_mciWnd != NULL)
	{
		AfxMessageBox(_T("�Ѿ��и����ڲ�����"));
		return;
	}
//	m_mciWnd = NULL;
	CListCtrl &listCtr = GetListCtrl();
	
	POSITION pos = listCtr.GetFirstSelectedItemPosition();
	if (NULL == pos)
	{
		AfxMessageBox(_T("��ѡ�����"));
		return;
	}

	while (pos)
	{
		int nIndex = listCtr.GetNextSelectedItem(pos);
		CString strFileName = listCtr.GetItemText(nIndex, 0);
		CString strDir = listCtr.GetItemText(nIndex, 8);
		CString strFullPath = strDir + "\\" + strFileName + ".mp3";
		AfxMessageBox(strFullPath);
		CMainFrame *pMainFram = (CMainFrame*)AfxGetMainWnd();
		if (pMainFram->m_wndPlayBar.m_hMp3 != NULL)
		{
			MCIWndDestroy(pMainFram->m_wndPlayBar.m_hMp3);
			pMainFram->m_wndPlayBar.m_hMp3 = NULL;
		}
		pMainFram->m_wndPlayBar.Play(strFullPath);

	/*
		m_mciWnd = MCIWndCreate(GetSafeHwnd(), AfxGetInstanceHandle(), WS_CHILD | MCIWNDF_NOMENU |
			MCIWNDF_NOTIFYMODE, _T(strFullPath));
		
		if (m_mciWnd == NULL)
		{
			AfxMessageBox(_T("���������ļ����ִ���"));
			return;
		}
		if (MCIWndCanPlay(m_mciWnd))
		{
			MCIWndPlay(m_mciWnd);
		}
	//	MCIWndStop(mciWnd);
	//	AfxMessageBox("��������");
		
	*/
	}

	CListView::OnLButtonDblClk(nFlags, point);
}