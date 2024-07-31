// Progress.cpp : implementation file
//

#include "stdafx.h"
#include "mp3filestudio.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgress dialog


CProgress::CProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgress)
	m_sText = _T("");
	m_sHeader = _T("");
	//}}AFX_DATA_INIT
}


void CProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgress)
	DDX_Control(pDX, IDC_PROGRESS_BAR, m_ProgressBar);
	DDX_Text(pDX, IDC_PROGRESS_TEXT, m_sText);
	DDX_Text(pDX, IDC_HEADER, m_sHeader);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgress, CDialog)
	//{{AFX_MSG_MAP(CProgress)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgress message handlers

void CProgress::SetText(char *Text)
{
	m_sText=Text;
	UpdateData(FALSE);
	this->RedrawWindow();
}

void CProgress::SetText(CString Text)
{
	m_sText=Text;
	UpdateData(FALSE);
	this->RedrawWindow();
}

void CProgress::SetHeader(CString Header)
{
	m_sHeader=Header;
	UpdateData(FALSE);
	this->RedrawWindow();
}

void CProgress::SetHeader(char *Header)
{
	m_sHeader=Header;
	UpdateData(FALSE);
	this->RedrawWindow();
}

void CProgress::SetProgressBar(int Max)
{
	m_ProgressBar.SetStep(1);
	m_ProgressBar.SetRange(0,Max);
}

void CProgress::StepProgressBar()
{
	m_ProgressBar.StepIt();
}
