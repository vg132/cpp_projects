// Front.cpp : implementation file
//

#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "Front.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFront property page

IMPLEMENT_DYNCREATE(CFront, CPropertyPage)

CFront::CFront() : CPropertyPage(CFront::IDD)
{
	//{{AFX_DATA_INIT(CFront)
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
	m_LeftRideHeight = _T("15.0");
	m_RightRideHeight = _T("15.0");
	//}}AFX_DATA_INIT
	m_SetupFile=NULL;
}

CFront::~CFront()
{
}

void CFront::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFront)
	DDX_Control(pDX, IDC_SLIDER_RIGHT_FRONT_RIDEHEIGHT, m_SliderRightRideHeight);
	DDX_Control(pDX, IDC_SLIDER_LEFT_FRONT_RIDEHEIGHT, m_SliderLeftRideHeight);
	DDX_Control(pDX, IDC_SPIN_RIGHT_FRONT_SLOW_REBOUND, m_SpinRightSlowRebound);
	DDX_Control(pDX, IDC_SPIN_RIGHT_FRONT_SLOW_BUMP, m_SpinRightSlowBump);
	DDX_Control(pDX, IDC_SPIN_RIGHT_FRONT_PACKERS, m_SpinRightPackers);
	DDX_Control(pDX, IDC_SPIN_RIGHT_FRONT_FAST_REBOUND, m_SpinRightFastRebound);
	DDX_Control(pDX, IDC_SPIN_RIGHT_FRONT_DUMPER, m_SpinRightDumper);
	DDX_Control(pDX, IDC_SPIN_LEFT_FRONT_SLOW_REBOUND, m_SpinLeftSlowRebound);
	DDX_Control(pDX, IDC_SPIN_LEFT_FRONT_SLOW_BUMP, m_SpinLeftSlowBump);
	DDX_Control(pDX, IDC_SPIN_LEFT_FRONT_PACKERS, m_SpinLeftPackers);
	DDX_Control(pDX, IDC_SPIN_LEFT_FRONT_FAST_REBOUND, m_SpinLeftFastRebound);
	DDX_Control(pDX, IDC_SPIN_LEFT_FRONT_DUMPER, m_SpinLeftDumper);
	DDX_CBIndex(pDX, IDC_COMBO_FRONT_ANTIROLLBAR, m_AntiRollBar);
	DDX_CBIndex(pDX, IDC_COMBO_LEFT_FRONT_SPRING, m_LeftSpring);
	DDX_CBIndex(pDX, IDC_COMBO_RIGHT_FRONT_SPRING, m_RightSpring);
	DDX_Text(pDX, IDC_EDIT_LEFT_FRONT_DUMPER, m_LeftDumper);
	DDV_MinMaxInt(pDX, m_LeftDumper, 0, 8);
	DDX_Text(pDX, IDC_EDIT_LEFT_FRONT_FAST_REBOUND, m_LeftFastRebound);
	DDV_MinMaxInt(pDX, m_LeftFastRebound, 0, 8);
	DDX_Text(pDX, IDC_EDIT_LEFT_FRONT_PACKERS, m_LeftPackers);
	DDV_MinMaxInt(pDX, m_LeftPackers, 0, 40);
	DDX_Text(pDX, IDC_EDIT_LEFT_FRONT_SLOW_BUMP, m_LeftSlowBump);
	DDV_MinMaxInt(pDX, m_LeftSlowBump, 0, 24);
	DDX_Text(pDX, IDC_EDIT_LEFT_FRONT_SLOW_REBOUND, m_LeftSlowRebound);
	DDV_MinMaxInt(pDX, m_LeftSlowRebound, 0, 24);
	DDX_Text(pDX, IDC_EDIT_RIGHT_FRONT_DUMPER, m_RightDumper);
	DDV_MinMaxInt(pDX, m_RightDumper, 0, 8);
	DDX_Text(pDX, IDC_EDIT_RIGHT_FRONT_FAST_REBOUND, m_RightFastRebound);
	DDV_MinMaxInt(pDX, m_RightFastRebound, 0, 8);
	DDX_Text(pDX, IDC_EDIT_RIGHT_FRONT_PACKERS, m_RightPackers);
	DDV_MinMaxInt(pDX, m_RightPackers, 0, 40);
	DDX_Text(pDX, IDC_EDIT_RIGHT_FRONT_SLOW_BUMP, m_RightSlowBump);
	DDV_MinMaxInt(pDX, m_RightSlowBump, 0, 24);
	DDX_Text(pDX, IDC_EDIT_RIGHT_FRONT_SLOW_REBOUND, m_RightSlowRebound);
	DDV_MinMaxInt(pDX, m_RightSlowRebound, 0, 24);
	DDX_Text(pDX, IDC_LABLE_LEFT_FRONT_RIDEHEIGHT_DISPLAY, m_LeftRideHeight);
	DDX_Text(pDX, IDC_LABLE_RIGHT_FRONT_RIDEHEIGHT_DISPLAY, m_RightRideHeight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFront, CPropertyPage)
	//{{AFX_MSG_MAP(CFront)
	ON_WM_HSCROLL()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFront message handlers

void CFront::EnableControls(bool enable)
{
	GetDlgItem(IDC_FRAME_LEFT_FRONT)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_RIGHT_FRONT)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_FRONT_ANTIROLLBAR)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_FRONT_ANTIROLLBAR)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_FRONT_ANTIROLLBAR)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_FRONT_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_FRONT_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_FASTREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_FRONT_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_SLOWBUMP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_FRONT_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_SLOWREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LEFT_FRONT_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_LEFT_FRONT_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_LEFT_FRONT_RIDEHEIGHT_DISPLAY)->EnableWindow(enable);
	GetDlgItem(IDC_SLIDER_LEFT_FRONT_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_FRONT_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_FRONT_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_FRONT_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_FRONT_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_RIGHT_FRONT_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_COMBO_RIGHT_FRONT_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_SLIDER_RIGHT_FRONT_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_RIDEHEIGHT_DISPLAY)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_RIDEHEIGHT)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_SPRING)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_SLOWREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_SLOWBUMP)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_FASTREBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_DAMPER)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_RIGHT_FRONT_PACKERS)->EnableWindow(enable);

	GetDlgItem(IDC_SPIN_RIGHT_FRONT_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_FRONT_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_FRONT_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_FRONT_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_RIGHT_FRONT_DUMPER)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_FRONT_SLOW_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_FRONT_SLOW_BUMP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_FRONT_PACKERS)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_FRONT_FAST_REBOUND)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_LEFT_FRONT_DUMPER)->EnableWindow(enable);
}

bool CFront::LoadSetup()
{
	m_AntiRollBar=m_SetupFile->GetFrontAntiRollBar(m_Id);
	m_LeftPackers=m_SetupFile->GetLeftFrontPackers(m_Id);
	m_RightPackers=m_SetupFile->GetRightFrontPackers(m_Id);
	m_LeftDumper=m_SetupFile->GetLeftFrontDumperFastBump(m_Id);
	m_RightDumper=m_SetupFile->GetRightFrontDumperFastBump(m_Id);
	m_LeftSlowBump=m_SetupFile->GetLeftFrontSlowBump(m_Id);
	m_RightSlowBump=m_SetupFile->GetRightFrontSlowBump(m_Id);
	m_LeftFastRebound=m_SetupFile->GetLeftFrontFastRebound(m_Id);
	m_RightFastRebound=m_SetupFile->GetRightFrontFastRebound(m_Id);
	m_LeftSlowRebound=m_SetupFile->GetLeftFrontSlowRebound(m_Id);
	m_RightSlowRebound=m_SetupFile->GetRightFrontSlowRebound(m_Id);
	m_LeftSpring=(m_SetupFile->GetLeftFrontSpring(m_Id)-80)/10;
	m_RightSpring=(m_SetupFile->GetRightFrontSpring(m_Id)-80)/10;
	m_SliderLeftRideHeight.SetPos(m_SetupFile->GetLeftFrontRideHeight(m_Id)-30);
	m_SliderRightRideHeight.SetPos(m_SetupFile->GetRightFrontRideHeight(m_Id)-30);
	UpdateData(FALSE);
	UpdateRideHeight();
	return(true);
}

BOOL CFront::OnSetActive() 
{
	if(m_SetupFile!=NULL)
		LoadSetup();
	return CPropertyPage::OnSetActive();
}

void CFront::SetGpXSetupFile(CSetupFile *Setup, int id)
{
	m_SetupFile=Setup;
	m_Id=id;
}

void CFront::InitControls()
{
	m_SpinRightSlowRebound.SetRange(0,24);
	m_SpinRightSlowBump.SetRange(0,24);
	m_SpinRightPackers.SetRange(0,40);
	m_SpinRightFastRebound.SetRange(0,8);
	m_SpinRightDumper.SetRange(0,8);
	m_SpinLeftSlowRebound.SetRange(0,24);
	m_SpinLeftSlowBump.SetRange(0,24);
	m_SpinLeftPackers.SetRange(0,40);
	m_SpinLeftFastRebound.SetRange(0,8);
	m_SpinLeftDumper.SetRange(0,8);
	m_SliderLeftRideHeight.SetRange(0,70);
	m_SliderRightRideHeight.SetRange(0,70);
}

void CFront::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UpdateRideHeight();
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CFront::UpdateRideHeight()
{
	UpdateData(TRUE);
	char *cBuffer = new char[50];
	int iPos=m_SliderLeftRideHeight.GetPos();
	sprintf(cBuffer,"%.1f",(double)(iPos+30)/2);
	m_LeftRideHeight=cBuffer;
	iPos=m_SliderRightRideHeight.GetPos();
	sprintf(cBuffer,"%.1f",(double)(iPos+30)/2);
	m_RightRideHeight=cBuffer;
	delete[] cBuffer;
	UpdateData(FALSE);
}

void CFront::SaveSetup()
{
	UpdateData(TRUE);
	m_SetupFile->SetFrontAntiRollBar(m_AntiRollBar,m_Id);
	m_SetupFile->SetLeftFrontPackers(m_LeftPackers,m_Id);
	m_SetupFile->SetRightFrontPackers(m_RightPackers,m_Id);
	m_SetupFile->SetLeftFrontDumperFastBump(m_LeftDumper,m_Id);
	m_SetupFile->SetRightFrontDumperFastBump(m_RightDumper,m_Id);
	m_SetupFile->SetLeftFrontSlowBump(m_LeftSlowBump,m_Id);
	m_SetupFile->SetRightFrontSlowBump(m_RightSlowBump,m_Id);
	m_SetupFile->SetLeftFrontFastRebound(m_LeftFastRebound,m_Id);
	m_SetupFile->SetRightFrontFastRebound(m_RightFastRebound,m_Id);
	m_SetupFile->SetLeftFrontSlowRebound(m_LeftSlowRebound,m_Id);
	m_SetupFile->SetRightFrontSlowRebound(m_RightSlowRebound,m_Id);
	m_SetupFile->SetLeftFrontSpring((m_LeftSpring*10)+80,m_Id);
	m_SetupFile->SetRightFrontSpring((m_RightSpring*10)+80,m_Id);
	m_SetupFile->SetLeftFrontRideHeight(m_SliderLeftRideHeight.GetPos()+30,m_Id);
	m_SetupFile->SetRightFrontRideHeight(m_SliderRightRideHeight.GetPos()+30,m_Id);
}
void CFront::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	if(bShow==false)
		SaveSetup();	
}

BOOL CFront::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	InitControls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}