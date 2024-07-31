// Commercial.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Commercial.h"

#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommercial

IMPLEMENT_DYNCREATE(CCommercial, CFormView)

CCommercial::CCommercial()
	: CFormView(CCommercial::IDD)
{
	//{{AFX_DATA_INIT(CCommercial)
	m_Ability = 0;
	m_Age = 0;
	m_FinalSeason = 0;
	m_Royalty = 0;
	m_Salary = 0;
	//}}AFX_DATA_INIT
}

CCommercial::~CCommercial()
{
}

void CCommercial::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommercial)
	DDX_Control(pDX, IDC_SPIN_SALARY, m_Spin_Salary);
	DDX_Control(pDX, IDC_SPIN_ROYALTY, m_Spin_Royalty);
	DDX_Control(pDX, IDC_SPIN_FINALSEASON, m_Spin_FinalSeason);
	DDX_Control(pDX, IDC_SPIN_AGE, m_Spin_Age);
	DDX_Control(pDX, IDC_COMBO_TEAM, m_Team);
	DDX_Control(pDX, IDC_SPIN_ABILITY, m_Spin_Ability);
	DDX_Text(pDX, IDC_EDIT_ABILITY, m_Ability);
	DDV_MinMaxInt(pDX, m_Ability, 0, 5);
	DDX_Text(pDX, IDC_EDIT_AGE, m_Age);
	DDV_MinMaxInt(pDX, m_Age, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_FINALSEASON, m_FinalSeason);
	DDV_MinMaxInt(pDX, m_FinalSeason, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_ROYALTY, m_Royalty);
	DDV_MinMaxInt(pDX, m_Royalty, 0, 100);
	DDX_Text(pDX, IDC_EDIT_SALARY, m_Salary);
	DDV_MinMaxInt(pDX, m_Salary, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommercial, CFormView)
	//{{AFX_MSG_MAP(CCommercial)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommercial diagnostics

#ifdef _DEBUG
void CCommercial::AssertValid() const
{
	CFormView::AssertValid();
}

void CCommercial::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCommercial message handlers

void CCommercial::Load(int id, CString file)
{
CFile f;
int iData;
int iCom[21]={1,9,17,25,33,41,49,57,65,73,81,88,89,90,91,92,93,94,95,96,97};

	f.Open(file,CFile::modeRead,NULL);
	
	m_Id=id;
	f.Seek(97832+(3576*iCom[id]),CFile::begin);
	f.Read((char*)&iData,sizeof(int));//Team
	m_Team.SetCurSel(iData);
	f.Seek(8,CFile::current);
	f.Read((char*)&m_Salary,sizeof(int));//Salary
	f.Read((char*)&m_Age,sizeof(int));//Age
	f.Seek(8,CFile::current);
	f.Read((char*)&m_Royalty,sizeof(int));//Royalty
	f.Read((char*)&m_Ability,sizeof(int));//Ability
	f.Seek(132,CFile::current);
	f.Read((char*)&m_FinalSeason,sizeof(int));//Last Year

	f.Close();
	UpdateData(FALSE);
}

void CCommercial::FillBox()
{
CLoadText m_Text;

	m_Text.LoadText();
	for(int i=0;i<12;i++)
		m_Team.AddString(m_Text.m_Teams[i]);
}

void CCommercial::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	FillBox();
	SetSpin();
}

void CCommercial::SetSpin()
{
	m_Spin_Ability.SetRange(0,5);
	m_Spin_Age.SetRange(0,32000);
	m_Spin_FinalSeason.SetRange(0,32000);
	m_Spin_Royalty.SetRange(0,100);
	m_Spin_Salary.SetRange32(0,1000000000);
}

void CCommercial::SaveCommercial(CString file)
{
CFile f;
int iData;
int iCom[21]={1,9,17,25,33,41,49,57,65,73,81,88,89,90,91,92,93,94,95,96,97};
	
	UpdateData(TRUE);
	
	f.Open(file,CFile::modeWrite,NULL);
	
	f.Seek(97832+(3576*iCom[m_Id]),CFile::begin);
	iData=m_Team.GetCurSel();
	f.Write((char*)&iData,sizeof(int));//Team
	f.Seek(8,CFile::current);
	f.Write((char*)&m_Salary,sizeof(int));//Salary
	f.Write((char*)&m_Age,sizeof(int));//Age
	f.Seek(8,CFile::current);
	f.Write((char*)&m_Royalty,sizeof(int));//Royalty
	f.Write((char*)&m_Ability,sizeof(int));//Ability
	f.Seek(132,CFile::current);
	f.Write((char*)&m_FinalSeason,sizeof(int));//Last Year

	f.Close();
}
