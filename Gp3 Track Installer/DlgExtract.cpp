// DlgExtract.cpp : implementation file
//

#include "stdafx.h"
#include "gp3trackinstaller.h"
#include "DlgExtract.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExtract dialog


CDlgExtract::CDlgExtract(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExtract::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExtract)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgExtract::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExtract)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgExtract, CDialog)
	//{{AFX_MSG_MAP(CDlgExtract)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExtract message handlers

void CDlgExtract::OnButton1() 
{
	CAnimateCtrl ani;
	ani.Create(WS_CHILD | WS_VISIBLE,CRect(10, 10, 100, 100),this,IDC_ANIMATE_EXTRACT);
	ani.Open(/*IDR_COPY*/"E:\\Microsoft Visual Studio\\Common\\Graphics\\Avis\\FILECOPY.AVI");
	ani.Play(0,-1,-1);
}
