// Team.cpp : implementation file
//

#include "stdafx.h"
#include "SaveEdit.h"
#include "Team.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeam

IMPLEMENT_DYNCREATE(CTeam, CFormView)

CTeam::CTeam()
	: CFormView(CTeam::IDD)
{
	//{{AFX_DATA_INIT(CTeam)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTeam::~CTeam()
{
}

void CTeam::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeam)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeam, CFormView)
	//{{AFX_MSG_MAP(CTeam)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeam diagnostics

#ifdef _DEBUG
void CTeam::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeam::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeam message handlers
