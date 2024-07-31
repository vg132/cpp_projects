// Confirm.cpp : implementation file
//

#include "stdafx.h"
#include "bokning.h"
#include "Confirm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfirm dialog


CConfirm::CConfirm(CWnd* pParent /*=NULL*/)
	: CDialog(CConfirm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfirm)
	m_BookedBy = _T("");
	m_From = _T("");
	m_Payment = _T("");
	m_Room = _T("");
	m_To = _T("");
	m_Total = _T("");
	//}}AFX_DATA_INIT
}


void CConfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfirm)
	DDX_Text(pDX, IDC_STATIC_BOOKEDBY, m_BookedBy);
	DDX_Text(pDX, IDC_STATIC_FROM, m_From);
	DDX_Text(pDX, IDC_STATIC_PAYMENT, m_Payment);
	DDX_Text(pDX, IDC_STATIC_ROOM, m_Room);
	DDX_Text(pDX, IDC_STATIC_TO, m_To);
	DDX_Text(pDX, IDC_STATIC_TOTAL, m_Total);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfirm, CDialog)
	//{{AFX_MSG_MAP(CConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, OnButtonConfirm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfirm message handlers

void CConfirm::OnButtonCancel() 
{
	OnCancel();	
}

void CConfirm::OnButtonConfirm() 
{
	OnOK();	
}

BOOL CConfirm::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
