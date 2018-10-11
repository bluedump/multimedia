// EditSong.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "EditSong.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditSong dialog


CEditSong::CEditSong(CWnd* pParent /*=NULL*/)
	: CDialog(CEditSong::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditSong)
	m_strEditAlbum = _T("");
	m_strEditComment = _T("");
	m_strEditTittle = _T("");
	//}}AFX_DATA_INIT
}


void CEditSong::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditSong)
	DDX_Text(pDX, IDC_EDIT_ALBUM, m_strEditAlbum);
	DDV_MaxChars(pDX, m_strEditAlbum, 50);
	DDX_Text(pDX, IDC_EDIT_COMMENT, m_strEditComment);
	DDV_MaxChars(pDX, m_strEditComment, 50);
	DDX_Text(pDX, IDC_EDIT_TITTLE, m_strEditTittle);
	DDV_MaxChars(pDX, m_strEditTittle, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditSong, CDialog)
	//{{AFX_MSG_MAP(CEditSong)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditSong message handlers
