// SaveEditDoc.cpp : implementation of the CSaveEditDoc class
//

#include "stdafx.h"
#include "SaveEdit.h"

#include "SaveEditDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveEditDoc

IMPLEMENT_DYNCREATE(CSaveEditDoc, CDocument)

BEGIN_MESSAGE_MAP(CSaveEditDoc, CDocument)
	//{{AFX_MSG_MAP(CSaveEditDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveEditDoc construction/destruction

CSaveEditDoc::CSaveEditDoc()
{
	// TODO: add one-time construction code here

}

CSaveEditDoc::~CSaveEditDoc()
{
}

BOOL CSaveEditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSaveEditDoc serialization

void CSaveEditDoc::Serialize(CArchive& ar)
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
// CSaveEditDoc diagnostics

#ifdef _DEBUG
void CSaveEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSaveEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSaveEditDoc commands
