// Main.cpp : implementation file
//

#include "stdafx.h"
#include "MedlemsSystem.h"
#include "Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMain

IMPLEMENT_DYNCREATE(CMain, CFormView)

CMain::CMain()
	: CFormView(CMain::IDD)
{
	//{{AFX_DATA_INIT(CMain)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMain::~CMain()
{
}

void CMain::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMain)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMain, CFormView)
	//{{AFX_MSG_MAP(CMain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMain diagnostics

#ifdef _DEBUG
void CMain::AssertValid() const
{
	CFormView::AssertValid();
}

void CMain::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMain message handlers
