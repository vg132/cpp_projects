// MedlemsSystemView.cpp : implementation of the CMedlemsSystemView class
//

#include "stdafx.h"
#include "MedlemsSystem.h"

#include "MedlemsSystemDoc.h"
#include "MedlemsSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemView

IMPLEMENT_DYNCREATE(CMedlemsSystemView, CFormView)

BEGIN_MESSAGE_MAP(CMedlemsSystemView, CFormView)
	//{{AFX_MSG_MAP(CMedlemsSystemView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemView construction/destruction

CMedlemsSystemView::CMedlemsSystemView()
	: CFormView(CMedlemsSystemView::IDD)
{
	//{{AFX_DATA_INIT(CMedlemsSystemView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMedlemsSystemView::~CMedlemsSystemView()
{
}

void CMedlemsSystemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMedlemsSystemView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMedlemsSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMedlemsSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemView diagnostics

#ifdef _DEBUG
void CMedlemsSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedlemsSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedlemsSystemDoc* CMedlemsSystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedlemsSystemDoc)));
	return (CMedlemsSystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemView message handlers