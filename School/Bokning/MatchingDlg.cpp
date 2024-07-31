// MatchingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bokning.h"
#include "MatchingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg dialog


CMatchingDlg::CMatchingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatchingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMatchingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMatchingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMatchingDlg)
	DDX_Control(pDX, IDC_LIST_PERSONS, m_Persons);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMatchingDlg, CDialog)
	//{{AFX_MSG_MAP(CMatchingDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PERSONS, OnDblclkListPersons)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg message handlers

void CMatchingDlg::SetMatchingList(List<CPerson> *matching)
{
	m_ListPersons=matching;
}

void CMatchingDlg::OnDblclkListPersons(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos;
	pos = m_Persons.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		m_Selected = m_Persons.GetItemData(m_Persons.GetNextSelectedItem(pos));
		OnOK();
	}
	*pResult = 0;
}

BOOL CMatchingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Selected=-1;

	DWORD dwStyle = m_Persons.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	m_Persons.SetExtendedStyle(dwStyle);

	m_Persons.InsertColumn(0,"Namn",NULL,125);
	m_Persons.InsertColumn(1,"Adress",NULL,75);
	m_Persons.InsertColumn(2,"Telefon",NULL,75);
	m_Persons.InsertColumn(3,"Kundnummer",NULL,75);
	
	char buffer[200];
	LVITEM lvi;
	lvi.mask =  LVIF_TEXT;
	lvi.iItem = 0;
	int id(0);

	for(int i=0;i<m_ListPersons->GetSize();i++)
	{
		m_Person=m_ListPersons->GetItem(i);
		m_Id=m_Person->GetId();

		lvi.iSubItem = 0;
		sprintf(buffer,"%s %s",m_Person->GetFirstName(),m_Person->GetLastName());
		lvi.pszText = buffer;
		m_Persons.InsertItem(&lvi);

		lvi.iSubItem = 1;
		lvi.pszText = m_Person->GetAddress();
		m_Persons.SetItem(&lvi);

		lvi.iSubItem = 2;
		lvi.pszText = m_Person->GetPhone();
		m_Persons.SetItem(&lvi);

		lvi.iSubItem = 3;
		lvi.pszText = m_Id->GetId();
		id = m_Persons.SetItem(&lvi);
		m_Persons.SetItemData(id-1,i);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}