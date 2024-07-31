// Rear.cpp : implementation file
//

#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "Rear.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRear property page

IMPLEMENT_DYNCREATE(CRear, CPropertyPage)

CRear::CRear() : CPropertyPage(CRear::IDD)
{
	//{{AFX_DATA_INIT(CRear)
	m_AntiRollBar = -1;
	m_LeftSpring = -1;
	m_RightSpring = -1;
	m_LeftDumper = 0;
	m_LeftFastRebound = 0;
	m_LeftPackers = 0;
	m_LeftSlowBump = 0;
	m_LeftSlowRebound = 0;
	m_RightDumper = 0;
	m_RightFastRebound = 0;
	m_RightPackers = 0;
	m_RightSlowBump = 0;
	m_RightSlowRebound = 0;
	m_LeftRideHeight = _T("20.0");
	m_RightRideHeight = _T("20.0");
	//}}AFX_DATA_INIT
	m_SetupFile=NULL;
}

CRear::~CRear()
{
}

void CRear::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRear)
	DDX_Control(pDX, IDC_SLIDER_LEFT_REAR_RIDEHEIGHT, m_SliderLeftRideHeight);
	DDX_Control(pDX, IDC_SLIDER_RIGHT_REAR_RIDEHEIGHT, m_SliderRightRideHeight);
	DDX_Control(pDX, IDC_SPIN_LEFT_REAR_DUMPER, m_SpinLeftDumper);
	DDX_Control(pDX, IDC_SPIN_LEFT_REAR_FAST_REBOUND, m_SpinLeftFastRebound);
	DDX_Control(pDX, IDC_SPIN_LEFT_REAR_PACKERS, m_SpinLeftPackers);
	DDX_Control(pDX, IDC_SPIN_LEFT_REAR_SLOW_BUMP, m_SpinLeftSlowBump);
	DDX_Control(pDX, IDC_SPIN_LEFT_REAR_SLOW_REBOUND, m_SpinLeftSlowRebound);
	DDX_Control(pDX, IDC_SPIN_RIGHT_REAR_DUMPER, m_SpinRightDumper);
	DDX_Control(pDX, IDC_SPIN_RIGHT_REAR_FAST_REBOUND, m_SpinRightFastRebound);
	DDX_Control(pDX, IDC_SPIN_RIGHT_REAR_PACKERS, m_SpinRightPackers);
	DDX_Control(pDX, IDC_SPIN_RIGHT_REAR_SLOW_BUMP, m_SpinRightSlowBump);
	DDX_Control(pDX, IDC_SPIN_RIGHT_REAR_SLOW_REBOUND, m_SpinRightSlowRebound);
	DDX_CBIndex(pDX, IDC_COMBO_REAR_ANTIROLLBAR, m_AntiRollBar);
	DDX_CBIndex(pDX, IDC_COMBO_LEFT_REAR_SPRING, m_LeftSpring);
	DDX_CBIndex(pDX, IDC_COMBO_RIGHT_REAR_SPRING, m_RightSpring);
	DDX_Text(pDX, IDC_EDIT_LEFT_REAR_DUMPER, m_LeftDumper);
	DDV_MinMaxInt(pDX, m_LeftDumper, 0, 8);
	DDX_Text(pDX, IDC_EDIT_LEFT_REAR_FAST_REBOUND, m_LeftFastRebound);
	DDV_MinMaxInt(pDX, m_LeftFastRebound, 0, 8);
	DDX_Text(pDX, IDC_EDIT_LEFT_REAR_PACKERS, m_LeftPackers);
	DDV_MinMaxInt(pDX, m_LeftPackers, 0, 80);
	DDX_Text(pDX, IDC_EDIT_LEFT_REAR_SLOW_BUMP, m_LeftSlowBump);
	DDV_MinMaxInt(pDX, m_LeftSlowBump, 0, 24);
	DDX_Text(pDX, IDC_EDIT_LEFT_REAR_SLOW_REBOUND, m_LeftSlowRebound);
	DDV_MinMaxInt(pDX, m_LeftSlowRebound, 0, 24);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REAR_DUMPER, m_RightDumper);
	DDV_MinMaxInt(pDX, m_RightDumper, 0, 8);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REAR_FAST_REBOUND, m_RightFastRebound);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REAR_PACKERS, m_RightPackers);
	DDV_MinMaxInt(pDX, m_RightPackers, 0, 80);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REAR_SLOW_BUMP, m_RightSlowBump);
	DDV_MinMaxInt(pDX, m_RightSlowBump, 0, 24);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REAR_SLOW_REBOUND, m_RightSlowRebound);
	DDV_MinMaxInt(pDX, m_RightSlowRebound, 0, 24);
	DDX_Text(pDX, IDC_LABLE_LEFT_REAR_RIDEHEIGHT_DISPLAY, m_LeftRideHeight);
	DDX_Text(pDX, IDC_LABLE_RIGHT_REAR_RIDEHEIGHT_DISPLAY, m_RightRideHeight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRear, CPropertyPage)
	//{{AFX_MSG_MAP(CRear)
	ON_WM_HSCROLL()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRear message handlers

void CRear::EnableControls(bool enable)
{
	GetDlgItem(IDC_FRAME_LEFT_REAR)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_FASTREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_SLOWBUMP)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_SLOWREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_REAR_RIDEHEIGHT_DISPLAY)->EnableWindow(enable);
	GetDlgItem(IDC_SLIDER_LEFT_REAR_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_LEFT_REAR_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_REAR_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_REAR_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_REAR_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_RIGHT_REAR)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_FASTREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_SLOWBUMP)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_SLOWREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_REAR_RIDEHEIGHT_DISPLAY)->EnableWindow(enable);
	GetDlgItem(IDC_SLIDER_RIGHT_REAR_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_RIGHT_REAR_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_REAR_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_REAR_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_REAR_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_REAR_ANTIROLLBAR)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_REAR_ANTIROLLBAR)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_REAR_ANTIROLLBAR)->EnableWindow(enable);

	GetDlgItem(IDC_SPIN_LEFT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_REAR_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_REAR_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_REAR_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_REAR_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_REAR_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_REAR_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_REAR_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_REAR_SLOW_REBOUND)->EnableWindow(enable);
}

bool CRear::LoadSetup()
{
	m_AntiRollBar=m_SetupFile->GetRearAntiRollBar(m_Id);
	m_LeftPackers=m_SetupFile->GetLeftRearPackers(m_Id);
	m_RightPackers=m_SetupFile->GetRightRearPackers(m_Id);
	m_LeftDumper=m_SetupFile->GetLeftRearDumperFastBump(m_Id);
	m_RightDumper=m_SetupFile->GetRightRearDumperFastBump(m_Id);
	m_LeftSlowBump=m_SetupFile->GetLeftRearSlowBump(m_Id);
	m_RightSlowBump=m_SetupFile->GetRightRearSlowBump(m_Id);
	m_LeftFastRebound=m_SetupFile->GetLeftRearFastRebound(m_Id);
	m_RightFastRebound=m_SetupFile->GetRightRearFastRebound(m_Id);
	m_LeftSlowRebound=m_SetupFile->GetLeftRearSlowRebound(m_Id);
	m_RightSlowRebound=m_SetupFile->GetRightRearSlowRebound(m_Id);
	m_LeftSpring=(m_SetupFile->GetLeftRearSpring(m_Id)-60)/10;
	m_RightSpring=(m_SetupFile->GetRightRearSpring(m_Id)-60)/10;
	m_SliderLeftRideHeight.SetPos(m_SetupFile->GetLeftRearRideHeight(m_Id)-40);
	m_SliderRightRideHeight.SetPos(m_SetupFile->GetRightRearRideHeight(m_Id)-40);
	UpdateData(FALSE);
	UpdateRideHeight();
	return(true);
}

BOOL CRear::OnSetActive() 
{
	if(m_SetupFile!=NULL)
		LoadSetup();
	return CPropertyPage::OnSetActive();
}

void CRear::SetGpXSetupFile(CSetupFile *Setup,int id)
{
	m_SetupFile=Setup;
	m_Id=id;
}

void CRear::InitControls()
{
	m_SpinLeftDumper.SetRange(0,8);
	m_SpinLeftFastRebound.SetRange(0,8);
	m_SpinLeftPackers.SetRange(0,80);
	m_SpinLeftSlowBump.SetRange(0,24);
	m_SpinLeftSlowRebound.SetRange(0,24);
	m_SpinRightDumper.SetRange(0,8);
	m_SpinRightFastRebound.SetRange(0,8);
	m_SpinRightPackers.SetRange(0,80);
	m_SpinRightSlowBump.SetRange(0,24);
	m_SpinRightSlowRebound.SetRange(0,24);
	m_SliderLeftRideHeight.SetRange(0,120);
	m_SliderRightRideHeight.SetRange(0,120);
}

void CRear::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UpdateRideHeight();	
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CRear::UpdateRideHeight()
{
	UpdateData(TRUE);
	char *cBuffer = new char[50];
	int iPos=m_SliderLeftRideHeight.GetPos();
	sprintf(cBuffer,"%.1f",(double)(iPos+40)/2);
	m_LeftRideHeight=cBuffer;
	iPos=m_SliderRightRideHeight.GetPos();
	sprintf(cBuffer,"%.1f",(double)(iPos+40)/2);
	m_RightRideHeight=cBuffer;
	delete[] cBuffer;
	UpdateData(FALSE);
}

void CRear::SaveSetup()
{
	UpdateData(TRUE);
	m_SetupFile->SetRearAntiRollBar(m_AntiRollBar,m_Id);
	m_SetupFile->SetLeftRearPackers(m_LeftPackers,m_Id);
	m_SetupFile->SetRightRearPackers(m_RightPackers,m_Id);
	m_SetupFile->SetLeftRearDumperFastBump(m_LeftDumper,m_Id);
	m_SetupFile->SetRightRearDumperFastBump(m_RightDumper,m_Id);
	m_SetupFile->SetLeftRearSlowBump(m_LeftSlowBump,m_Id);
	m_SetupFile->SetRightRearSlowBump(m_RightSlowBump,m_Id);
	m_SetupFile->SetLeftRearFastRebound(m_LeftFastRebound,m_Id);
	m_SetupFile->SetRightRearFastRebound(m_RightFastRebound,m_Id);
	m_SetupFile->SetLeftRearSlowRebound(m_LeftSlowRebound,m_Id);
	m_SetupFile->SetRightRearSlowRebound(m_RightSlowRebound,m_Id);
	m_SetupFile->SetLeftRearSpring((m_LeftSpring*10)+60,m_Id);
	m_SetupFile->SetRightRearSpring((m_RightSpring*10)+60,m_Id);
	m_SetupFile->SetLeftRearRideHeight(m_SliderLeftRideHeight.GetPos()+40);
	m_SetupFile->SetRightRearRideHeight(m_SliderRightRideHeight.GetPos()+40,m_Id);
}

void CRear::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	if(bShow==false)
		SaveSetup();
}

BOOL CRear::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	InitControls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
