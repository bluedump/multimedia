// MP3SongDoc.h : interface of the CMP3SongDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MP3SONGDOC_H__8E2D3944_BB4C_443F_AFB9_45309F5BE924__INCLUDED_)
#define AFX_MP3SONGDOC_H__8E2D3944_BB4C_443F_AFB9_45309F5BE924__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMP3SongDoc : public CDocument
{
protected: // create from serialization only
	CMP3SongDoc();
	DECLARE_DYNCREATE(CMP3SongDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3SongDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMP3SongDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMP3SongDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3SONGDOC_H__8E2D3944_BB4C_443F_AFB9_45309F5BE924__INCLUDED_)
