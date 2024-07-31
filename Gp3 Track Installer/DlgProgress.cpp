// DlgProgress.cpp : implementation file
//

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "DlgProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgProgress dialog


CDlgProgress::CDlgProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgProgress)
	//}}AFX_DATA_INIT
}


void CDlgProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgProgress)
	DDX_Control(pDX, IDC_PROGRESS_BAR, m_ProgressBar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgProgress, CDialog)
	//{{AFX_MSG_MAP(CDlgProgress)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgProgress message handlers

void CDlgProgress::SetDataText(CString szData)
{
	SetDlgItemText(IDC_STATIC_DATA,szData);
}

void CDlgProgress::SetSubTitleText(CString szTitle)
{
	SetDlgItemText(IDC_STATIC_SUB_TITLE,szTitle);
}

void CDlgProgress::SetTitleText(CString szTitle)
{
	SetDlgItemText(IDC_STATIC_TITLE,szTitle);
}

void CDlgProgress::InitProgressBar(int iMin, int iMax)
{
	m_iMax=iMax;
	m_ProgressBar.SetRange(iMin,iMax);
	m_ProgressBar.SetStep(1);
}

void CDlgProgress::StepIt()
{
	m_ProgressBar.StepIt();
}
