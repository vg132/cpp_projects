w// Info.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Info.h"
#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfo

IMPLEMENT_DYNCREATE(CInfo, CFormView)

CInfo::CInfo()
	: CFormView(CInfo::IDD)
{
	//{{AFX_DATA_INIT(CInfo)
	m_CHPoints = 0;
	m_CHPos = 0;
	m_Created = _T("");
	m_CurrentYear = 0;
	m_Modified = _T("");
	m_Player = _T("");
	m_Score = 0;
	m_Seasons = 0;
	m_NextRace = _T("");
	m_Team = _T("");
	//}}AFX_DATA_INIT
}

CInfo::~CInfo()
{
}

void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfo)
	DDX_Text(pDX, IDC_INFO_CHPOINTS, m_CHPoints);
	DDX_Text(pDX, IDC_INFO_CHPOS, m_CHPos);
	DDX_Text(pDX, IDC_INFO_CREATED, m_Created);
	DDX_Text(pDX, IDC_INFO_CURRENTYEAR, m_CurrentYear);
	DDX_Text(pDX, IDC_INFO_MODIFIED, m_Modified);
	DDX_Text(pDX, IDC_INFO_PLAYER, m_Player);
	DDX_Text(pDX, IDC_INFO_SCORE, m_Score);
	DDX_Text(pDX, IDC_INFO_SEASONS, m_Seasons);
	DDX_Text(pDX, IDC_INFO_NEXTRACE, m_NextRace);
	DDX_Text(pDX, IDC_INFO_TEAM, m_Team);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfo, CFormView)
	//{{AFX_MSG_MAP(CInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfo diagnostics

#ifdef _DEBUG
void CInfo::AssertValid() const
{
	CFormView::AssertValid();
}

void CInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInfo message handlers

bool CInfo::Load(CString file)
{
char cPlayer[18];
char cCreated[24];
char cModified[24];
int iData;
CLoadText m_Text;

	m_Text.LoadText();

	CFile f;
	f.Open(file,CFile::modeRead,NULL);

	f.Seek(144,CFile::begin);
	f.Read((char*)&iData,sizeof(int));
	m_Team=m_Text.m_Teams[iData];
	f.Seek(100,CFile::current);
	f.Read((char*)&m_Score,sizeof(int));//Score
	f.Read((char*)&m_Seasons,sizeof(int));//Years
	f.Read((char*)&m_CurrentYear,sizeof(int));//Year
	f.Read((char*)&m_CHPos,sizeof(int));//Pos
	f.Read((char*)&m_CHPoints,sizeof(int));//Point
	f.Read((char*)&iData,sizeof(int));//Next Race
	m_NextRace=m_Text.m_Tracks[iData-1];

	f.Seek(113,CFile::begin);
	f.Read((char*)&cPlayer,sizeof(cPlayer));
	f.Seek(198,CFile::begin);
	f.Read((char*)&cCreated,sizeof(cCreated));
	f.Seek(148,CFile::begin);
	f.Read((char*)&cModified,sizeof(cModified));

	m_Modified=cModified;
	m_Created=cCreated;
	m_Player=cPlayer;

	f.Close();
	UpdateData(FALSE);
	return(true);
}

void CInfo::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
}
