// Mechanics.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Mechanics.h"

#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMechanics

IMPLEMENT_DYNCREATE(CMechanics, CFormView)

CMechanics::CMechanics()
	: CFormView(CMechanics::IDD)
{
	//{{AFX_DATA_INIT(CMechanics)
	m_CHBonus = 0;
	m_Age = 0;
	m_Ability = 0;
	m_FinalSeason = 0;
	m_RaceBonus = 0;
	m_Salary = 0;
	//}}AFX_DATA_INIT
}

CMechanics::~CMechanics()
{
}

void CMechanics::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMechanics)
	DDX_Control(pDX, IDC_SPIN_SALARY, m_Spin_Salary);
	DDX_Control(pDX, IDC_SPIN_RACEBONUS, m_Spin_RaceBonus);
	DDX_Control(pDX, IDC_SPIN_FINALSEASON, m_Spin_FinalSeason);
	DDX_Control(pDX, IDC_SPIN_AGE, m_Spin_Age);
	DDX_Control(pDX, IDC_SPIN_CHBONUS, m_Spin_CHBonus);
	DDX_Control(pDX, IDC_SPIN_ABILITY, m_Spin_Ability);
	DDX_Control(pDX, IDC_DRIVERLOYALTY, m_DriverLoyalty);
	DDX_Control(pDX, IDC_COMBO_TEAM, m_Team);
	DDX_Text(pDX, IDC_CHBONUS, m_CHBonus);
	DDV_MinMaxInt(pDX, m_CHBonus, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_AGE, m_Age);
	DDV_MinMaxInt(pDX, m_Age, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_ABILITY, m_Ability);
	DDV_MinMaxInt(pDX, m_Ability, 0, 5);
	DDX_Text(pDX, IDC_EDIT_FINALSEASON, m_FinalSeason);
	DDV_MinMaxInt(pDX, m_FinalSeason, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_RACEBONUS, m_RaceBonus);
	DDV_MinMaxInt(pDX, m_RaceBonus, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_SALARY, m_Salary);
	DDV_MinMaxInt(pDX, m_Salary, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMechanics, CFormView)
	//{{AFX_MSG_MAP(CMechanics)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMechanics diagnostics

#ifdef _DEBUG
void CMechanics::AssertValid() const
{
	CFormView::AssertValid();
}

void CMechanics::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMechanics message handlers

void CMechanics::Load(int id, CString file)
{
CFile f;
unsigned int iData;
int iMec[21]={4,12,20,28,36,44,52,60,68,76,84,118,
			  119,120,121,122,123,124,125,126,127};

	m_Id=id;
	f.Open(file,CFile::modeRead,NULL);

	f.Seek(97832+(3576*iMec[id]),CFile::begin);

	f.Read((char*)&iData,sizeof(int));
	m_Team.SetCurSel(iData);
	f.Seek(8,CFile::current);
	f.Read((char*)&m_Salary,sizeof(int));
	f.Read((char*)&m_Age,sizeof(int));
	f.Read((char*)&m_RaceBonus,sizeof(int));
	f.Read((char*)&m_CHBonus,sizeof(int));
	f.Seek(4,CFile::current);
	f.Read((char*)&m_Ability,sizeof(int));
	f.Seek(128,CFile::current);
	f.Read((char*)&iData,sizeof(int));
	
	if(iData!=0)
	{
		for(int i=0;i<41;i++)
			if(m_DriverLoyalty.GetItemData(i)==iData)
				m_DriverLoyalty.SetCurSel(i);
	}
	else
		m_DriverLoyalty.SetCurSel(0);
	f.Read((char*)&m_FinalSeason,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CMechanics::Save(CString file)
{
CFile f;
unsigned int iData;
int iMec[21]={4,12,20,28,36,44,52,60,68,76,84,118,
			  119,120,121,122,123,124,125,126,127};

	UpdateData(TRUE);
	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(97832+(3576*iMec[m_Id]),CFile::begin);

	iData=m_Team.GetCurSel();
	f.Write((char*)&iData,sizeof(int));
	f.Seek(8,CFile::current);
	f.Write((char*)&m_Salary,sizeof(int));
	f.Write((char*)&m_Age,sizeof(int));
	f.Write((char*)&m_RaceBonus,sizeof(int));
	f.Write((char*)&m_CHBonus,sizeof(int));
	f.Seek(4,CFile::current);
	f.Write((char*)&m_Ability,sizeof(int));
	f.Seek(128,CFile::current);
	iData=m_DriverLoyalty.GetItemData(m_DriverLoyalty.GetCurSel());
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_FinalSeason,sizeof(int));

	f.Close();
}

void CMechanics::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
	FillBox();
}

void CMechanics::SetSpin()
{
	m_Spin_Ability.SetRange(0,5);
	m_Spin_Age.SetRange(0,32000);
	m_Spin_CHBonus.SetRange32(0,1000000000);
	m_Spin_FinalSeason.SetRange(0,32000);
	m_Spin_RaceBonus.SetRange32(0,1000000000);
	m_Spin_Salary.SetRange32(0,1000000000);
}

void CMechanics::FillBox()
{
CLoadText m_Text;
int i;
int iDriv[41]={5,6,7,13,14,15,21,22,29,30,31,37,
			   38,45,46,47,53,54,55,61,62,63,69,
			   70,77,78,79,85,86,87,128,129,130,
			   131,132,133,134,135,136,137,138};

	m_Text.LoadText();

	for(i=0;i<12;i++)
		m_Team.AddString(m_Text.m_Teams[i]);
	m_DriverLoyalty.AddString("None");
	m_DriverLoyalty.SetItemData(0,0);
	for(i=0;i<41;i++)
	{
		m_DriverLoyalty.AddString(m_Text.m_Name[iDriv[i]]);
		m_DriverLoyalty.SetItemData(i+1,iDriv[i]);
	}
}
