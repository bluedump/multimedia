#if !defined(AFX_QUERYDLG_H__DC3A59AB_2087_4A87_9D30_EC075905F6DD__INCLUDED_)
#define AFX_QUERYDLG_H__DC3A59AB_2087_4A87_9D30_EC075905F6DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog

class CQueryDlg : public CDialog
{
// Construction
public:
	CString& GetSql();
	CString m_SQL;
	CQueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryDlg)
	enum { IDD = IDD_QUERY };
	CString	m_strWhereValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddSql();
	afx_msg void OnRemoveSql();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__DC3A59AB_2087_4A87_9D30_EC075905F6DD__INCLUDED_)
