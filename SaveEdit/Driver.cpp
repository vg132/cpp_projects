// Driver.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Driver.h"
#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriver

IMPLEMENT_DYNCREATE(CDriver, CFormView)

CDriver::CDriver()
	: CFormView(CDriver::IDD)
{
	//{{AFX_DATA_INIT(CDriver)
	m_Age = 0;
	m_CH = 0;
	m_Concentration = 0;
	m_Experience = 0;
	m_FastLaps = 0;
	m_Morale = 0;
	m_Overtaking = 0;
	m_Wins = 0;
	m_Wet = 0;
	m_TotalPoints = 0;
	m_Stamina = 0;
	m_Speed = 0;
	m_Skill = 0;
	m_Salary = 0;
	m_Races = 0;
	m_RaceBonus = 0;
	m_Pole = 0;
	m_Points = 0;
	m_PointFinish = 0;
	m_CHBonus = 0;
	//}}AFX_DATA_INIT
}

CDriver::~CDriver()
{
}

void CDriver::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriver)
	DDX_Control(pDX, IDC_DRIVER_COMBO_POS, m_Pos);
	DDX_Control(pDX, IDC_DRIVER_COMBO_ROLE, m_Role);
	DDX_Control(pDX, IDC_DRIVER_SPIN_WINS, m_Spin_Wins);
	DDX_Control(pDX, IDC_DRIVER_SPIN_WET, m_Spin_Wet);
	DDX_Control(pDX, IDC_DRIVER_SPIN_TOTALPOINTS, m_Spin_TotalPoints);
	DDX_Control(pDX, IDC_DRIVER_SPIN_STAMINA, m_Spin_Stamina);
	DDX_Control(pDX, IDC_DRIVER_SPIN_SPEED, m_Spin_Speed);
	DDX_Control(pDX, IDC_DRIVER_SPIN_SKILL, m_Spin_Skill);
	DDX_Control(pDX, IDC_DRIVER_SPIN_SALARY, m_Spin_Salary);
	DDX_Control(pDX, IDC_DRIVER_SPIN_RACES, m_Spin_Races);
	DDX_Control(pDX, IDC_DRIVER_SPIN_RACEBONUS, m_Spin_RaceBonus);
	DDX_Control(pDX, IDC_DRIVER_SPIN_POLE, m_Spin_Pole);
	DDX_Control(pDX, IDC_DRIVER_SPIN_POINTS, m_Spin_Points);
	DDX_Control(pDX, IDC_DRIVER_SPIN_POINTFINISH, m_Spin_PointFinish);
	DDX_Control(pDX, IDC_DRIVER_SPIN_OVERTAKING, m_Spin_Overtaking);
	DDX_Control(pDX, IDC_DRIVER_SPIN_MORALE, m_Spin_Morale);
	DDX_Control(pDX, IDC_DRIVER_SPIN_FASTLAPS, m_Spin_FastLaps);
	DDX_Control(pDX, IDC_DRIVER_SPIN_EXPERIENCE, m_Spin_Experiance);
	DDX_Control(pDX, IDC_DRIVER_SPIN_CONCENTRATION, m_Spin_Concentration);
	DDX_Control(pDX, IDC_DRIVER_SPIN_CHBONUS, m_Spin_CHBonus);
	DDX_Control(pDX, IDC_DRIVER_SPIN_CH, m_Spin_CH);
	DDX_Control(pDX, IDC_DRIVER_SPIN_AGE, m_Spin_Age);
	DDX_Control(pDX, IDC_DRIVER_COMBO_TEAM, m_Team);
	DDX_Control(pDX, IDC_DRIVER_COMBO_COUNTRY, m_Country);
	DDX_Text(pDX, IDC_DRIVER_EDIT_AGE, m_Age);
	DDV_MinMaxInt(pDX, m_Age, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_CH, m_CH);
	DDV_MinMaxInt(pDX, m_CH, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_CONCENTRATION, m_Concentration);
	DDV_MinMaxInt(pDX, m_Concentration, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_EXPERIENCE, m_Experience);
	DDV_MinMaxInt(pDX, m_Experience, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_FASTLAPS, m_FastLaps);
	DDV_MinMaxInt(pDX, m_FastLaps, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_MORALE, m_Morale);
	DDV_MinMaxInt(pDX, m_Morale, 0, 100);
	DDX_Text(pDX, IDC_DRIVER_EDIT_OVERTAKING, m_Overtaking);
	DDV_MinMaxInt(pDX, m_Overtaking, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_WINS, m_Wins);
	DDV_MinMaxInt(pDX, m_Wins, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_WET, m_Wet);
	DDV_MinMaxInt(pDX, m_Wet, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_TOTALPOINTS, m_TotalPoints);
	DDV_MinMaxInt(pDX, m_TotalPoints, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_STAMINA, m_Stamina);
	DDV_MinMaxInt(pDX, m_Stamina, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_SPEED, m_Speed);
	DDV_MinMaxInt(pDX, m_Speed, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_SKILL, m_Skill);
	DDV_MinMaxInt(pDX, m_Skill, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EDIT_SALARY, m_Salary);
	DDV_MinMaxInt(pDX, m_Salary, -1000000000, 1000000000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_RACES, m_Races);
	DDV_MinMaxInt(pDX, m_Races, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_RACEBONUS, m_RaceBonus);
	DDV_MinMaxInt(pDX, m_RaceBonus, 0, 1000000000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_POLE, m_Pole);
	DDV_MinMaxInt(pDX, m_Pole, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_POINTS, m_Points);
	DDV_MinMaxInt(pDX, m_Points, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_POINTFINISH, m_PointFinish);
	DDV_MinMaxInt(pDX, m_PointFinish, 0, 32000);
	DDX_Text(pDX, IDC_DRIVER_EDIT_CHBONUS, m_CHBonus);
	DDV_MinMaxInt(pDX, m_CHBonus, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDriver, CFormView)
	//{{AFX_MSG_MAP(CDriver)
	ON_CBN_SELCHANGE(IDC_DRIVER_COMBO_ROLE, OnSelchangeDriverComboRole)
	ON_CBN_SELCHANGE(IDC_DRIVER_COMBO_POS, OnSelchangeDriverComboPos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriver diagnostics

#ifdef _DEBUG
void CDriver::AssertValid() const
{
	CFormView::AssertValid();
}

void CDriver::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDriver message handlers

void CDriver::Load(int id, CString file)
{
CFile f;
int iData;
int iDriv[41]={5,6,7,13,14,15,21,22,29,30,31,37,
			   38,45,46,47,53,54,55,61,62,63,69,
			   70,77,78,79,85,86,87,128,129,130,
			   131,132,133,134,135,136,137,138};

	m_Id=id;
	f.Open(file,CFile::modeRead,NULL);
	f.Seek(97824+(3576*iDriv[id]),CFile::begin);

	f.Read((char*)&iData,sizeof(int));//pic pos (1-2-3)
	m_Pos.SetCurSel(iData-6);

	f.Seek(4,CFile::current);

	f.Read((char*)&iData,sizeof(int));//Team
	m_Team.SetCurSel(iData);

	f.Seek(8,CFile::current);
	f.Read((char*)&m_Salary,sizeof(int)); //Salary
	f.Read((char*)&m_Age,sizeof(int)); //Age
	f.Read((char*)&m_RaceBonus,sizeof(int));//Race Bonus
	f.Read((char*)&m_CHBonus,sizeof(int));//WC Bonus
	f.Seek(8,CFile::current);
	f.Read((char*)&m_Points,sizeof(int));//Points
	f.Read((char*)&m_TotalPoints,sizeof(int));//Total points
	f.Seek(8,CFile::current);
	f.Read((char*)&m_Wins,sizeof(int));//Wins
	f.Read((char*)&m_Pole,sizeof(int));//Pole
	f.Seek(100,CFile::current);
	f.Read((char*)&iData,sizeof(int));//Country
	m_Country.SetCurSel(iData);

	f.Seek(2964,CFile::current);
	f.Read((char*)&m_Speed,sizeof(int));//Speed
	f.Read((char*)&m_Overtaking,sizeof(int));//Overtaking
	f.Read((char*)&m_Wet,sizeof(int));//Wet Wether
	f.Read((char*)&m_Concentration,sizeof(int));//Concentration
	f.Read((char*)&m_Experience,sizeof(int));//Experience
	f.Read((char*)&m_Stamina,sizeof(int));//Stamina
	f.Read((char*)&m_Morale,sizeof(int));//Morale
	f.Seek(4,CFile::current);
	f.Read((char*)&m_Skill,sizeof(int));//Skill

	f.Seek(12,CFile::current);
	f.Read((char*)&iData,sizeof(int));//Driver role
	m_Role.SetCurSel(iData-1);

	f.Seek(4,CFile::current);

	f.Read((char*)&m_CH,sizeof(int));//championships
	f.Read((char*)&m_Races,sizeof(int));//races
	f.Seek(4,CFile::current);
	f.Read((char*)&m_PointFinish,sizeof(int));//point finish
	f.Read((char*)&m_FastLaps,sizeof(int));//fast laps

	f.Close();
	m_Pos.EnableWindow(FALSE);
	UpdateData(FALSE);
}

void CDriver::FillBox()
{
CLoadText m_LoadText;
int i;
	i=m_Team.GetCount();
	for(i;i<0;i--)
		m_Team.DeleteString(i);
	i=m_Country.GetCount();
	for(i;i<0;i--)
		m_Country.DeleteString(i);

	m_LoadText.LoadText();
	for(i=0;i<15;i++)
		m_Country.AddString(m_LoadText.m_Country[i]);
	for(i=0;i<12;i++)
		m_Team.AddString(m_LoadText.m_Teams[i]);
}

void CDriver::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	FillBox();	
	SetSpin();
}

void CDriver::SetSpin()
{
	m_Spin_Age.SetRange(0,32000);
	m_Spin_CH.SetRange(0,32000);
	m_Spin_CHBonus.SetRange32(0,1000000000);
	m_Spin_Concentration.SetRange(0,5);
	m_Spin_Experiance.SetRange(0,5);
	m_Spin_FastLaps.SetRange(0,32000);
	m_Spin_Morale.SetRange(0,100);
	m_Spin_Overtaking.SetRange(0,5);
	m_Spin_PointFinish.SetRange(0,32000);
	m_Spin_Points.SetRange(0,32000);
	m_Spin_Pole.SetRange(0,32000);
	m_Spin_RaceBonus.SetRange32(0,1000000000);
	m_Spin_Races.SetRange(0,32000);
	m_Spin_Salary.SetRange32(-1000000000,1000000000);
	m_Spin_Skill.SetRange(0,5);
	m_Spin_Speed.SetRange(0,5);
	m_Spin_Stamina.SetRange(0,5);
	m_Spin_TotalPoints.SetRange(0,32000);
	m_Spin_Wet.SetRange(0,5);
	m_Spin_Wins.SetRange(0,32000);
}

void CDriver::SaveDriver(CString file)
{
CFile f;
int iData;
int iDriv[41]={5,6,7,13,14,15,21,22,29,30,31,37,
			   38,45,46,47,53,54,55,61,62,63,69,
			   70,77,78,79,85,86,87,128,129,130,
			   131,132,133,134,135,136,137,138};

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);
	f.Seek(97824+(3576*iDriv[m_Id]),CFile::begin);

	iData=m_Pos.GetCurSel()+6;
	f.Write((char*)&iData,sizeof(int));//pic pos (1-2-3)
	f.Seek(4,CFile::current);

	iData=m_Team.GetCurSel();
	f.Write((char*)&iData,sizeof(int)); //Team

	f.Seek(8,CFile::current);
	f.Write((char*)&m_Salary,sizeof(int)); //Salary
	f.Write((char*)&m_Age,sizeof(int)); //Age
	f.Write((char*)&m_RaceBonus,sizeof(int));//Race Bonus
	f.Write((char*)&m_CHBonus,sizeof(int));//WC Bonus
	f.Seek(8,CFile::current);
	f.Write((char*)&m_Points,sizeof(int));//Points
	f.Write((char*)&m_TotalPoints,sizeof(int));//Total points
	f.Seek(8,CFile::current);
	f.Write((char*)&m_Wins,sizeof(int));//Wins
	f.Write((char*)&m_Pole,sizeof(int));//Pole
	f.Seek(100,CFile::current);

	iData=m_Country.GetCurSel();
	f.Write((char*)&iData,sizeof(int));//Country

	f.Seek(2964,CFile::current);
	f.Write((char*)&m_Speed,sizeof(int));//Speed
	f.Write((char*)&m_Overtaking,sizeof(int));//Overtaking
	f.Write((char*)&m_Wet,sizeof(int));//Wet Wether
	f.Write((char*)&m_Concentration,sizeof(int));//Concentration
	f.Write((char*)&m_Experience,sizeof(int));//Experience
	f.Write((char*)&m_Stamina,sizeof(int));//Stamina
	f.Write((char*)&m_Morale,sizeof(int));//Morale
	f.Seek(4,CFile::current);
	f.Write((char*)&m_Skill,sizeof(int));//Skill

	f.Seek(12,CFile::current);
	iData=m_Role.GetCurSel()+1;
	f.Write((char*)&iData,sizeof(int)); // Driver role
	f.Seek(4,CFile::current);

	f.Write((char*)&m_CH,sizeof(int)); //Championships
	f.Write((char*)&m_Races,sizeof(int)); //Races
	f.Seek(4,CFile::current);
	f.Write((char*)&m_PointFinish,sizeof(int)); //Point finished
	f.Write((char*)&m_FastLaps,sizeof(int)); //Fastest laps

	f.Close();
}

void CDriver::OnSelchangeDriverComboRole() 
{
	UpdateData(TRUE);
	if(m_Role.GetCurSel()==0)
	{
		m_Pos.SetCurSel(0);
		m_Pos.EnableWindow(FALSE);
	}
	else if(m_Role.GetCurSel()==2)
	{
		m_Pos.SetCurSel(1);
		m_Pos.EnableWindow(FALSE);
	}
	else if(m_Role.GetCurSel()==3)
	{
		m_Pos.SetCurSel(2);
		m_Pos.EnableWindow(FALSE);
	}
	else if(m_Role.GetCurSel()==1)
	{
		m_Pos.EnableWindow(TRUE);
		if(m_Pos.GetCurSel()==2)
			m_Pos.SetCurSel(0);
	}
	UpdateData(FALSE);
}

void CDriver::OnSelchangeDriverComboPos() 
{
	if(m_Role.GetCurSel()==1&&m_Pos.GetCurSel()==2)
	{
		MessageBox("You can only select this position for a test driver.","GPW Save File Editor",MB_OK);
		m_Pos.SetCurSel(0);
	}
}
