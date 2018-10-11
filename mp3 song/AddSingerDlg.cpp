// AddSingerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "AddSingerDlg.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSingerDlg dialog


CAddSingerDlg::CAddSingerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSingerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSingerDlg)
	m_bCheckComment = FALSE;
	//m_strSingerSex = _T("");
	m_strComment = _T("");
	m_strDir = _T("");
	//}}AFX_DATA_INIT
}


void CAddSingerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSingerDlg)
	DDX_Check(pDX, IDC_CHECK_COMMENT, m_bCheckComment);
	DDX_Control(pDX, IDC_COMBO_SEX, m_strSingerSex);
	DDX_Text(pDX, IDC_EDIT_COMMENT, m_strComment);
	DDX_Text(pDX, IDC_EDIT_DIR, m_strDir);
	//}}AFX_DATA_MAP
}

BOOL CAddSingerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_strSingerSex.AddString(_T("ÄÐ"));
	m_strSingerSex.AddString(_T("Å®"));
	m_strSingerSex.SetCurSel(0);
	CMainFrame* pMainFram = (CMainFrame*)AfxGetMainWnd();
	m_strSingerSex.GetLBText(m_strSingerSex.GetCurSel(),pMainFram->m_strSingerSex);
	return TRUE;
}
BEGIN_MESSAGE_MAP(CAddSingerDlg, CDialog)
	//{{AFX_MSG_MAP(CAddSingerDlg)
	ON_CBN_SELENDOK(IDC_COMBO_SEX, OnSelendokComboSex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSingerDlg message handlers

void CAddSingerDlg::OnSelendokComboSex() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFram = (CMainFrame*)AfxGetMainWnd();
	m_strSingerSex.GetLBText(m_strSingerSex.GetCurSel(), pMainFram->m_strSingerSex);
	
}
