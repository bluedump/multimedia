#if !defined(AFX_RIGHTLISTVIEW_H__B3B5F39D_D619_4AB0_ADC5_025392BE973C__INCLUDED_)
#define AFX_RIGHTLISTVIEW_H__B3B5F39D_D619_4AB0_ADC5_025392BE973C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightListView.h : header file
//
#include <afxcview.h>
#include "SongRecordSet.h"
/////////////////////////////////////////////////////////////////////////////
// CRightListView view

class CRightListView : public CListView
{
protected:
	CRightListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRightListView)

// Attributes
public:

// Operations
public:
	HWND m_mciWnd;
	void DeleteSong();
	void EditSong();
	void AddItem(CSongRecordSet &db, UINT mCur, UINT uMethod);
	void AddList(CSongRecordSet &db, CString &strSql);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRightListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRightListView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMCINotify(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTLISTVIEW_H__B3B5F39D_D619_4AB0_ADC5_025392BE973C__INCLUDED_)
