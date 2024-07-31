// Splatsh.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Splatsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplatsh dialog


CSplatsh::CSplatsh(CWnd* pParent /*=NULL*/)
	: CDialog(CSplatsh::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSplatsh)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSplatsh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplatsh)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSplatsh, CDialog)
	//{{AFX_MSG_MAP(CSplatsh)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplatsh message handlers
