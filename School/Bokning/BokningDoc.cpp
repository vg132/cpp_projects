// BokningDoc.cpp : implementation of the CBokningDoc class
//

#include "stdafx.h"
#include "Bokning.h"

#include "BokningDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBokningDoc

IMPLEMENT_DYNCREATE(CBokningDoc, CDocument)

BEGIN_MESSAGE_MAP(CBokningDoc, CDocument)
	//{{AFX_MSG_MAP(CBokningDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBokningDoc construction/destruction

CBokningDoc::CBokningDoc()
{
	// TODO: add one-time construction code here

}

CBokningDoc::~CBokningDoc()
{
}

BOOL CBokningDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBokningDoc serialization

void CBokningDoc::Serialize(CArchive& ar)
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
// CBokningDoc diagnostics

#ifdef _DEBUG
void CBokningDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBokningDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBokningDoc commands
