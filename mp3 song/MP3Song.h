// MP3Song.h : main header file for the MP3SONG application
//

#if !defined(AFX_MP3SONG_H__9D38E35A_F281_4A1B_A7F1_01810C3F17BA__INCLUDED_)
#define AFX_MP3SONG_H__9D38E35A_F281_4A1B_A7F1_01810C3F17BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMP3SongApp:
// See MP3Song.cpp for the implementation of this class
//

class CMP3SongApp : public CWinApp
{
public:
	CMP3SongApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3SongApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMP3SongApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP3SONG_H__9D38E35A_F281_4A1B_A7F1_01810C3F17BA__INCLUDED_)
