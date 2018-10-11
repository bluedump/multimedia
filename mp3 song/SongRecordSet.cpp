// SongRecordSet.cpp : implementation file
//

#include "stdafx.h"
#include "MP3Song.h"
#include "SongRecordSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSongRecordSet

IMPLEMENT_DYNAMIC(CSongRecordSet, CRecordset)

CSongRecordSet::CSongRecordSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSongRecordSet)
	m_Title = _T("");
	m_Album = _T("");
	m_Comment = _T("");
	m_Genre = _T("");
	m_Folder = _T("");
	m_Year = _T("");
	m_strFileName = _T("");
	m_Artist = _T("");
	m_Singer = _T("");
	m_SingerSex = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSongRecordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=songMp3");
}

CString CSongRecordSet::GetDefaultSQL()
{
	return _T("[songMp3]");
}

void CSongRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSongRecordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[����]"), m_Title);
	RFX_Text(pFX, _T("[ר��]"), m_Album);
	RFX_Text(pFX, _T("[��ע]"), m_Comment);
	RFX_Text(pFX, _T("[����]"), m_Genre);
	RFX_Text(pFX, _T("[�ļ���]"), m_Folder);
	RFX_Text(pFX, _T("[���]"), m_Year);
	RFX_Text(pFX, _T("[�ļ���]"), m_strFileName);
	RFX_Text(pFX, _T("[������]"), m_Artist);
	RFX_Text(pFX, _T("[�ݳ�]"), m_Singer);
	RFX_Text(pFX, _T("[�Ա�]"), m_SingerSex);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSongRecordSet diagnostics

#ifdef _DEBUG
void CSongRecordSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSongRecordSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
