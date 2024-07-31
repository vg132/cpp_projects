// LeftMenu.cpp : implementation file
//

#include "stdafx.h"
#include "MedlemsSystem.h"
#include "LeftMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftMenu

IMPLEMENT_DYNCREATE(CLeftMenu, CFormView)

CLeftMenu::CLeftMenu()
	: CFormView(CLeftMenu::IDD)
{
	//{{AFX_DATA_INIT(CLeftMenu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLeftMenu::~CLeftMenu()
{

}

void CLeftMenu::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftMenu)
	DDX_Control(pDX, IDC_CONTACT, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftMenu, CFormView)
	//{{AFX_MSG_MAP(CLeftMenu)
	ON_NOTIFY(TVN_SELCHANGED, IDC_CONTACT, OnSelchangedContact)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftMenu diagnostics

#ifdef _DEBUG
void CLeftMenu::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftMenu::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftMenu message handlers

HTREEITEM CLeftMenu::BuildNode(LPSTR szText, int Image, int SelectedImage, int id, HTREEITEM Parant)
{
	TV_ITEM tvItem;
	TV_INSERTSTRUCT tvIns;

	// The pszText, iImage, and iSelectedImage members are filled out.
	tvItem.mask = TVIF_TEXT | TVIF_PARAM|TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvItem.pszText=szText;
	tvItem.iImage = Image;
	tvItem.iSelectedImage = SelectedImage;
	tvItem.lParam=id;
	
	tvIns.hParent = Parant;
	tvIns.hInsertAfter = TVI_LAST;
	tvIns.item=tvItem;

	return(m_Tree.InsertItem(&tvIns));
}

void CLeftMenu::BuildTree()
{
HTREEITEM hRoot;
HTREEITEM hChild;
HTREEITEM hChildChild;

	m_Tree.SetImageList(m_pImageList,TVSIL_NORMAL);

	m_Tree.DeleteAllItems();

	//Build Tree
	hRoot=BuildNode("Members",1,0,-1,TVI_ROOT);

	char *tmp=NULL;
	for(int i=0;i<l.GetSize();i++)
	{
		m=l.GetItem(i);
		tmp=new char[strlen(m->GetFirstName())];
		strcpy(tmp,m->GetFirstName());
		hChild=BuildNode(tmp,2,2,i,hRoot);
	}
	m_Tree.EnsureVisible(hChild);
}

void CLeftMenu::MakeImageList()
{
	CMedlemsSystemApp* pApp;
	pApp = (CMedlemsSystemApp*)AfxGetApp();

	m_pImageList=new CImageList();
	m_pImageList->Create(16, 16, ILC_MASK|ILC_COLOR8, 2, 2);
	m_pImageList->Add(pApp->LoadIcon(IDI_OPEN));//			0
	m_pImageList->Add(pApp->LoadIcon(IDI_CLOSED));//		1
	m_pImageList->Add(pApp->LoadIcon(IDI_DOCUMENT));//		2
}


void CLeftMenu::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	m_MainFrame=(CMainFrame*)AfxGetMainWnd();
	MakeImageList();
	BuildTree();
}

void CLeftMenu::OnSelchangedContact(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	m_CurSelected=(int)pNMTreeView->itemNew.lParam;

	if(m_CurSelected==-1)
		m_MainFrame->ShowInfo();
	else
		m_MainFrame->ShowMemberInfo(l.GetItem(m_CurSelected));
	*pResult = 0;
}
