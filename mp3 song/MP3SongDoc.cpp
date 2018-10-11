// MP3SongDoc.cpp : implementation of the CMP3SongDoc class
//

#include "stdafx.h"
#include "MP3Song.h"

#include "MP3SongDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMP3SongDoc

IMPLEMENT_DYNCREATE(CMP3SongDoc, CDocument)

BEGIN_MESSAGE_MAP(CMP3SongDoc, CDocument)
	//{{AFX_MSG_MAP(CMP3SongDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMP3SongDoc construction/destruction

CMP3SongDoc::CMP3SongDoc()
{
	// TODO: add one-time construction code here

}

CMP3SongDoc::~CMP3SongDoc()
{
}

BOOL CMP3SongDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMP3SongDoc serialization

void CMP3SongDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMP3SongDoc diagnostics

#ifdef _DEBUG
void CMP3SongDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMP3SongDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMP3SongDoc commands
