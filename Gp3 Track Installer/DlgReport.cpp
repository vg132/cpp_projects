// DlgReport.cpp : implementation file
//

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "DlgReport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgReport dialog


CDlgReport::CDlgReport(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgReport::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgReport)
	//}}AFX_DATA_INIT
}


void CDlgReport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgReport)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgReport, CDialog)
	//{{AFX_MSG_MAP(CDlgReport)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgReport message handlers

void CDlgReport::OnButtonOk() 
{
	OnOK();	
}

void CDlgReport::Init(CLanguage *lang, char* text, bool gp3form)
{
	m_pLang=lang;
	m_Gp3Form=gp3form;
	m_pText=text;
}

BOOL CDlgReport::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(m_Gp3Form==true)
	{
		SetDlgItemText(IDC_BUTTON_OK,m_pLang->GetText(m_pLang->GP3FORM_OK_BUTTON));
		SetWindowText(m_pLang->GetText(m_pLang->GP3FORM_TITLE));
	}
	else
	{
		SetDlgItemText(IDC_BUTTON_OK,m_pLang->GetText(m_pLang->REPORT_OK_BUTTON));
		SetWindowText(m_pLang->GetText(m_pLang->REPORT_TITLE));
	}

	SetDlgItemText(IDC_EDIT_REPORT,m_pText);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
