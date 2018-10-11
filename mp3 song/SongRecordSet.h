#if !defined(AFX_SONGRECORDSET_H__5901B414_B9E6_4B45_8D4D_3B35650453D4__INCLUDED_)
#define AFX_SONGRECORDSET_H__5901B414_B9E6_4B45_8D4D_3B35650453D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SongRecordSet.h : header file
//
#include <afxdb.h>
/////////////////////////////////////////////////////////////////////////////
// CSongRecordSet recordset

class CSongRecordSet : public CRecordset
{
public:
	CSongRecordSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSongRecordSet)

// Field/Param Data
	//{{AFX_FIELD(CSongRecordSet, CRecordset)
	CString	m_Title;
	CString	m_Album;
	CString	m_Comment;
	CString	m_Genre;
	CString	m_Folder;
	CString	m_Year;
	CString	m_strFileName;
	CString	m_Artist;
	CString	m_Singer;
	CString	m_SingerSex;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSongRecordSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SONGRECORDSET_H__5901B414_B9E6_4B45_8D4D_3B35650453D4__INCLUDED_)
