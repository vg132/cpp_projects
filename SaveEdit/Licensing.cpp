// Licensing.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Licensing.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLicensing

IMPLEMENT_DYNCREATE(CLicensing, CFormView)

CLicensing::CLicensing()
	: CFormView(CLicensing::IDD)
{
	//{{AFX_DATA_INIT(CLicensing)
	m_Check_Cars = FALSE;
	m_Check_Clothing = FALSE;
	m_Check_FanClub = FALSE;
	m_Check_Publishing = FALSE;
	m_Check_VideoGames = FALSE;
	m_Cash_Cars = 0;
	m_Cash_Chronometers = 0;
	m_Cash_Clothing = 0;
	m_Cash_FanClub = 0;
	m_Cash_Publishing = 0;
	m_Cash_VideoGames = 0;
	m_Completion_Cars = 0;
	m_Completion_Publishing = 0;
	m_Completion_VideoGames = 0;
	m_Completion_Chronometers = 0;
	m_Completion_Clothing = 0;
	m_Completion_FanClub = 0;
	m_Demand_Cars = 0;
	m_Demand_FanClub = 0;
	m_Demand_Publishing = 0;
	m_Demand_VideoGams = 0;
	m_Demand_Clothing = 0;
	m_Demand_Chronometers = 0;
	m_Check_Chronometers = FALSE;
	//}}AFX_DATA_INIT
}

CLicensing::~CLicensing()
{
}

void CLicensing::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLicensing)
	DDX_Control(pDX, IDC_SPIN_COMPLETION_PUBLISHING, m_Spin_Completion_Publishing);
	DDX_Control(pDX, IDC_SPIN_COMPLETION_VIDEOGAMES, m_Spin_Completion_VideoGames);
	DDX_Control(pDX, IDC_SPIN_COMPLETION_FANCLUB, m_Spin_Completion_FanClub);
	DDX_Control(pDX, IDC_SPIN_COMPLETION_CLOTHING, m_Spin_Completion_Clothing);
	DDX_Control(pDX, IDC_SPIN_COMPLETION_CHRONOMETERS, m_Spin_Completion_Chronometers);
	DDX_Control(pDX, IDC_SPIN_COMPLETION_CARS, m_Spin_Completion_Cars);
	DDX_Control(pDX, IDC_SPIN_DEMAND_PUBLISHING, m_Spin_Demand_Publishing);
	DDX_Control(pDX, IDC_SPIN_DEMAND_CLOTHING, m_Spin_Demand_Clothing);
	DDX_Control(pDX, IDC_SPIN_DEMAND_CHRONOMETERS, m_Spin_Demand_Chronometers);
	DDX_Control(pDX, IDC_SPIN_DEMAND_CARS, m_Spin_Demand_Cars);
	DDX_Control(pDX, IDC_SPIN_DEMAND_FANCLUB, m_Spin_Demand_FanClub);
	DDX_Control(pDX, IDC_SPIN_DEMAND_VIDEOGAMES, m_Spin_Demand_VideoGames);
	DDX_Control(pDX, IDC_SPIN_CASH_VIDEOGAMES, m_Spin_Cash_VideoGames);
	DDX_Control(pDX, IDC_SPIN_CASH_PUBLISHING, m_Spin_Cash_Publishing);
	DDX_Control(pDX, IDC_SPIN_CASH_FANCLUB, m_Spin_Cash_FanClub);
	DDX_Control(pDX, IDC_SPIN_CASH_CLOTHING, m_Spin_Cash_Clothing);
	DDX_Control(pDX, IDC_SPIN_CASH_CHRONOMETERS, m_Spin_Cash_Chronometers);
	DDX_Control(pDX, IDC_SPIN_CASH_CARS, m_Spin_Cash_Cars);
	DDX_Check(pDX, IDC_CHECK_CARS, m_Check_Cars);
	DDX_Check(pDX, IDC_CHECK_CLOTHING, m_Check_Clothing);
	DDX_Check(pDX, IDC_CHECK_FANCLUB, m_Check_FanClub);
	DDX_Check(pDX, IDC_CHECK_PUBLISHING, m_Check_Publishing);
	DDX_Check(pDX, IDC_CHECK_VIDEOGAMES, m_Check_VideoGames);
	DDX_Text(pDX, IDC_EDIT_CASH_CARS, m_Cash_Cars);
	DDV_MinMaxInt(pDX, m_Cash_Cars, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_CASH_CHRONOMETERS, m_Cash_Chronometers);
	DDV_MinMaxInt(pDX, m_Cash_Chronometers, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_CASH_CLOTHING, m_Cash_Clothing);
	DDV_MinMaxInt(pDX, m_Cash_Clothing, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_CASH_FANCLUB, m_Cash_FanClub);
	DDV_MinMaxInt(pDX, m_Cash_FanClub, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_CASH_PUBLISHING, m_Cash_Publishing);
	DDV_MinMaxInt(pDX, m_Cash_Publishing, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_CASH_VIDEOGAMES, m_Cash_VideoGames);
	DDV_MinMaxInt(pDX, m_Cash_VideoGames, 0, 1000000000);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_CARS, m_Completion_Cars);
	DDV_MinMaxInt(pDX, m_Completion_Cars, 0, 6);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_PUBLISHING, m_Completion_Publishing);
	DDV_MinMaxInt(pDX, m_Completion_Publishing, 0, 3);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_VIDEOGAMES, m_Completion_VideoGames);
	DDV_MinMaxInt(pDX, m_Completion_VideoGames, 0, 4);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_CHRONOMETERS, m_Completion_Chronometers);
	DDV_MinMaxInt(pDX, m_Completion_Chronometers, 0, 5);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_CLOTHING, m_Completion_Clothing);
	DDV_MinMaxInt(pDX, m_Completion_Clothing, 0, 2);
	DDX_Text(pDX, IDC_EDIT_COMPLETION_FANCLUB, m_Completion_FanClub);
	DDV_MinMaxInt(pDX, m_Completion_FanClub, 0, 1);
	DDX_Text(pDX, IDC_EDIT_DEMAND_CARS, m_Demand_Cars);
	DDV_MinMaxInt(pDX, m_Demand_Cars, 0, 5);
	DDX_Text(pDX, IDC_EDIT_DEMAND_FANCLUB, m_Demand_FanClub);
	DDV_MinMaxInt(pDX, m_Demand_FanClub, 0, 5);
	DDX_Text(pDX, IDC_EDIT_DEMAND_PUBLISHING, m_Demand_Publishing);
	DDV_MinMaxInt(pDX, m_Demand_Publishing, 0, 5);
	DDX_Text(pDX, IDC_EDIT_DEMAND_VIDEOGAMES, m_Demand_VideoGams);
	DDV_MinMaxInt(pDX, m_Demand_VideoGams, 0, 5);
	DDX_Text(pDX, IDC_EDIT_DEMAND_CLOTHING, m_Demand_Clothing);
	DDV_MinMaxInt(pDX, m_Demand_Clothing, 0, 5);
	DDX_Text(pDX, IDC_EDIT_DEMAND_CHRONOMETERS, m_Demand_Chronometers);
	DDV_MinMaxInt(pDX, m_Demand_Chronometers, 0, 5);
	DDX_Check(pDX, IDC_CHECK_CHRONOMETERS, m_Check_Chronometers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLicensing, CFormView)
	//{{AFX_MSG_MAP(CLicensing)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLicensing diagnostics

#ifdef _DEBUG
void CLicensing::AssertValid() const
{
	CFormView::AssertValid();
}

void CLicensing::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLicensing message handlers

void CLicensing::Load(int id, CString file)
{
CFile f;
int iData;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);

	f.Seek(15632+(id*7824),CFile::begin);
	f.Read((char*)&m_Demand_FanClub,sizeof(int));
	f.Read((char*)&m_Demand_Clothing,sizeof(int));
	f.Read((char*)&m_Demand_Publishing,sizeof(int));
	f.Read((char*)&m_Demand_VideoGams,sizeof(int));
	f.Read((char*)&m_Demand_Chronometers,sizeof(int));
	f.Read((char*)&m_Demand_Cars,sizeof(int));

	f.Read((char*)&iData,sizeof(int));
	m_Completion_FanClub=ConvertCompletion(false,iData);
	f.Read((char*)&iData,sizeof(int));
	m_Completion_Clothing=ConvertCompletion(false,iData);
	f.Read((char*)&iData,sizeof(int));
	m_Completion_Publishing=ConvertCompletion(false,iData);
	f.Read((char*)&iData,sizeof(int));
	m_Completion_VideoGames=ConvertCompletion(false,iData);
	f.Read((char*)&iData,sizeof(int));
	m_Completion_Chronometers=ConvertCompletion(false,iData);
	f.Read((char*)&iData,sizeof(int));
	m_Completion_Cars=ConvertCompletion(false,iData);

	f.Read((char*)&m_Check_FanClub,sizeof(int));
	f.Read((char*)&m_Check_Clothing,sizeof(int));
	f.Read((char*)&m_Check_Publishing,sizeof(int));
	f.Read((char*)&m_Check_VideoGames,sizeof(int));
	f.Read((char*)&m_Check_Chronometers,sizeof(int));
	f.Read((char*)&m_Check_Cars,sizeof(int));

	f.Read((char*)&m_Cash_FanClub,sizeof(int));
	f.Read((char*)&m_Cash_Clothing,sizeof(int));
	f.Read((char*)&m_Cash_Publishing,sizeof(int));
	f.Read((char*)&m_Cash_VideoGames,sizeof(int));
	f.Read((char*)&m_Cash_Chronometers,sizeof(int));
	f.Read((char*)&m_Cash_Cars,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

int CLicensing::ConvertCompletion(bool togpw, int Completion)
{
	if(togpw==true)
	{
		Completion=(500*(Completion+1))*Completion;
	}
	else
	{
		if(Completion<1000)
			Completion=0;
		else if(Completion>=1000&&Completion<3000)
			Completion=1;
		else if(Completion>=3000&&Completion<6000)
			Completion=2;
		else if(Completion>=6000&&Completion<10000)
			Completion=3;
		else if(Completion>=10000&&Completion<15000)
			Completion=4;
		else if(Completion>=15000&&Completion<21000)
			Completion=5;
		else if(Completion>=21000)
			Completion=6;
	}
	return(Completion);
}


void CLicensing::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
}

void CLicensing::SetSpin()
{
	m_Spin_Completion_Cars.SetRange(0,6);
	m_Spin_Completion_Chronometers.SetRange(0,5);
	m_Spin_Completion_Clothing.SetRange(0,2);
	m_Spin_Completion_FanClub.SetRange(0,1);
	m_Spin_Completion_VideoGames.SetRange(0,4);
	m_Spin_Completion_Publishing.SetRange(0,3);

	m_Spin_Demand_Cars.SetRange(0,5);
	m_Spin_Demand_Chronometers.SetRange(0,5);
	m_Spin_Demand_Clothing.SetRange(0,5);
	m_Spin_Demand_FanClub.SetRange(0,5);
	m_Spin_Demand_Publishing.SetRange(0,5);
	m_Spin_Demand_VideoGames.SetRange(0,5);

	m_Spin_Cash_Cars.SetRange32(0,1000000000);
	m_Spin_Cash_Chronometers.SetRange32(0,1000000000);
	m_Spin_Cash_Clothing.SetRange32(0,1000000000);
	m_Spin_Cash_FanClub.SetRange32(0,1000000000);
	m_Spin_Cash_Publishing.SetRange32(0,1000000000);
	m_Spin_Cash_VideoGames.SetRange32(0,1000000000);
}

void CLicensing::Save(CString file)
{
CFile f;
int iData;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(15632+(m_Id*7824),CFile::begin);
	f.Write((char*)&m_Demand_FanClub,sizeof(int));
	f.Write((char*)&m_Demand_Clothing,sizeof(int));
	f.Write((char*)&m_Demand_Publishing,sizeof(int));
	f.Write((char*)&m_Demand_VideoGams,sizeof(int));
	f.Write((char*)&m_Demand_Chronometers,sizeof(int));
	f.Write((char*)&m_Demand_Cars,sizeof(int));

	iData=ConvertCompletion(true,m_Completion_FanClub);
	f.Write((char*)&iData,sizeof(int));

	iData=ConvertCompletion(true,m_Completion_Clothing);
	f.Write((char*)&iData,sizeof(int));
	
	iData=ConvertCompletion(true,m_Completion_Publishing);
	f.Write((char*)&iData,sizeof(int));
	
	iData=ConvertCompletion(true,m_Completion_VideoGames);
	f.Write((char*)&iData,sizeof(int));
	
	iData=ConvertCompletion(true,m_Completion_Chronometers);
	f.Write((char*)&iData,sizeof(int));
	
	iData=ConvertCompletion(true,m_Completion_Cars);
	f.Write((char*)&iData,sizeof(int));

	f.Write((char*)&m_Check_FanClub,sizeof(int));
	f.Write((char*)&m_Check_Clothing,sizeof(int));
	f.Write((char*)&m_Check_Publishing,sizeof(int));
	f.Write((char*)&m_Check_VideoGames,sizeof(int));
	f.Write((char*)&m_Check_Chronometers,sizeof(int));
	f.Write((char*)&m_Check_Cars,sizeof(int));

	f.Write((char*)&m_Cash_FanClub,sizeof(int));
	f.Write((char*)&m_Cash_Clothing,sizeof(int));
	f.Write((char*)&m_Cash_Publishing,sizeof(int));
	f.Write((char*)&m_Cash_VideoGames,sizeof(int));
	f.Write((char*)&m_Cash_Chronometers,sizeof(int));
	f.Write((char*)&m_Cash_Cars,sizeof(int));

	iData=m_Cash_FanClub*16;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash_Clothing*16;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash_Publishing*16;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash_VideoGames*16;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash_Chronometers*16;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash_Cars*16;
	f.Write((char*)&iData,sizeof(int));

	f.Close();
}
