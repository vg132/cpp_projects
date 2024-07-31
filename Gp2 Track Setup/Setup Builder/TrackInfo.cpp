// TrackInfo.cpp : implementation file
//

#include "stdafx.h"
#include "New Track Install.h"
#include "TrackInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TrackInfo dialog


TrackInfo::TrackInfo(CWnd* pParent /*=NULL*/)
	: CDialog(TrackInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(TrackInfo)
	m_Adj = _T("");
	m_Country = _T("");
	m_Laps = _T("");
	m_Len = _T("");
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void TrackInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TrackInfo)
	DDX_Text(pDX, IDC_Adjective, m_Adj);
	DDV_MaxChars(pDX, m_Adj, 30);
	DDX_Text(pDX, IDC_Country, m_Country);
	DDV_MaxChars(pDX, m_Country, 30);
	DDX_Text(pDX, IDC_Laps, m_Laps);
	DDV_MaxChars(pDX, m_Laps, 3);
	DDX_Text(pDX, IDC_Len, m_Len);
	DDV_MaxChars(pDX, m_Len, 4);
	DDX_Text(pDX, IDC_Name, m_Name);
	DDV_MaxChars(pDX, m_Name, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TrackInfo, CDialog)
	//{{AFX_MSG_MAP(TrackInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TrackInfo message handlers
