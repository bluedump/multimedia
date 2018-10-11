// MP3SongView.h : interface of the CMP3SongView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MP3SONGVIEW_H__641B37DB_B756_4F53_A46D_41107B20D716__INCLUDED_)
#define AFX_MP3SONGVIEW_H__641B37DB_B756_4F53_A46D_41107B20D716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMP3SongView : public CView
{
protected: // create from serialization only
	CMP3SongView();
	DECLARE_DYNCREATE(CMP3SongView)

// Attributes
public:
	CMP3SongDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3SongView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMP3SongView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMP3SongView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MP3SongView.cpp
inline CMP3SongDoc* CMP3SongView::GetDocument()
   { return (CMP3SongDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3SONGVIEW_H__641B37DB_B756_4F53_A46D_41107B20D716__INCLUDED_)
