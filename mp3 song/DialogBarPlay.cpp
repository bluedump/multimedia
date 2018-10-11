// DialogBarPlay.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "DialogBarPlay.h"
#include "RightListView.h"
#include "MainFrm.h"
#include "vfw.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#define TIMER_PLAYING 0
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogBarPlay dialog


CDialogBarPlay::CDialogBarPlay(CWnd* pParent /*=NULL*/)

{
	//{{AFX_DATA_INIT(CDialogBarPlay)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogBarPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogBarPlay)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogBarPlay, CDialogBar)
	//{{AFX_MSG_MAP(CDialogBarPlay)
	ON_BN_CLICKED(IDC_PLAY, OnPaly)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogBarPlay message handlers

BOOL CDialogBarPlay::InitDialog()
{
	CWnd* pPic=(CWnd*)GetDlgItem(IDC_PLAY_PICTURE);
	pPic->ShowWindow(SW_HIDE);
	//初始化个成员变量
	m_hMp3=NULL;
	m_bPause=FALSE;
	m_strPath="";
	m_Volume=500;
	m_curPosition=0;
	m_endPosition=0;
	//设置播放音量
	CSliderCtrl* pSlidCtrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER_VOLUM);
	//设置滑动条范围
	pSlidCtrl->SetRange(0,m_Volume*2,TRUE);
	//设置滑动条位置
	pSlidCtrl->SetPos(m_Volume);
	//子类化播放控制按钮
	m_btnOpen.SubclassDlgItem(IDC_OPEN_SINGLE, this);
   // m_btnOpen.SetIcon(IDI_OPEN, btst); 
//	m_btnOpen.o
	m_btnPlay.SubclassDlgItem(IDC_PLAY, this);
    m_btnPlay.SetIcon(IDI_PLAY); 
	m_btnPause.SubclassDlgItem(IDC_PAUSE, this);
    m_btnPause.SetIcon(IDI_PAUSE); 
	m_btnStop.SubclassDlgItem(IDC_STOP, this);
    m_btnStop.SetIcon(IDI_STOP); 
	//CButton *playButton = (CButton*)GetDlgItem(IDC_PLAY);
	//playButton->EnableWindow(false);
//	m_btnPlay.EnableWindow(true);
//	m_btnOpen.EnableAutomation();
	return TRUE;
}

void CDialogBarPlay::OnPaly() 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("onplay");
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	
//	CSplitterWnd spliter = pMain->m_wndSplitter;
	CRightListView* pRightView = (CRightListView*)pMain->m_wndSplitter.GetPane(0,1);
	CListCtrl &listCtrl = pRightView->GetListCtrl();
	POSITION pos = listCtrl.GetFirstSelectedItemPosition();
	
	if (NULL == pos)
	{
		AfxMessageBox(_T("请选择播放歌曲"));
	}
	while (pos)
	{
		int nIndex = listCtrl.GetNextSelectedItem(pos);
		CString strDir = listCtrl.GetItemText(nIndex, 8);
		CString strFileName = listCtrl.GetItemText(nIndex, 0);
	//	CString strDir = listCtr.GetItemText(nIndex, 8);
		CString strFullPath = strDir + "\\" + strFileName + ".mp3";
		if (pMain->m_wndPlayBar.m_hMp3 != NULL)
		{
			MCIWndDestroy(pMain->m_wndPlayBar.m_hMp3);
			pMain->m_wndPlayBar.m_hMp3 = NULL;
		}
		Play(strFullPath);
	//	AfxMessageBox(strPath);
	}
	
	
	
	AfxMessageBox("qinlei");
	
}

void CDialogBarPlay::OnPause() 
{
	// TODO: Add your control notification handler code here
	if(m_bPause)
	{
		//若先前处于暂停则继续播放
		MCIWndResume(m_hMp3);
		m_bPause= FALSE;
	}
	else
	{
		//否则，暂停
		MCIWndPause(m_hMp3);
		m_bPause= TRUE;
	}
	
}

void CDialogBarPlay::OnStop() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("onstop");
	MCIWndStop(m_hMp3);
//	Play(m_strPath);

	
}

void CDialogBarPlay::Play(CString &strFullPath)
{
	m_strPath = strFullPath;
	if (m_hMp3 == NULL)
	{
		m_hMp3 = MCIWndCreate(this->GetSafeHwnd(), AfxGetInstanceHandle(),
			WS_CHILD | WS_VISIBLE | MCIWNDF_NOTIFYMODE | MCIWNDF_NOPLAYBAR, m_strPath);
	}
	else
	{
		MCIWndHome(m_hMp3);
	}
	SetTimer(TIMER_PLAYING, 100, NULL);
	MCIWndSetVolume(m_hMp3, m_Volume);
	if (MCIWndPlay(m_hMp3))
	{
		AfxMessageBox("播放不成功");
		return;
	}
	CWnd* pPic = (CWnd*)GetDlgItem(IDC_PLAY_PICTURE);
	pPic->ShowWindow(SW_SHOW);
}

void CDialogBarPlay::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl* pSlidCtrl = (CSliderCtrl*)pScrollBar;
	m_Volume = pSlidCtrl->GetPos();
	if (m_hMp3 == NULL)
	{
		return;
	}
	MCIWndSetVolume(m_hMp3, m_Volume);
	CDialogBar::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDialogBarPlay::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case TIMER_PLAYING:
		{
			CWnd* pPic = (CWnd*)GetDlgItem(IDC_PLAY_PICTURE);
			m_curPosition = MCIWndGetPosition(m_hMp3);
			div_t div_pos;
			div_pos = div((int)m_curPosition, 2);
			if (div_pos.rem == 0)
			{
				pPic->ShowWindow(SW_SHOW);
			}
			else
			{
				pPic->ShowWindow(SW_HIDE);
			}
			if (m_curPosition == MCIWndGetLength(m_hMp3))
			{
				KillTimer(TIMER_PLAYING);
				CWnd* pPic = (CWnd*)GetDlgItem(IDC_PLAY_PICTURE);
				MCIWndDestroy(m_hMp3);
				pPic->ShowWindow(SW_HIDE);
				m_hMp3 = NULL;
			}
			break;
		}
	default:
		break;
	}
	CDialogBar::OnTimer(nIDEvent);
}
