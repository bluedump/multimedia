// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__DFAC38A6_9504_4562_ABDD_0927273390E9__INCLUDED_)
#define AFX_MAINFRM_H__DFAC38A6_9504_4562_ABDD_0927273390E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SongRecordSet.h"
#include "DialogBarPlay.h"	// Added by ClassView
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CSplitterWnd m_wndSplitter;
	struct MP3_TAG_ID1 
	{
		char head[3];
		char title[30];
		char artist[30];
		char album[30];
		char year[4];
		char comment[30];
		char genre[1];
	}m_tagID1;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAddSinger();
	afx_msg void OnDelSinger();
	afx_msg void OnEditSong();
	afx_msg void OnDelSong();
	afx_msg void OnQuery();
	afx_msg void OnOpenSingle();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CDialogBarPlay m_wndPlayBar;
	CReBar m_wndReBar;
	CString m_strFN;
	void AddToDb(CSongRecordSet &db, MP3_TAG_ID1 &tagID1);
	void ReadTag(HANDLE hFile, DWORD fileSize,MP3_TAG_ID1 &tagID1, UINT uMethod);
	void BrowseDir(CString &strDir);
	BOOL m_bCheckCom;
	CString m_strComment;
	CString m_strSingerSex;
	CString m_strSinger;
	CString m_strPath;
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__DFAC38A6_9504_4562_ABDD_0927273390E9__INCLUDED_)
