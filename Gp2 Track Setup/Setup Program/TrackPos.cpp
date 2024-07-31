// TrackPos.cpp : implementation file
//

#include "stdafx.h"
#include "New Setup.h"
#include "TrackPos.h"
#include "New SetupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TrackPos dialog


TrackPos::TrackPos(CWnd* pParent /*=NULL*/)
	: CDialog(TrackPos::IDD, pParent)
{
	//{{AFX_DATA_INIT(TrackPos)
	m_TrackPos = _T("");
	m_Text = FALSE;
	//}}AFX_DATA_INIT
}


void TrackPos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TrackPos)
	DDX_CBString(pDX, IDC_TrackPos, m_TrackPos);
	DDX_Check(pDX, IDC_Change, m_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TrackPos, CDialog)
	//{{AFX_MSG_MAP(TrackPos)
	ON_BN_CLICKED(IDC_Next, OnNext)
	ON_BN_CLICKED(IDC_Exit, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TrackPos message handlers

void TrackPos::OnNext() 
{
	OnOK();	
}

void TrackPos::OnExit() 
{
	OnCancel();	
}

BOOL TrackPos::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_TrackPos="Track 1";
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
