// WorkDesign.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "WorkDesign.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkDesign

IMPLEMENT_DYNCREATE(CWorkDesign, CFormView)

CWorkDesign::CWorkDesign()
	: CFormView(CWorkDesign::IDD)
{
	//{{AFX_DATA_INIT(CWorkDesign)
		// NOTE: the ClassWizard will add member initialization here
	m_ActiveSuspension = 0;
	m_AutomaticGears = 0;
	m_PowerBreakes = 0;
	m_TractionControl = 0;
	m_Performence_Breakes = 0;
	m_Performence_Clutch = 0;
	m_Performence_Electronics = 0;
	m_Performence_Gearbox = 0;
	m_Performence_Hydraulics = 0;
	m_Performence_Suspension = 0;
	m_Performence_Throttle = 0;
	m_Reliability_Clutch = 0;
	m_Reliability_Electronics = 0;
	m_Reliability_Gearbox = 0;
	m_Reliability_Hydraulics = 0;
	m_Reliability_Suspension = 0;
	m_Reliability_Breakes = 0;
	m_Reliability_Throttle = 0;
	//}}AFX_DATA_INIT
}

CWorkDesign::~CWorkDesign()
{
}

void CWorkDesign::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkDesign)
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_ELECTRONICS, m_Spin_Reliability_Electronics);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_HYDRAULICS, m_Spin_Reliability_Hydraulics);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_SUSPENSION, m_Spin_Reliability_Suspension);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_THROTTLE, m_Spin_Reliability_Throttle);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_GEARBOX, m_Spin_Reliability_Gearbox);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_CLUTCH, m_Spin_Reliability_Clutch);
	DDX_Control(pDX, IDC_SPIN_RELIABILITY_BREAKES, m_Spin_Reliability_Breakes);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_THROTTLE, m_Spin_Performence_Throttle);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_SUSPENSION, m_Spin_Performence_Suspension);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_HYDRAULICS, m_Spin_Performence_Hydraulics);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_GEARBOX, m_Spin_Performence_Gearbox);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_ELECTRONICS, m_Spin_Performence_Electronics);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_CLUTCH, m_Spin_Performence_Clutch);
	DDX_Control(pDX, IDC_SPIN_PERFORMENCE_BREAKES, m_Spin_Performence_Breakes);
	DDX_Control(pDX, IDC_SPIN_ACTIVESUSPENSION, m_Spin_ActiveSuspension);
	DDX_Control(pDX, IDC_SPIN_AUTOMATICGEARS, m_Spin_AutomaticGears);
	DDX_Control(pDX, IDC_SPIN_POWERBREAKES, m_Spin_Powerbreakes);
	DDX_Control(pDX, IDC_SPIN_TRACTIONCONTROL, m_Spin_Tractioncontrol);
	DDX_Text(pDX, IDC_EDIT_ACTIVESUSPENSION, m_ActiveSuspension);
	DDV_MinMaxInt(pDX, m_ActiveSuspension, 0, 5);
	DDX_Text(pDX, IDC_EDIT_AUTOMATICGEARS, m_AutomaticGears);
	DDV_MinMaxInt(pDX, m_AutomaticGears, 0, 5);
	DDX_Text(pDX, IDC_EDIT_POWERBREAKS, m_PowerBreakes);
	DDV_MinMaxInt(pDX, m_PowerBreakes, 0, 5);
	DDX_Text(pDX, IDC_EDIT_TRACTIONCONTROL, m_TractionControl);
	DDV_MinMaxInt(pDX, m_TractionControl, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_BREAKES, m_Performence_Breakes);
	DDV_MinMaxInt(pDX, m_Performence_Breakes, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_CLUTCH, m_Performence_Clutch);
	DDV_MinMaxInt(pDX, m_Performence_Clutch, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_ELECTRONICS, m_Performence_Electronics);
	DDV_MinMaxInt(pDX, m_Performence_Electronics, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_GEARBOX, m_Performence_Gearbox);
	DDV_MinMaxInt(pDX, m_Performence_Gearbox, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_HYDRAULICS, m_Performence_Hydraulics);
	DDV_MinMaxInt(pDX, m_Performence_Hydraulics, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_SUSPENSION, m_Performence_Suspension);
	DDV_MinMaxInt(pDX, m_Performence_Suspension, 0, 5);
	DDX_Text(pDX, IDC_EDIT_PERFORMENCE_THROTTLE, m_Performence_Throttle);
	DDV_MinMaxInt(pDX, m_Performence_Throttle, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_CLUTCH, m_Reliability_Clutch);
	DDV_MinMaxInt(pDX, m_Reliability_Clutch, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_ELECTRONICS, m_Reliability_Electronics);
	DDV_MinMaxInt(pDX, m_Reliability_Electronics, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_GEARBOX, m_Reliability_Gearbox);
	DDV_MinMaxInt(pDX, m_Reliability_Gearbox, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_HYDRAULICS, m_Reliability_Hydraulics);
	DDV_MinMaxInt(pDX, m_Reliability_Hydraulics, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_SUSPENSION, m_Reliability_Suspension);
	DDV_MinMaxInt(pDX, m_Reliability_Suspension, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_BREAKES, m_Reliability_Breakes);
	DDV_MinMaxInt(pDX, m_Reliability_Breakes, 0, 5);
	DDX_Text(pDX, IDC_EDIT_RELIABILITY_THROTTLE, m_Reliability_Throttle);
	DDV_MinMaxInt(pDX, m_Reliability_Throttle, 0, 5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkDesign, CFormView)
	//{{AFX_MSG_MAP(CWorkDesign)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkDesign diagnostics

#ifdef _DEBUG
void CWorkDesign::AssertValid() const
{
	CFormView::AssertValid();
}

void CWorkDesign::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorkDesign message handlers

void CWorkDesign::Load(int id, CString file)
{
CFile f;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);

	f.Seek(2396604+(id*764),CFile::begin);
	f.Read((char*)&m_Performence_Breakes ,sizeof(int));
	f.Read((char*)&m_Performence_Clutch,sizeof(int));
	f.Read((char*)&m_Performence_Electronics,sizeof(int));
	f.Read((char*)&m_Performence_Gearbox,sizeof(int));
	f.Read((char*)&m_Performence_Hydraulics,sizeof(int));
	f.Read((char*)&m_Performence_Suspension,sizeof(int));
	f.Read((char*)&m_Performence_Throttle,sizeof(int));

	f.Read((char*)&m_Reliability_Breakes,sizeof(int));
	f.Read((char*)&m_Reliability_Clutch,sizeof(int));
	f.Read((char*)&m_Reliability_Electronics,sizeof(int));
	f.Read((char*)&m_Reliability_Gearbox,sizeof(int));
	f.Read((char*)&m_Reliability_Hydraulics,sizeof(int));
	f.Read((char*)&m_Reliability_Suspension,sizeof(int));
	f.Read((char*)&m_Reliability_Throttle,sizeof(int));

	f.Seek(2396820+(id*764),CFile::begin);
	f.Read((char*)&m_ActiveSuspension,sizeof(int));
	f.Read((char*)&m_AutomaticGears,sizeof(int));
	f.Read((char*)&m_PowerBreakes,sizeof(int));
	f.Read((char*)&m_TractionControl,sizeof(int));

	f.Close();

	UpdateData(FALSE);
}

void CWorkDesign::Save(CString file)
{
CFile f;
int i;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(2396604+(m_Id*764),CFile::begin);
	for(i=0;i<2;i++)
	{
		f.Write((char*)&m_Performence_Breakes ,sizeof(int));
		f.Write((char*)&m_Performence_Clutch,sizeof(int));
		f.Write((char*)&m_Performence_Electronics,sizeof(int));
		f.Write((char*)&m_Performence_Gearbox,sizeof(int));
		f.Write((char*)&m_Performence_Hydraulics,sizeof(int));
		f.Write((char*)&m_Performence_Suspension,sizeof(int));
		f.Write((char*)&m_Performence_Throttle,sizeof(int));

		f.Write((char*)&m_Reliability_Breakes,sizeof(int));
		f.Write((char*)&m_Reliability_Clutch,sizeof(int));
		f.Write((char*)&m_Reliability_Electronics,sizeof(int));
		f.Write((char*)&m_Reliability_Gearbox,sizeof(int));
		f.Write((char*)&m_Reliability_Hydraulics,sizeof(int));
		f.Write((char*)&m_Reliability_Suspension,sizeof(int));
		f.Write((char*)&m_Reliability_Throttle,sizeof(int));
	}

	f.Seek(2396820+(m_Id*764),CFile::begin);
	for(i=0;i<2;i++)
	{
		f.Write((char*)&m_ActiveSuspension,sizeof(int));
		f.Write((char*)&m_AutomaticGears,sizeof(int));
		f.Write((char*)&m_PowerBreakes,sizeof(int));
		f.Write((char*)&m_TractionControl,sizeof(int));
		f.Seek(16,CFile::current);
	}

	f.Close();
}

void CWorkDesign::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
}

void CWorkDesign::SetSpin()
{
	m_Spin_ActiveSuspension.SetRange(0,5);
	m_Spin_AutomaticGears.SetRange(0,5);
	m_Spin_Performence_Breakes.SetRange(0,5);
	m_Spin_Performence_Clutch.SetRange(0,5);
	m_Spin_Performence_Electronics.SetRange(0,5);
	m_Spin_Performence_Gearbox.SetRange(0,5);
	m_Spin_Performence_Hydraulics.SetRange(0,5);
	m_Spin_Performence_Suspension.SetRange(0,5);
	m_Spin_Performence_Throttle.SetRange(0,5);
	m_Spin_Powerbreakes.SetRange(0,5);
	m_Spin_Reliability_Breakes.SetRange(0,5);
	m_Spin_Reliability_Clutch.SetRange(0,5);
	m_Spin_Reliability_Electronics.SetRange(0,5);
	m_Spin_Reliability_Gearbox.SetRange(0,5);
	m_Spin_Reliability_Hydraulics.SetRange(0,5);
	m_Spin_Reliability_Suspension.SetRange(0,5);
	m_Spin_Reliability_Throttle.SetRange(0,5);
	m_Spin_Tractioncontrol.SetRange(0,5);
}
