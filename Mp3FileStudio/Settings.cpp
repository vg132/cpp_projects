// Settings.cpp : implementation file
//

#include "stdafx.h"
#include "mp3filestudio.h"
#include "Settings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettings property page

IMPLEMENT_DYNCREATE(CSettings, CPropertyPage)

CSettings::CSettings() : CPropertyPage(CSettings::IDD)
{
	//{{AFX_DATA_INIT(CSettings)
	m_Mp3Player = _T("");
	//}}AFX_DATA_INIT
}

CSettings::~CSettings()
{
}

void CSettings::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettings)
	DDX_Text(pDX, IDC_MP3PLAYER, m_Mp3Player);
	DDV_MaxChars(pDX, m_Mp3Player, 260);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettings, CPropertyPage)
	//{{AFX_MSG_MAP(CSettings)
	ON_BN_CLICKED(IDC_BROWSE_MP3PLAYER, OnBrowseMp3player)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettings message handlers

void CSettings::OnBrowseMp3player() 
{
	CFileDialog fdlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Mp3 Player (*.exe)|*.exe||",NULL);
	if(fdlg.DoModal()==IDOK)
	{
		m_Mp3Player=fdlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
		m_pParentWnd->SendMessage(m_Msg,WM_NEWPLAYER,0);
	}
}

void CSettings::SetPlayer(CString player)
{
	m_Mp3Player=player;
}

CString CSettings::GetPlayer()
{
	return(m_Mp3Player);
}

void CSettings::Init(CWnd *pParentWnd, UINT msg)
{
	m_pParentWnd=pParentWnd;
	m_Msg = msg;
}

BOOL CSettings::OnSetActive() 
{
	UpdateData(FALSE);
	return CPropertyPage::OnSetActive();
}
