// Design.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Design.h"

#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesign

IMPLEMENT_DYNCREATE(CDesign, CFormView)

CDesign::CDesign()
	: CFormView(CDesign::IDD)
{
	//{{AFX_DATA_INIT(CDesign)
	m_CHBonus = 0;
	m_Ability = 0;
	m_Salary = 0;
	m_Age = 0;
	m_FinalSeason = 0;
	m_RaceBonus = 0;
	//}}AFX_DATA_INIT
}

CDesign::~CDesign()
{
}

void CDesign::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDesign)
	DDX_Control(pDX, IDC_SPIN_FINALSEASON, m_Spin_FinalSeason);
	DDX_Control(pDX, IDC_SPIN_CHBONUS, m_Spin_CHBonus);
	DDX_Control(pDX, IDC_SPIN_ABILITY, m_Spin_Ability);
	DDX_Control(pDX, IDC_SPIN_AGE, m_Spin_Age);
	DDX_Control(pDX, IDC_SPIN_RACEBONUS, m_Spin_RaceBonus);
	DDX_Control(pDX, IDC_SPIN_SALARY, m_Spin_Salary);
	DDX_Control(pDX, IDC_COMBO_TEAM, m_Team);
	DDX_Control(pDX, IDC_DRIVERLOYALTY, m_DriverLoyalty);
	DDX_Text(pDX, IDC_CHBONUS, m_CHBonus);
	DDV_MinMaxInt(pDX, m_CHBonus, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_ABILITY, m_Ability);
	DDV_MinMaxInt(pDX, m_Ability, 0, 5);
	DDX_Text(pDX, IDC_EDIT_SALARY, m_Salary);
	DDV_MinMaxInt(pDX, m_Salary, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_AGE, m_Age);
	DDV_MinMaxInt(pDX, m_Age, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_FINALSEASON, m_FinalSeason);
	DDV_MinMaxInt(pDX, m_FinalSeason, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_RACEBONUS, m_RaceBonus);
	DDV_MinMaxInt(pDX, m_RaceBonus, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDesign, CFormView)
	//{{AFX_MSG_MAP(CDesign)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesign diagnostics

#ifdef _DEBUG
void CDesign::AssertValid() const
{
	CFormView::AssertValid();
}

void CDesign::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesign message handlers

void CDesign::Load(int id, CString file)
{
CFile f;
unsigned int iData;
int iDes[21]={2,10,18,26,34,42,50,58,66,74,82,98,
			  99,100,101,102,103,104,105,106,107};

	m_Id=id;
	f.Open(file,CFile::modeRead,NULL);

	f.Seek(97832+(3576*iDes[id]),CFile::begin);

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

void CDesign::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	FillBox();
	SetSpin();
}

void CDesign::FillBox()
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

void CDesign::SetSpin()
{
	m_Spin_Ability.SetRange(0,5);
	m_Spin_Age.SetRange(0,32000);
	m_Spin_CHBonus.SetRange32(0,1000000000);
	m_Spin_FinalSeason.SetRange(0,32000);
	m_Spin_RaceBonus.SetRange32(0,1000000000);
	m_Spin_Salary.SetRange32(0,1000000000);
}

void CDesign::Save(CString file)
{
CFile f;
unsigned int iData;
int iDes[21]={2,10,18,26,34,42,50,58,66,74,82,98,
			  99,100,101,102,103,104,105,106,107};

	UpdateData(TRUE);
	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(97832+(3576*iDes[m_Id]),CFile::begin);

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
