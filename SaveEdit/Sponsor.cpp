// Sponsor.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Sponsor.h"
#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSponsor

IMPLEMENT_DYNCREATE(CSponsor, CFormView)

CSponsor::CSponsor()
	: CFormView(CSponsor::IDD)
{
	//{{AFX_DATA_INIT(CSponsor)
	m_Value1 = 0;
	m_Value10 = 0;
	m_Value2 = 0;
	m_Value3 = 0;
	m_Value6 = 0;
	m_Value4 = 0;
	m_Value5 = 0;
	m_Value7 = 0;
	m_Value8 = 0;
	m_Value9 = 0;
	//}}AFX_DATA_INIT
}

CSponsor::~CSponsor()
{
}

void CSponsor::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSponsor)
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_TYRE, m_Tyre);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_FUEL, m_Fuel);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_TEAM, m_Team);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_ENGINE, m_Engine);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH6, m_Cash6);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH5, m_Cash5);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH4, m_Cash4);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH3, m_Cash3);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH2, m_Cash2);
	DDX_Control(pDX, IDC_TEAMFINANCE_COMBO_CASH1, m_Cash1);
	DDX_Control(pDX, IDC_SPIN_VALUE9, m_Spin_Value9);
	DDX_Control(pDX, IDC_SPIN_VALUE8, m_Spin_Value8);
	DDX_Control(pDX, IDC_SPIN_VALUE7, m_Spin_Value7);
	DDX_Control(pDX, IDC_SPIN_VALUE6, m_Spin_Value6);
	DDX_Control(pDX, IDC_SPIN_VALUE5, m_Spin_Value5);
	DDX_Control(pDX, IDC_SPIN_VALUE4, m_Spin_Value4);
	DDX_Control(pDX, IDC_SPIN_VALUE3, m_Spin_Value3);
	DDX_Control(pDX, IDC_SPIN_VALUE2, m_Spin_Value2);
	DDX_Control(pDX, IDC_SPIN_VALUE10, m_Spin_Value10);
	DDX_Control(pDX, IDC_SPIN_VALUE1, m_Spin_Value1);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE1, m_Value1);
	DDV_MinMaxInt(pDX, m_Value1, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE10, m_Value10);
	DDV_MinMaxInt(pDX, m_Value10, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE2, m_Value2);
	DDV_MinMaxInt(pDX, m_Value2, -1000000000, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE3, m_Value3);
	DDV_MinMaxInt(pDX, m_Value3, -1000000000, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE6, m_Value6);
	DDV_MinMaxInt(pDX, m_Value6, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE4, m_Value4);
	DDV_MinMaxInt(pDX, m_Value4, -1000000000, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE5, m_Value5);
	DDV_MinMaxInt(pDX, m_Value5, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE7, m_Value7);
	DDV_MinMaxInt(pDX, m_Value7, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE8, m_Value8);
	DDV_MinMaxInt(pDX, m_Value8, 0, 1000000000);
	DDX_Text(pDX, IDC_TEAMFINANCE_EDIT_VALUE9, m_Value9);
	DDV_MinMaxInt(pDX, m_Value9, 0, 1000000000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSponsor, CFormView)
	//{{AFX_MSG_MAP(CSponsor)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSponsor diagnostics

#ifdef _DEBUG
void CSponsor::AssertValid() const
{
	CFormView::AssertValid();
}

void CSponsor::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSponsor message handlers

void CSponsor::Load(int id, CString file)
{
CFile f;
int iData;

	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);

	f.Seek(10936+(id*7824),CFile::begin);

	f.Read((char*)&iData,sizeof(int));
	m_Team.SetCurSel(iData-1);
	f.Read((char*)&iData,sizeof(int));
	m_Engine.SetCurSel(iData-11);
	f.Read((char*)&iData,sizeof(int));
	m_Tyre.SetCurSel(iData-8);
	f.Read((char*)&iData,sizeof(int));
	m_Fuel.SetCurSel(iData-19);
	f.Read((char*)&iData,sizeof(int));
	m_Cash1.SetCurSel(iData-28);
	f.Read((char*)&iData,sizeof(int));
	m_Cash2.SetCurSel(iData-28);
	f.Read((char*)&iData,sizeof(int));
	m_Cash3.SetCurSel(iData-28);
	f.Read((char*)&iData,sizeof(int));
	m_Cash4.SetCurSel(iData-28);
	f.Read((char*)&iData,sizeof(int));
	m_Cash5.SetCurSel(iData-28);
	f.Read((char*)&iData,sizeof(int));
	m_Cash6.SetCurSel(iData-28);

	f.Seek(500,CFile::current);

	f.Read((char*)&m_Value1,sizeof(int));
	f.Read((char*)&m_Value2,sizeof(int));
	f.Read((char*)&m_Value3,sizeof(int));
	f.Read((char*)&m_Value4,sizeof(int));
	f.Read((char*)&m_Value5,sizeof(int));
	f.Read((char*)&m_Value6,sizeof(int));
	f.Read((char*)&m_Value7,sizeof(int));
	f.Read((char*)&m_Value8,sizeof(int));
	f.Read((char*)&m_Value9,sizeof(int));
	f.Read((char*)&m_Value10,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CSponsor::FillBox()
{
CLoadText m_Text;
int i;
	m_Text.LoadText();
	for(i=0;i<9;i++)
		m_Fuel.AddString(m_Text.m_Fuel[i]);
	for(i=0;i<7;i++)
		m_Team.AddString(m_Text.m_TeamSponcor[i]);
	for(i=0;i<8;i++)
		m_Engine.AddString(m_Text.m_Engine[i]);
	for(i=0;i<3;i++)
		m_Tyre.AddString(m_Text.m_Tyre[i]);
	for(i=0;i<71;i++)
	{
		m_Cash1.AddString(m_Text.m_Sponsors[i]);
		m_Cash2.AddString(m_Text.m_Sponsors[i]);
		m_Cash3.AddString(m_Text.m_Sponsors[i]);
		m_Cash4.AddString(m_Text.m_Sponsors[i]);
		m_Cash5.AddString(m_Text.m_Sponsors[i]);
		m_Cash6.AddString(m_Text.m_Sponsors[i]);
	}
}

void CSponsor::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	FillBox();
	SetSpin();
}

void CSponsor::SetSpin()
{
	m_Spin_Value1.SetRange32(0,1000000000);
	m_Spin_Value2.SetRange32(-1000000000,1000000000);
	m_Spin_Value3.SetRange32(-1000000000,1000000000);
	m_Spin_Value4.SetRange32(-1000000000,1000000000);
	m_Spin_Value5.SetRange32(0,1000000000);
	m_Spin_Value6.SetRange32(0,1000000000);
	m_Spin_Value7.SetRange32(0,1000000000);
	m_Spin_Value8.SetRange32(0,1000000000);
	m_Spin_Value9.SetRange32(0,1000000000);
	m_Spin_Value10.SetRange32(0,1000000000);
}

void CSponsor::Save(CString file)
{
CFile f;
int iData;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);

	f.Seek(10936+(m_Id*7824),CFile::begin);

	iData=m_Team.GetCurSel()+1;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Engine.GetCurSel()+11;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Tyre.GetCurSel()+8;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Fuel.GetCurSel()+20;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash1.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash2.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash3.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash4.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash5.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));
	iData=m_Cash6.GetCurSel()+28;
	f.Write((char*)&iData,sizeof(int));

	f.Seek(500,CFile::current);

	f.Write((char*)&m_Value1,sizeof(int));
	f.Write((char*)&m_Value2,sizeof(int));
	f.Write((char*)&m_Value3,sizeof(int));
	f.Write((char*)&m_Value4,sizeof(int));
	f.Write((char*)&m_Value5,sizeof(int));
	f.Write((char*)&m_Value6,sizeof(int));
	f.Write((char*)&m_Value7,sizeof(int));
	f.Write((char*)&m_Value8,sizeof(int));
	f.Write((char*)&m_Value9,sizeof(int));
	f.Write((char*)&m_Value10,sizeof(int));

}
