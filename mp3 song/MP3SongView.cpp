// MP3SongView.cpp : implementation of the CMP3SongView class
//

#include "stdafx.h"
#include "MP3Song.h"

#include "MP3SongDoc.h"
#include "MP3SongView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView

IMPLEMENT_DYNCREATE(CMP3SongView, CView)

BEGIN_MESSAGE_MAP(CMP3SongView, CView)
	//{{AFX_MSG_MAP(CMP3SongView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView construction/destruction

CMP3SongView::CMP3SongView()
{
	// TODO: add construction code here

}

CMP3SongView::~CMP3SongView()
{
}

BOOL CMP3SongView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView drawing

void CMP3SongView::OnDraw(CDC* pDC)
{
	CMP3SongDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView printing

BOOL CMP3SongView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMP3SongView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMP3SongView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView diagnostics

#ifdef _DEBUG
void CMP3SongView::AssertValid() const
{
	CView::AssertValid();
}

void CMP3SongView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMP3SongDoc* CMP3SongView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMP3SongDoc)));
	return (CMP3SongDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMP3SongView message handlers
