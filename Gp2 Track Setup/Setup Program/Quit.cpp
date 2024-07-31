// Quit.cpp : implementation file
//

#include "stdafx.h"
#include "New Setup.h"
#include "Quit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuit dialog


CQuit::CQuit(CWnd* pParent /*=NULL*/)
	: CDialog(CQuit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuit)
	//}}AFX_DATA_INIT
}


void CQuit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuit)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuit, CDialog)
	//{{AFX_MSG_MAP(CQuit)
	ON_BN_CLICKED(IDC_Exit, OnExit)
	ON_BN_CLICKED(IDC_Resume, OnResume)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuit message handlers

BOOL CQuit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQuit::OnExit() 
{
	OnOK();	
}

void CQuit::OnResume() 
{
	OnCancel();	
}
