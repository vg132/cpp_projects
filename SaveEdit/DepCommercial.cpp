// DepCommercial.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "DepCommercial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepCommercial

IMPLEMENT_DYNCREATE(CDepCommercial, CFormView)

CDepCommercial::CDepCommercial()
	: CFormView(CDepCommercial::IDD)
{
	//{{AFX_DATA_INIT(CDepCommercial)
	m_Available = 0;
	m_Morale = 0;
	m_Standard_Average = 0;
	m_Standard_Excellent = 0;
	m_Standard_Good = 0;
	m_Standard_Trainee = 0;
	m_Standard_VeryGood = 0;
	m_Stars_Average = 0;
	m_Stars_Excellent = 0;
	m_Stars_Good = 0;
	m_Stars_Trainee = 0;
	m_Stars_VeryGood = 0;
	//}}AFX_DATA_INIT
}

CDepCommercial::~CDepCommercial()
{
}

void CDepCommercial::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepCommercial)
	DDX_Control(pDX, IDC_SPIN_STARS_VERYGOOD, m_Spin_Stars_VeryGood);
	DDX_Control(pDX, IDC_SPIN_STARS_TRAINEE, m_Spin_Stars_Trainee);
	DDX_Control(pDX, IDC_SPIN_STARS_EXCELLENT, m_Spin_Stars_Excellent);
	DDX_Control(pDX, IDC_SPIN_STARS_GOOD, m_Spin_Stars_Good);
	DDX_Control(pDX, IDC_SPIN_STARS_AVERAGE, m_Spin_Stars_Average);
	DDX_Control(pDX, IDC_SPIN_STANDARD_VERYGOOD, m_Spin_Standard_VeryGood);
	DDX_Control(pDX, IDC_SPIN_STANDARD_TRAINEE, m_Spin_Standard_Trainee);
	DDX_Control(pDX, IDC_SPIN_STANDARD_GOOD, m_Spin_Standard_Good);
	DDX_Control(pDX, IDC_SPIN_STANDARD_EXCELLENT, m_Spin_Standard_Excellent);
	DDX_Control(pDX, IDC_SPIN_STANDARD_AVERAGE, m_Spin_Standard_Average);
	DDX_Control(pDX, IDC_SPIN_MORALE, m_Spin_Morale);
	DDX_Control(pDX, IDC_SPIN_AVAILABLE, m_Spin_Available);
	DDX_Text(pDX, IDC_EDIT_AVAILABLE, m_Available);
	DDV_MinMaxInt(pDX, m_Available, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_MORALE, m_Morale);
	DDV_MinMaxInt(pDX, m_Morale, 0, 100);
	DDX_Text(pDX, IDC_EDIT_STANDARD_AVERAGE, m_Standard_Average);
	DDV_MinMaxInt(pDX, m_Standard_Average, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STANDARD_EXCELLENT, m_Standard_Excellent);
	DDV_MinMaxInt(pDX, m_Standard_Excellent, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STANDARD_GOOD, m_Standard_Good);
	DDV_MinMaxInt(pDX, m_Standard_Good, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STANDARD_TRAINEE, m_Standard_Trainee);
	DDV_MinMaxInt(pDX, m_Standard_Trainee, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STANDARD_VERYGOOD, m_Standard_VeryGood);
	DDV_MinMaxInt(pDX, m_Standard_VeryGood, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STARS_AVERAGE, m_Stars_Average);
	DDV_MinMaxInt(pDX, m_Stars_Average, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STARS_EXCELLENT, m_Stars_Excellent);
	DDV_MinMaxInt(pDX, m_Stars_Excellent, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STARS_GOOD, m_Stars_Good);
	DDV_MinMaxInt(pDX, m_Stars_Good, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STARS_TRAINEE, m_Stars_Trainee);
	DDV_MinMaxInt(pDX, m_Stars_Trainee, 0, 32000);
	DDX_Text(pDX, IDC_EDIT_STARS_VERYGOOD, m_Stars_VeryGood);
	DDV_MinMaxInt(pDX, m_Stars_VeryGood, 0, 32000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepCommercial, CFormView)
	//{{AFX_MSG_MAP(CDepCommercial)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepCommercial diagnostics

#ifdef _DEBUG
void CDepCommercial::AssertValid() const
{
	CFormView::AssertValid();
}

void CDepCommercial::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDepCommercial message handlers

void CDepCommercial::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetSpin();
}

void CDepCommercial::Load(int id, CString file)
{
CFile f;
	
	m_Id=id;

	f.Open(file,CFile::modeRead,NULL);
	
	f.Seek(9160+(id*7824),CFile::begin);
	f.Read((char*)&m_Morale,sizeof(int));
	f.Seek(216,CFile::current);
	f.Read((char*)&m_Standard_Trainee,sizeof(int));
	f.Read((char*)&m_Standard_Average,sizeof(int));
	f.Read((char*)&m_Standard_Good,sizeof(int));
	f.Read((char*)&m_Standard_VeryGood,sizeof(int));
	f.Read((char*)&m_Standard_Excellent,sizeof(int));
	f.Seek(4,CFile::current);
	f.Read((char*)&m_Stars_Trainee,sizeof(int));
	f.Read((char*)&m_Stars_Average,sizeof(int));
	f.Read((char*)&m_Stars_Good,sizeof(int));
	f.Read((char*)&m_Stars_VeryGood,sizeof(int));
	f.Read((char*)&m_Stars_Excellent,sizeof(int));
	
	f.Seek(12844,CFile::begin);
	f.Read((char*)&m_Available,sizeof(int));

	f.Close();
	UpdateData(FALSE);
}

void CDepCommercial::SetSpin()
{
	m_Spin_Available.SetRange(0,32000);
	m_Spin_Morale.SetRange(0,100);

	m_Spin_Standard_Average.SetRange(0,32000);
	m_Spin_Standard_Excellent.SetRange(0,32000);
	m_Spin_Standard_Good.SetRange(0,32000);
	m_Spin_Standard_Trainee.SetRange(0,32000);
	m_Spin_Standard_VeryGood.SetRange(0,32000);

	m_Spin_Stars_Average.SetRange(0,32000);
	m_Spin_Stars_Excellent.SetRange(0,32000);
	m_Spin_Stars_Good.SetRange(0,32000);
	m_Spin_Stars_Trainee.SetRange(0,32000);
	m_Spin_Stars_VeryGood.SetRange(0,32000);
}

void CDepCommercial::Save(CString file)
{
CFile f;

	UpdateData(TRUE);

	f.Open(file,CFile::modeWrite,NULL);
	
	f.Seek(9160+(m_Id*7824),CFile::begin);
	f.Write((char*)&m_Morale,sizeof(int));
	f.Seek(216,CFile::current);
	f.Write((char*)&m_Standard_Trainee,sizeof(int));
	f.Write((char*)&m_Standard_Average,sizeof(int));
	f.Write((char*)&m_Standard_Good,sizeof(int));
	f.Write((char*)&m_Standard_VeryGood,sizeof(int));
	f.Write((char*)&m_Standard_Excellent,sizeof(int));
	f.Seek(4,CFile::current);
	f.Write((char*)&m_Stars_Trainee,sizeof(int));
	f.Write((char*)&m_Stars_Average,sizeof(int));
	f.Write((char*)&m_Stars_Good,sizeof(int));
	f.Write((char*)&m_Stars_VeryGood,sizeof(int));
	f.Write((char*)&m_Stars_Excellent,sizeof(int));
	
	f.Seek(12844,CFile::begin);
	f.Write((char*)&m_Available,sizeof(int));

	f.Close();
}
