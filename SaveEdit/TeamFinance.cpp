// TeamFinance.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "TeamFinance.h"
#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeamFinance

IMPLEMENT_DYNCREATE(CTeamFinance, CFormView)

CTeamFinance::CTeamFinance()
	: CFormView(CTeamFinance::IDD)
{
	//{{AFX_DATA_INIT(CTeamFinance)
	m_Cad = 0;
	m_Factory = 0;
	m_Cam = 0;
	m_SuperComputer = 0;
	m_TestRig = 0;
	m_WindTunnel = 0;
	m_WorkShop = 0;
	m_Balance = 0;
	//}}AFX_DATA_INIT
}

CTeamFinance::~CTeamFinance()
{
}

void CTeamFinance::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeamFinance)
	DDX_Control(pDX, IDC_SPIN_WINDTUNNEL, m_Spin_WindTunnel);
	DDX_Control(pDX, IDC_SPIN_WORKSHOP, m_Spin_WorkShop);
	DDX_Control(pDX, IDC_SPIN_TESTRIG, m_Spin_TestRig);
	DDX_Control(pDX, IDC_SPIN_SUPERCOMPUTER, m_Spin_SuperComputer);
	DDX_Control(pDX, IDC_SPIN_FACTORY, m_Spin_Factory);
	DDX_Control(pDX, IDC_SPIN_CAM, m_Spin_Cam);
	DDX_Control(pDX, IDC_SPIN_CAD, m_Spin_Cad);
	DDX_Control(pDX, IDC_SPIN_BALANCE, m_Spin_Balance);
	DDX_Text(pDX, IDC_EDIT_CAD, m_Cad);
	DDV_MinMaxInt(pDX, m_Cad, 0, 5);
	DDX_Text(pDX, IDC_EDIT_FACTORY, m_Factory);
	DDV_MinMaxInt(pDX, m_Factory, 0, 5);
	DDX_Text(pDX, IDC_EDIT_CAM, m_Cam);
	DDV_MinMaxInt(pDX, m_Cam, 0, 5);
	DDX_Text(pDX, IDC_EDIT_SUPERCOMPUTER, m_SuperComputer);
	DDV_MinMaxInt(pDX, m_SuperComputer, 0, 5);
	DDX_Text(pDX, IDC_EDIT_TESTRIG, m_TestRig);
	DDV_MinMaxInt(pDX, m_TestRig, 0, 5);
	DDX_Text(pDX, IDC_EDIT_WINDTUNNEL, m_WindTunnel);
	DDV_MinMaxInt(pDX, m_WindTunnel, 0, 5);
	DDX_Text(pDX, IDC_EDIT_WORKSHOP, m_WorkShop);
	DDV_MinMaxInt(pDX, m_WorkShop, 0, 5);
	DDX_Text(pDX, IDC_EDIT_BALANCE, m_Balance);
	DDV_MinMaxInt(pDX, m_Balance, -2147483647, 2147483647);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeamFinance, CFormView)
	//{{AFX_MSG_MAP(CTeamFinance)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeamFinance diagnostics

#ifdef _DEBUG
void CTeamFinance::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeamFinance::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeamFinance message handlers

void CTeamFinance::Load(int id, CString file)
{
CFile f;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);

	f.Seek(10712+(id*7824),CFile::begin);
	f.Read((char*)&m_Balance,sizeof(int));

	f.Seek(2404904+(id*224),CFile::begin);
	f.Read((char*)&m_WindTunnel,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_SuperComputer,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_Cam,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_Cad,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_WorkShop,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_TestRig,sizeof(int));
	f.Seek(24,CFile::current);
	f.Read((char*)&m_Factory,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CTeamFinance::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
}

void CTeamFinance::Save(CString file)
{
CFile f;
int iData;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(10712+(m_Id*7824),CFile::begin);
	f.Write((char*)&m_Balance,sizeof(int));

	f.Seek(2404896+(m_Id*224),CFile::begin);

	
	
	
	iData=1;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_WindTunnel,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=133333;
	f.Write((char*)&iData,sizeof(int));
	iData=2000000;
	f.Write((char*)&iData,sizeof(int));
	
	iData=2;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_SuperComputer,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=20000;
	f.Write((char*)&iData,sizeof(int));
	iData=300000;
	f.Write((char*)&iData,sizeof(int));	
	




	iData=3;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_Cam,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=20000;
	f.Write((char*)&iData,sizeof(int));
	iData=300000;
	f.Write((char*)&iData,sizeof(int));	







	iData=4;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_Cad,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=16666;
	f.Write((char*)&iData,sizeof(int));
	iData=250000;
	f.Write((char*)&iData,sizeof(int));	



	iData=5;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_WorkShop,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=20000;
	f.Write((char*)&iData,sizeof(int));
	iData=300000;
	f.Write((char*)&iData,sizeof(int));	




	iData=6;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_TestRig,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=20000;
	f.Write((char*)&iData,sizeof(int));
	iData=300000;
	f.Write((char*)&iData,sizeof(int));	



	
	iData=7;
	f.Write((char*)&iData,sizeof(int));
	iData=1998;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&m_Factory,sizeof(int));
	iData=0;
	f.Write((char*)&iData,sizeof(int));
	f.Write((char*)&iData,sizeof(int));
	iData=20000;
	f.Write((char*)&iData,sizeof(int));
	iData=300000;
	f.Write((char*)&iData,sizeof(int));	





















/*
	
	f.Write((char*)&m_SuperComputer,sizeof(int));
	f.Seek(24,CFile::current);
	f.Write((char*)&m_Cam,sizeof(int));
	f.Seek(24,CFile::current);
	f.Write((char*)&m_Cad,sizeof(int));
	f.Seek(24,CFile::current);
	f.Write((char*)&m_WorkShop,sizeof(int));
	f.Seek(24,CFile::current);
	f.Write((char*)&m_TestRig,sizeof(int));
	f.Seek(24,CFile::current);
	f.Write((char*)&m_Factory,sizeof(int));
*/
	f.Close();
}

void CTeamFinance::SetSpin()
{
	m_Spin_Balance.SetRange32(0,2147483647);
	m_Spin_Cad.SetRange(0,5);
	m_Spin_Cam.SetRange(0,5);
	m_Spin_Factory.SetRange(0,5);
	m_Spin_SuperComputer.SetRange(0,5);
	m_Spin_TestRig.SetRange(0,5);
	m_Spin_WindTunnel.SetRange(0,5);
	m_Spin_WorkShop.SetRange(0,5);
}
