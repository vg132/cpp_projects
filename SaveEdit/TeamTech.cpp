// TeamTech.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "TeamTech.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeamTech

IMPLEMENT_DYNCREATE(CTeamTech, CFormView)

CTeamTech::CTeamTech()
	: CFormView(CTeamTech::IDD)
{
	//{{AFX_DATA_INIT(CTeamTech)
	m_Aids = 0;
	m_Chassis = 0;
	m_NextCar = 0;
	m_Spares = 0;
	m_Tech = 0;
	m_ThisCar = 0;
	//}}AFX_DATA_INIT
}

CTeamTech::~CTeamTech()
{
}

void CTeamTech::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeamTech)
	DDX_Control(pDX, IDC_SPIN_SPARES, m_Spin_Spares);
	DDX_Control(pDX, IDC_SPIN_THISCAR, m_Spin_ThisCar);
	DDX_Control(pDX, IDC_SPIN_TECH, m_Spin_Tech);
	DDX_Control(pDX, IDC_SPIN_NEXTCAR, m_Spin_NextCar);
	DDX_Control(pDX, IDC_SPIN_CHASSIS, m_Spin_Chassis);
	DDX_Control(pDX, IDC_SPIN_AIDS, m_Spin_Aids);
	DDX_Text(pDX, IDC_AIDS, m_Aids);
	DDV_MinMaxInt(pDX, m_Aids, 0, 1000000000);
	DDX_Text(pDX, IDC_CHASSIS, m_Chassis);
	DDV_MinMaxInt(pDX, m_Chassis, 0, 1000000000);
	DDX_Text(pDX, IDC_NEXTCAR, m_NextCar);
	DDV_MinMaxInt(pDX, m_NextCar, 0, 1000000000);
	DDX_Text(pDX, IDC_SPARES, m_Spares);
	DDV_MinMaxInt(pDX, m_Spares, 0, 1000000000);
	DDX_Text(pDX, IDC_TECH, m_Tech);
	DDV_MinMaxInt(pDX, m_Tech, 0, 1000000000);
	DDX_Text(pDX, IDC_THISCAR, m_ThisCar);
	DDV_MinMaxInt(pDX, m_ThisCar, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeamTech, CFormView)
	//{{AFX_MSG_MAP(CTeamTech)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeamTech diagnostics

#ifdef _DEBUG
void CTeamTech::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeamTech::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeamTech message handlers

void CTeamTech::Load(int id, CString file)
{
CFile f;

	m_Id=id;
	f.Open(file,CFile::modeRead,NULL);

	f.Seek(2776432+(168*m_Id),CFile::begin);

	f.Read((char*)&m_ThisCar,sizeof(int));
	f.Read((char*)&m_NextCar,sizeof(int));
	f.Read((char*)&m_Chassis,sizeof(int));
	f.Read((char*)&m_Tech,sizeof(int));
	f.Read((char*)&m_Aids,sizeof(int));
	f.Read((char*)&m_Spares,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CTeamTech::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
//	SetSpin();
}

void CTeamTech::SetSpin()
{
	m_Spin_Aids.SetRange32(0,1000000000);
	m_Spin_Chassis.SetRange32(0,1000000000);
	m_Spin_NextCar.SetRange32(0,1000000000);
	m_Spin_Spares.SetRange32(0,1000000000);
	m_Spin_Tech.SetRange32(0,1000000000);
	m_Spin_ThisCar.SetRange32(0,1000000000);
}

void CTeamTech::Save(CString file)
{
CFile f;
	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(2776432+(168*m_Id),CFile::begin);

	f.Write((char*)&m_ThisCar,sizeof(int));
	f.Write((char*)&m_NextCar,sizeof(int));
	f.Write((char*)&m_Chassis,sizeof(int));
	f.Write((char*)&m_Tech,sizeof(int));
	f.Write((char*)&m_Aids,sizeof(int));
	f.Write((char*)&m_Spares,sizeof(int));

	f.Close();
}
