// MedlemsSystemDoc.cpp : implementation of the CMedlemsSystemDoc class
//

#include "stdafx.h"
#include "MedlemsSystem.h"

#include "MedlemsSystemDoc.h"
#include "LeftMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemDoc

IMPLEMENT_DYNCREATE(CMedlemsSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CMedlemsSystemDoc, CDocument)
	//{{AFX_MSG_MAP(CMedlemsSystemDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemDoc construction/destruction

CMedlemsSystemDoc::CMedlemsSystemDoc()
{
	// TODO: add one-time construction code here

}

CMedlemsSystemDoc::~CMedlemsSystemDoc()
{
}

BOOL CMedlemsSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemDoc serialization

void CMedlemsSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMedlemsSystemDoc diagnostics

#ifdef _DEBUG
void CMedlemsSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMedlemsSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
