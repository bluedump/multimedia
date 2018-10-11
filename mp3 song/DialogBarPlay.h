#if !defined(AFX_DIALOGBARPLAY_H__C9682D16_C3B8_48A2_A591_0C1FBAFBFF41__INCLUDED_)
#define AFX_DIALOGBARPLAY_H__C9682D16_C3B8_48A2_A591_0C1FBAFBFF41__INCLUDED_

#include "BTNST.H"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogBarPlay.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogBarPlay dialog

class CDialogBarPlay : public CDialogBar
{
// Construction
public:
	void Play(CString &strFullPath);
	CButtonST m_btnStop;
	CButtonST m_btnPause;
	CButtonST m_btnPlay;
	CButtonST m_btnOpen;
	LONG m_endPosition;
	LONG m_curPosition;
	int m_Volume;
	CString m_strPath;
	BOOL m_bPause;
	HWND m_hMp3;
	BOOL InitDialog();
	CDialogBarPlay(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogBarPlay)
	enum { IDD = IDD_PLAY_BAR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogBarPlay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogBarPlay)
	afx_msg void OnPaly();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBARPLAY_H__C9682D16_C3B8_48A2_A591_0C1FBAFBFF41__INCLUDED_)
