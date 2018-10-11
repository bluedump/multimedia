// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog
BOOL CQueryDlg::OnInitDialog()
{
	CComboBox *pFieldComBox = (CComboBox*)GetDlgItem(IDC_FIELD_COMBO);
	pFieldComBox->AddString(_T("文件名"));
	pFieldComBox->AddString(_T("演唱"));
	pFieldComBox->AddString(_T("标题"));
	pFieldComBox->AddString(_T("艺术家"));
	pFieldComBox->SetCurSel(0);
	
	CComboBox *pRelationComBox = (CComboBox*)GetDlgItem(IDC_RELATION_COMBO);
	pRelationComBox->AddString(_T("="));
	pRelationComBox->AddString(_T("like"));
	pRelationComBox->SetCurSel(0);
	m_SQL = "";
	return TRUE;
}

CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
	m_strWhereValue = _T("");
	//}}AFX_DATA_INIT
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Text(pDX, IDC_FIELD_EDIT, m_strWhereValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	ON_BN_CLICKED(IDC_ADD_SQL, OnAddSql)
	ON_BN_CLICKED(IDC_REMOVE_SQL, OnRemoveSql)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers

void CQueryDlg::OnAddSql() 
{
	// TODO: Add your control notification handler code here
	
	CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_FIELD_COMBO);
	CString strField;
	pCombox->GetLBText(pCombox->GetCurSel(), strField);
	
	pCombox = (CComboBox*)GetDlgItem(IDC_RELATION_COMBO);
	CString strRelation;
	pCombox->GetLBText(pCombox->GetCurSel(), strRelation);

	UpdateData(TRUE);

	if (!m_strWhereValue.Compare("") || m_strWhereValue.IsEmpty())
	{
		AfxMessageBox(_T("请检查条件字段"));
		return;
	}
	CString strSql;
	if (pCombox->GetCurSel() == 0)
	{
		strSql.Format("'%s'", m_strWhereValue);
		strSql = strField + strRelation + strSql;
	}
	else
	{
		char chTem = '%';
		strSql.Format("'%c%s%c'", chTem, m_strWhereValue, chTem);
		
		strSql = strField +" " +strRelation + " " +strSql;
	}
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_SQL_LIST);
	pListBox->AddString(strSql);

}

void CQueryDlg::OnRemoveSql() 
{
	// TODO: Add your control notification handler code here
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_SQL_LIST);
	int mIndex = -1;
	mIndex = pListBox->GetCurSel();
	if (mIndex < 0)
	{
		AfxMessageBox(_T("请先选择SQL语句"));
	}
	pListBox->DeleteString(mIndex);
}

void CQueryDlg::OnOK() 
{
	// TODO: Add extra validation here
	GetSql();
	CDialog::OnOK();
}

void CQueryDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

CString& CQueryDlg::GetSql()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_SQL_LIST);
	int mNumberSql;
	mNumberSql = pListBox->GetCount();
	CString strSqlText;
	CString strSqlTem;
	for (int i = 0; i < mNumberSql; ++i)
	{
		if (i < mNumberSql-1)
		{
			pListBox->GetText(i, strSqlTem);
			strSqlText.Format("%s and ", strSqlTem);
			m_SQL += strSqlText;
		}
		else
		{
			pListBox->GetText(i , strSqlTem);
			m_SQL += strSqlTem;
		}
	}
	return m_SQL;
}
