// Misc.cpp : implementation file
//

#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "Misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMisc property page

IMPLEMENT_DYNCREATE(CMisc, CPropertyPage)

CMisc::CMisc() : CPropertyPage(CMisc::IDD)
{
	//{{AFX_DATA_INIT(CMisc)
	m_Gear1 = 16;
	m_Gear2 = 17;
	m_Gear3 = 18;
	m_Gear4 = 19;
	m_Gear5 = 20;
	m_Gear6 = 21;
	m_FrontWing = 1;
	m_RearWing = 1;
	m_FirstStop = 0;
	m_SecondStop = 0;
	m_ThirdStop = 0;
	m_BrakeBalance = _T("");
	m_RadioNone = 0;
	m_RadioOne = -1;
	m_RadioTwo = -1;
	m_RadioThree = -1;
	m_Differential = 0;
	m_TyreChoice = 0;
	//}}AFX_DATA_INIT
	m_SetupFile=NULL;
}

CMisc::~CMisc()
{
}

void CMisc::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMisc)
	DDX_Control(pDX, IDC_SLIDER_BRAKE_BALANCE, m_SliderBrakeBalance);
	DDX_Control(pDX, IDC_SPIN_PITSTOP_THIRDSTOP, m_SpinThirdStop);
	DDX_Control(pDX, IDC_SPIN_PITSTOP_SECONDSTOP, m_SpinSecondStop);
	DDX_Control(pDX, IDC_SPIN_PITSTOP_FIRSTSTOP, m_SpinFirstStop);
	DDX_Control(pDX, IDC_SPIN_MISC_REAR_WING, m_SpinRearWing);
	DDX_Control(pDX, IDC_SPIN_MISC_FRONT_WING, m_SpinFrontWing);
	DDX_Control(pDX, IDC_SPIN_GEAR_6, m_SpinGear6);
	DDX_Control(pDX, IDC_SPIN_GEAR_5, m_SpinGear5);
	DDX_Control(pDX, IDC_SPIN_GEAR_4, m_SpinGear4);
	DDX_Control(pDX, IDC_SPIN_GEAR_3, m_SpinGear3);
	DDX_Control(pDX, IDC_SPIN_GEAR_1, m_SpinGear1);
	DDX_Control(pDX, IDC_SPIN_GEAR_2, m_SpinGear2);
	DDX_Text(pDX, IDC_EDIT_GEAR_1, m_Gear1);
	DDV_MinMaxInt(pDX, m_Gear1, 16, 75);
	DDX_Text(pDX, IDC_EDIT_GEAR_2, m_Gear2);
	DDV_MinMaxInt(pDX, m_Gear2, 17, 76);
	DDX_Text(pDX, IDC_EDIT_GEAR_4, m_Gear4);
	DDV_MinMaxInt(pDX, m_Gear4, 19, 78);
	DDX_Text(pDX, IDC_EDIT_GEAR_5, m_Gear5);
	DDV_MinMaxInt(pDX, m_Gear5, 20, 79);
	DDX_Text(pDX, IDC_EDIT_GEAR_6, m_Gear6);
	DDV_MinMaxInt(pDX, m_Gear6, 21, 80);
	DDX_Text(pDX, IDC_EDIT_GEAR_3, m_Gear3);
	DDV_MinMaxInt(pDX, m_Gear3, 18, 77);
	DDX_Text(pDX, IDC_EDIT_MISC_FRONT_WING, m_FrontWing);
	DDV_MinMaxInt(pDX, m_FrontWing, 1, 20);
	DDX_Text(pDX, IDC_EDIT_MISC_REAR_WING, m_RearWing);
	DDV_MinMaxInt(pDX, m_RearWing, 1, 20);
	DDX_Text(pDX, IDC_EDIT_PITSTOP_FIRSTSTOP, m_FirstStop);
	DDV_MinMaxInt(pDX, m_FirstStop, 0, 100);
	DDX_Text(pDX, IDC_EDIT_PITSTOP_SECONDSTOP, m_SecondStop);
	DDV_MinMaxInt(pDX, m_SecondStop, 0, 100);
	DDX_Text(pDX, IDC_EDIT_PITSTOP_THIRDSTOP, m_ThirdStop);
	DDV_MinMaxInt(pDX, m_ThirdStop, 0, 100);
	DDX_Text(pDX, IDC_LABLE_BRAKE_BALANCE_DISPLAY, m_BrakeBalance);
	DDX_Radio(pDX, IDC_RADIO_PITSTOP_NONE, m_RadioNone);
	DDX_Radio(pDX, IDC_RADIO_PITSTOP_ONE_STOP, m_RadioOne);
	DDX_Radio(pDX, IDC_RADIO_PITSTOP_TWO_STOPS, m_RadioTwo);
	DDX_Radio(pDX, IDC_RADIO_PITSTOP_THREE_STOPS, m_RadioThree);
	DDX_CBIndex(pDX, IDC_COMBO_DIFFERENTIAL, m_Differential);
	DDX_CBIndex(pDX, IDC_COMBO_MISC_TYRE_CHOICE, m_TyreChoice);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMisc, CPropertyPage)
	//{{AFX_MSG_MAP(CMisc)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO_PITSTOP_NONE, OnRadioPitstopNone)
	ON_BN_CLICKED(IDC_RADIO_PITSTOP_ONE_STOP, OnRadioPitstopOneStop)
	ON_BN_CLICKED(IDC_RADIO_PITSTOP_THREE_STOPS, OnRadioPitstopThreeStops)
	ON_BN_CLICKED(IDC_RADIO_PITSTOP_TWO_STOPS, OnRadioPitstopTwoStops)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMisc message handlers

void CMisc::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UpdateBrakeBalance();
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMisc::InitControls()
{
	m_SpinFirstStop.SetRange(0,100);
	m_SpinSecondStop.SetRange(0,100);
	m_SpinThirdStop.SetRange(0,100);

	m_SpinFrontWing.SetRange(1,20);
	m_SpinRearWing.SetRange(1,20);

	m_SpinGear1.SetRange(16,75);
	m_SpinGear2.SetRange(17,76);
	m_SpinGear3.SetRange(18,77);
	m_SpinGear4.SetRange(19,78);
	m_SpinGear5.SetRange(20,79);
	m_SpinGear6.SetRange(21,80);

	m_SliderBrakeBalance.SetRange(0,200);

	OnRadioPitstopNone();
	UpdateBrakeBalance();
}

void CMisc::EnableControls(bool enable)
{
	GetDlgItem(IDC_FRAME_PITSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_RADIO_PITSTOP_NONE)->EnableWindow(enable);
	GetDlgItem(IDC_RADIO_PITSTOP_ONE_STOP)->EnableWindow(enable);
	GetDlgItem(IDC_RADIO_PITSTOP_TWO_STOPS)->EnableWindow(enable);
	GetDlgItem(IDC_RADIO_PITSTOP_THREE_STOPS)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_PITSTOP_FIRSTSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_PITSTOP_SECONDSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_PITSTOP_THIRDSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_BRAKE_BALANCE)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_BRAKE_BALANCE_DISPLAY)->EnableWindow(enable);
	GetDlgItem(IDC_SLIDER_BRAKE_BALANCE)->EnableWindow(enable);

	if(m_SetupFile!=NULL&&enable==true&&(m_SetupFile->GetFileType()==2||m_SetupFile->GetFileType()==4))
	{
		GetDlgItem(IDC_FRAME_GP3_SETUP)->EnableWindow(enable);
		GetDlgItem(IDC_LABLE_TYRECHOICE)->EnableWindow(enable);
		GetDlgItem(IDC_COMBO_MISC_TYRE_CHOICE)->EnableWindow(enable);
		GetDlgItem(IDC_LABLE_DIFFERENTIAL)->EnableWindow(enable);
		GetDlgItem(IDC_COMBO_DIFFERENTIAL)->EnableWindow(enable);
	}
	else
	{
		GetDlgItem(IDC_FRAME_GP3_SETUP)->EnableWindow(enable);
		GetDlgItem(IDC_LABLE_TYRECHOICE)->EnableWindow(enable);
		GetDlgItem(IDC_COMBO_MISC_TYRE_CHOICE)->EnableWindow(enable);
		GetDlgItem(IDC_LABLE_DIFFERENTIAL)->EnableWindow(enable);
		GetDlgItem(IDC_COMBO_DIFFERENTIAL)->EnableWindow(enable);
	}
	GetDlgItem(IDC_FRAME_GEARRATIONS)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_1)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_2)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_3)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_4)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_5)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_GEAR_6)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_1)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_2)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_3)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_4)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_5)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_GEAR_6)->EnableWindow(enable);
	GetDlgItem(IDC_FRAME_MISCSETTINGS)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_FRONTWING)->EnableWindow(enable);
	GetDlgItem(IDC_LABLE_REARWING)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_MISC_FRONT_WING)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_MISC_REAR_WING)->EnableWindow(enable);

	GetDlgItem(IDC_SPIN_PITSTOP_THIRDSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_PITSTOP_SECONDSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_PITSTOP_FIRSTSTOP)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_MISC_REAR_WING)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_MISC_FRONT_WING)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_6)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_5)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_4)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_3)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_1)->EnableWindow(enable);
	GetDlgItem(IDC_SPIN_GEAR_2)->EnableWindow(enable);

}

void CMisc::UpdateBrakeBalance()
{
	UpdateData(TRUE);
	char *cBuffer=new char[50];
	int iPos = m_SliderBrakeBalance.GetPos();
	sprintf(cBuffer,"%d:%d",50000-(125*iPos),50000+(125*iPos));
	m_BrakeBalance=cBuffer;
	delete[] cBuffer;
	UpdateData(FALSE);
}

void CMisc::OnRadioPitstopNone() 
{
	UpdateData(TRUE);
	m_RadioNone=0;
	m_RadioOne=1;
	m_RadioTwo=1;
	m_RadioThree=1;
	GetDlgItem(IDC_EDIT_PITSTOP_FIRSTSTOP)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_PITSTOP_SECONDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_SECONDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_FIRSTSTOP)->EnableWindow(false);
	UpdateData(FALSE);
}

void CMisc::OnRadioPitstopOneStop() 
{
	UpdateData(TRUE);
	m_RadioNone=1;
	m_RadioOne=0;
	m_RadioTwo=1;
	m_RadioThree=1;
	GetDlgItem(IDC_EDIT_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_PITSTOP_SECONDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_SECONDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	UpdateData(FALSE);
}

void CMisc::OnRadioPitstopTwoStops() 
{
	UpdateData(TRUE);
	m_RadioNone=1;
	m_RadioOne=1;
	m_RadioTwo=0;
	m_RadioThree=1;
	GetDlgItem(IDC_EDIT_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_PITSTOP_SECONDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_THIRDSTOP)->EnableWindow(false);
	GetDlgItem(IDC_SPIN_PITSTOP_SECONDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_SPIN_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	UpdateData(FALSE);
}

void CMisc::OnRadioPitstopThreeStops() 
{
	UpdateData(TRUE);
	m_RadioNone=1;
	m_RadioOne=1;
	m_RadioTwo=1;
	m_RadioThree=0;
	GetDlgItem(IDC_EDIT_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_PITSTOP_SECONDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_PITSTOP_THIRDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_SPIN_PITSTOP_THIRDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_SPIN_PITSTOP_SECONDSTOP)->EnableWindow(true);
	GetDlgItem(IDC_SPIN_PITSTOP_FIRSTSTOP)->EnableWindow(true);
	UpdateData(FALSE);
}

bool CMisc::LoadSetup()
{
	m_SliderBrakeBalance.SetPos(m_SetupFile->GetBrakeBalans(m_Id));
	m_FrontWing=m_SetupFile->GetFrontWing(m_Id);
	m_RearWing=m_SetupFile->GetRearWing(m_Id);
	m_FirstStop=m_SetupFile->GetFirstStop(m_Id);
	m_SecondStop=m_SetupFile->GetSecondStop(m_Id);
	m_ThirdStop=m_SetupFile->GetThirdStop(m_Id);
	m_Gear1=m_SetupFile->GetGear1(m_Id);
	m_Gear2=m_SetupFile->GetGear2(m_Id);
	m_Gear3=m_SetupFile->GetGear3(m_Id);
	m_Gear4=m_SetupFile->GetGear4(m_Id);
	m_Gear5=m_SetupFile->GetGear5(m_Id);
	m_Gear6=m_SetupFile->GetGear6(m_Id);
	if(m_SetupFile->GetFileType()==2||m_SetupFile->GetFileType()==4)
	{
		m_TyreChoice=m_SetupFile->GetTyreChoice(m_Id);
		m_Differential=m_SetupFile->GetDifferential(m_Id);
		GetDlgItem(IDC_FRAME_GP3_SETUP)->EnableWindow(true);
		GetDlgItem(IDC_LABLE_TYRECHOICE)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_MISC_TYRE_CHOICE)->EnableWindow(true);
		GetDlgItem(IDC_LABLE_DIFFERENTIAL)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_DIFFERENTIAL)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_FRAME_GP3_SETUP)->EnableWindow(false);
		GetDlgItem(IDC_LABLE_TYRECHOICE)->EnableWindow(false);
		GetDlgItem(IDC_COMBO_MISC_TYRE_CHOICE)->EnableWindow(false);
		GetDlgItem(IDC_LABLE_DIFFERENTIAL)->EnableWindow(false);
		GetDlgItem(IDC_COMBO_DIFFERENTIAL)->EnableWindow(false);
	}
	UpdateData(FALSE);
	switch(m_SetupFile->GetNrOfStops(m_Id))
	{
		case 1:
			OnRadioPitstopOneStop();
			break;
		case 2:
			OnRadioPitstopTwoStops();
			break;
		case 3:
			OnRadioPitstopThreeStops();
			break;
		default:
			OnRadioPitstopNone();
			break;
	};
	UpdateBrakeBalance();
	return(true);
}

BOOL CMisc::OnSetActive() 
{
//	InitControls();
	if(m_SetupFile!=NULL)
		LoadSetup();
	return CPropertyPage::OnSetActive();
}

void CMisc::SetGpXSetupFile(CSetupFile *Setup,int id)
{
	m_SetupFile=Setup;
	m_Id=id;
}

void CMisc::SaveSetup()
{
	if(m_SetupFile==NULL)
		return;
	UpdateData(TRUE);
	m_SetupFile->SetBrakeBalans(m_SliderBrakeBalance.GetPos(),m_Id);
	m_SetupFile->SetFrontWing(m_FrontWing,m_Id);
	m_SetupFile->SetRearWing(m_RearWing,m_Id);
	m_SetupFile->SetFirstStop(m_FirstStop,m_Id);
	m_SetupFile->SetSecondStop(m_SecondStop,m_Id);
	m_SetupFile->SetThirdStop(m_ThirdStop,m_Id);
	m_SetupFile->SetGear1(m_Gear1,m_Id);
	m_SetupFile->SetGear2(m_Gear2,m_Id);
	m_SetupFile->SetGear3(m_Gear3,m_Id);
	m_SetupFile->SetGear4(m_Gear4,m_Id);
	m_SetupFile->SetGear5(m_Gear5,m_Id);
	m_SetupFile->SetGear6(m_Gear6,m_Id);
	if(m_RadioNone==0)
		m_SetupFile->SetNrOfStops(0,m_Id);
	else if(m_RadioOne==0)
		m_SetupFile->SetNrOfStops(1,m_Id);
	else if(m_RadioTwo==0)
		m_SetupFile->SetNrOfStops(2,m_Id);
	else if(m_RadioThree==0)
		m_SetupFile->SetNrOfStops(3,m_Id);

	if(m_SetupFile->GetFileType()==2||m_SetupFile->GetFileType()==4)
	{
		m_SetupFile->SetTyreChoice(m_TyreChoice,m_Id);
		m_SetupFile->SetDifferential(m_Differential,m_Id);
	}
}

void CMisc::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	if(bShow==false)
		SaveSetup();
}

BOOL CMisc::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	InitControls();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}