#if !defined(AFX_ADDSINGERDLG_H__23060B10_D7B7_4770_B908_FAF98BB33B6A__INCLUDED_)
#define AFX_ADDSINGERDLG_H__23060B10_D7B7_4770_B908_FAF98BB33B6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSingerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSingerDlg dialog

class CAddSingerDlg : public CDialog
{
// Construction
public:
	CAddSingerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSingerDlg)
	enum { IDD = IDD_DLG_SINGER };
	BOOL	m_bCheckComment;
	CComboBox	m_strSingerSex;
	CString	m_strComment;
	CString	m_strDir;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSingerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSingerDlg)
	afx_msg void OnSelendokComboSex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSINGERDLG_H__23060B10_D7B7_4770_B908_FAF98BB33B6A__INCLUDED_)
