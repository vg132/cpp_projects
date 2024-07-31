// WorkMech.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "WorkMech.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkMech

IMPLEMENT_DYNCREATE(CWorkMech, CFormView)

CWorkMech::CWorkMech()
	: CFormView(CWorkMech::IDD)
{
	//{{AFX_DATA_INIT(CWorkMech)
	m_Car1Damage = 0;
	m_Car1Ware = 0;
	m_Car2Damage = 0;
	m_Car2Ware = 0;
	m_Car3Damage = 0;
	m_Car3Ware = 0;
	m_Car4Damage = 0;
	m_Car4Ware = 0;
	m_FreePractice = 0;
	m_Spares = 0;
	m_Miles = 0;
	m_Cost_Mile = 0;
	//}}AFX_DATA_INIT
}

CWorkMech::~CWorkMech()
{
}

void CWorkMech::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkMech)
	DDX_Control(pDX, IDC_SPIN_CAR1DAMAGE, m_Spin_Car1Damage);
	DDX_Control(pDX, IDC_SPIN_CAR1WARE, m_Spin_Car1Ware);
	DDX_Control(pDX, IDC_SPIN_CAR2DAMAGE, m_Spin_Car2Damage);
	DDX_Control(pDX, IDC_SPIN_CAR2WARE, m_Spin_Car2Ware);
	DDX_Control(pDX, IDC_SPIN_CAR3DAMAGE, m_Spin_Car3Damage);
	DDX_Control(pDX, IDC_SPIN_CAR3WARE, m_Spin_Car3Ware);
	DDX_Control(pDX, IDC_SPIN_CAR4DAMAGE, m_Spin_Car4Damage);
	DDX_Control(pDX, IDC_SPIN_CAR4WARE, m_Spin_Car4Ware);
	DDX_Control(pDX, IDC_SPIN_COST_MILE, m_Spin_Cost_Mile);
	DDX_Control(pDX, IDC_SPIN_FREEPRACTICE, m_Spin_FreePractice);
	DDX_Control(pDX, IDC_SPIN_MILES, m_Spin_Miles);
	DDX_Control(pDX, IDC_SPIN_SPARES, m_Spin_Spares);
	DDX_Text(pDX, IDC_EDIT_CAR1DAMAGE, m_Car1Damage);
	DDV_MinMaxInt(pDX, m_Car1Damage, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR1WARE, m_Car1Ware);
	DDV_MinMaxInt(pDX, m_Car1Ware, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR2DAMAGE, m_Car2Damage);
	DDV_MinMaxInt(pDX, m_Car2Damage, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR2WARE, m_Car2Ware);
	DDV_MinMaxInt(pDX, m_Car2Ware, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR3DAMAGE, m_Car3Damage);
	DDV_MinMaxInt(pDX, m_Car3Damage, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR3WARE, m_Car3Ware);
	DDV_MinMaxInt(pDX, m_Car3Ware, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR4DAMAGE, m_Car4Damage);
	DDV_MinMaxInt(pDX, m_Car4Damage, 0, 100);
	DDX_Text(pDX, IDC_EDIT_CAR4WARE, m_Car4Ware);
	DDV_MinMaxInt(pDX, m_Car4Ware, 0, 100);
	DDX_Text(pDX, IDC_EDIT_FREEPRACTICE, m_FreePractice);
	DDV_MinMaxInt(pDX, m_FreePractice, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_SPARES, m_Spares);
	DDV_MinMaxInt(pDX, m_Spares, 0, 10);
	DDX_Text(pDX, IDC_EDIT_MILES, m_Miles);
	DDV_MinMaxInt(pDX, m_Miles, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_COST_MILE, m_Cost_Mile);
	DDV_MinMaxInt(pDX, m_Cost_Mile, 0, 32000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkMech, CFormView)
	//{{AFX_MSG_MAP(CWorkMech)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkMech diagnostics

#ifdef _DEBUG
void CWorkMech::AssertValid() const
{
	CFormView::AssertValid();
}

void CWorkMech::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorkMech message handlers

void CWorkMech::Load(int id, CString file)
{
CFile f;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);

	f.Seek(2761112+(id*224),CFile::begin);
	f.Read((char*)&m_Spares,sizeof(int));
	f.Seek(16,CFile::current);
	f.Read((char*)&m_Car1Ware,sizeof(int));
	f.Read((char*)&m_Car2Ware,sizeof(int));
	f.Read((char*)&m_Car3Ware,sizeof(int));
	f.Read((char*)&m_Car4Ware,sizeof(int));
	f.Read((char*)&m_Car1Damage,sizeof(int));
	f.Read((char*)&m_Car2Damage,sizeof(int));
	f.Read((char*)&m_Car3Damage,sizeof(int));
	f.Read((char*)&m_Car4Damage,sizeof(int));

	f.Seek(2761212+(id*224),CFile::begin);
	f.Read((char*)&m_Miles,sizeof(int));
	f.Read((char*)&m_Cost_Mile,sizeof(int));
	f.Read((char*)&m_FreePractice,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CWorkMech::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
}

void CWorkMech::SetSpin()
{
	m_Spin_Car1Damage.SetRange(0,100);
	m_Spin_Car2Damage.SetRange(0,100);
	m_Spin_Car3Damage.SetRange(0,100);
	m_Spin_Car4Damage.SetRange(0,100);

	m_Spin_Car1Ware.SetRange(0,100);
	m_Spin_Car2Ware.SetRange(0,100);
	m_Spin_Car3Ware.SetRange(0,100);
	m_Spin_Car4Ware.SetRange(0,100);

	m_Spin_Spares.SetRange(0,10);
	m_Spin_Miles.SetRange(0,32000);
	m_Spin_Cost_Mile.SetRange(0,32000);
	m_Spin_FreePractice.SetRange(0,32000);
}

void CWorkMech::Save(CString file)
{
CFile f;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(2761112+(m_Id*224),CFile::begin);
	f.Write((char*)&m_Spares,sizeof(int));
	f.Seek(16,CFile::current);
	f.Write((char*)&m_Car1Ware,sizeof(int));
	f.Write((char*)&m_Car2Ware,sizeof(int));
	f.Write((char*)&m_Car3Ware,sizeof(int));
	f.Write((char*)&m_Car4Ware,sizeof(int));
	f.Write((char*)&m_Car1Damage,sizeof(int));
	f.Write((char*)&m_Car2Damage,sizeof(int));
	f.Write((char*)&m_Car3Damage,sizeof(int));
	f.Write((char*)&m_Car4Damage,sizeof(int));

	f.Seek(2761212+(m_Id*224),CFile::begin);
	f.Write((char*)&m_Miles,sizeof(int));
	f.Write((char*)&m_Cost_Mile,sizeof(int));
	f.Write((char*)&m_FreePractice,sizeof(int));

	f.Close();
}
