// TimeEdit.cpp : implementation file
//

#include "stdafx.h"
#include "GP4 Time Editor.h"
#include "TimeEdit.h"


// CTimeEdit dialog

IMPLEMENT_DYNAMIC(CTimeEdit, CDialog)
CTimeEdit::CTimeEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeEdit::IDD, pParent)
{
}

CTimeEdit::~CTimeEdit()
{
}

void CTimeEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_Name);
	DDX_Control(pDX, IDC_EDIT_TEAM, m_Team);
	DDX_Control(pDX, IDC_EDIT_DATE, m_Date);
	DDX_Control(pDX, IDC_EDIT_TIME, m_Time);
}


BEGIN_MESSAGE_MAP(CTimeEdit, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnBnClickedButtonCancel)
END_MESSAGE_MAP()


// CTimeEdit message handlers
void CTimeEdit::OnBnClickedButtonCancel()
{
	OnCancel();
}