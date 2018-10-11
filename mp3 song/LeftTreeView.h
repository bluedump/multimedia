#if !defined(AFX_LEFTTREEVIEW_H__A6D19BCE_6473_421A_BD43_C97520F684EF__INCLUDED_)
#define AFX_LEFTTREEVIEW_H__A6D19BCE_6473_421A_BD43_C97520F684EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftTreeView.h : header file
//
#include <afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView view

class CLeftTreeView : public CTreeView
{
protected:
	CLeftTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftTreeView)

// Attributes
public:

// Operations
public:
	void DeleteSinger();
	CString m_strSinger;
	CImageList m_theImageList;
	void AddSingerToTree(CString &strSinger, CString &strSex);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTREEVIEW_H__A6D19BCE_6473_421A_BD43_C97520F684EF__INCLUDED_)
