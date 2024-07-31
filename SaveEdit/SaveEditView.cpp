// SaveEditView.cpp : implementation of the CSaveEditView class
//

#include "stdafx.h"
#include "SaveEdit.h"

#include "SaveEditDoc.h"
#include "SaveEditView.h"

#include "LoadText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveEditView

IMPLEMENT_DYNCREATE(CSaveEditView, CFormView)

BEGIN_MESSAGE_MAP(CSaveEditView, CFormView)
	//{{AFX_MSG_MAP(CSaveEditView)
	ON_NOTIFY(TVN_SELCHANGED, IDC_NAV_TREE, OnSelchangedNavTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveEditView construction/destruction

CSaveEditView::CSaveEditView()
	: CFormView(CSaveEditView::IDD)
{
	//{{AFX_DATA_INIT(CSaveEditView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CSaveEditView::~CSaveEditView()
{
}

void CSaveEditView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaveEditView)
	DDX_Control(pDX, IDC_NAV_TREE, m_Tree);
	//}}AFX_DATA_MAP
}

BOOL CSaveEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSaveEditView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_MainFrame=(CMainFrame*)AfxGetMainWnd();
}

/////////////////////////////////////////////////////////////////////////////
// CSaveEditView diagnostics

#ifdef _DEBUG
void CSaveEditView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSaveEditView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSaveEditDoc* CSaveEditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSaveEditDoc)));
	return (CSaveEditDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSaveEditView message handlers

void CSaveEditView::OnSelchangedNavTree(NMHDR* pNMHDR, LRESULT* pResult) 
{

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int i=(int)pNMTreeView->itemNew.lParam;

	//Show Forms!
	if(m_Close==1)
	{
		if(i==0)
			m_MainFrame->ShowInfo();
		//driver
		if((i>=2000&&i<2100)&&(i!=iCurShow))
			m_MainFrame->ShowDriver(i-2000);
		//Commercial
		else if((i>=3000&&i<3100)&&(i!=iCurShow))
			m_MainFrame->ShowCommercial(i-3000);
		else if((i>=3100&&i<3200)&&(i!=iCurShow))
			m_MainFrame->ShowDepCommercial(i-3101);
		else if((i>=3200&&i<3300)&&(i!=iCurShow))
			m_MainFrame->ShowLicensing(i-3201);
		else if((i>=3300&&i<3400)&&(i!=iCurShow))
			m_MainFrame->ShowSponsors(i-3301);
		//Design
		else if((i>=4000&&i<4100)&&(i!=iCurShow))
			m_MainFrame->ShowDesign(i-4000);
		else if((i>=4100&&i<4200)&&(i!=iCurShow))
			m_MainFrame->ShowDepDesign(i-4101);
		else if((i>=4200&&i<4300)&&(i!=iCurShow))
			m_MainFrame->ShowWorkDesign(i-4201);
		//Engineering
		else if((i>=5000&&i<5100)&&(i!=iCurShow))
			m_MainFrame->ShowEngineering(i-5000);
		else if((i>=5100&&i<5200)&&(i!=iCurShow))
			m_MainFrame->ShowDepEngineering(i-5101);
		else if((i>=5200&&i<5300)&&(i!=iCurShow))
			m_MainFrame->ShowTechTeam(i-5201);
		//Mechanics
		else if((i>=6000&&i<6100)&&(i!=iCurShow))
			m_MainFrame->ShowMechanics(i-6000);
		else if((i>=6100&&i<6200)&&(i!=iCurShow))
			m_MainFrame->ShowDepMechanics(i-6101);
		else if((i>=6200&&i<6300)&&(i!=iCurShow))
			m_MainFrame->ShowWorkMech(i-6201);
		else if((i>=7000&&i<7100)&&(i!=iCurShow))
			m_MainFrame->ShowTrack(i-7000);
		else if((i>=8001&&i<8017)&&(i!=iCurShow))
			m_MainFrame->ShowFinanceTeam(i-8001);

		else
			m_MainFrame->ShowMain();	
		iCurShow=i;

		m_Tree.SetFocus();
	}
	*pResult = 0;

}

HTREEITEM CSaveEditView::BuildNode(LPSTR szText, int Image, int SelectedImage, int id, HTREEITEM Parant)
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

void CSaveEditView::BuildTree(CString file)
{
int iEng[21]={3,11,19,27,35,43,51,59,67,75,83,108,
			  19,110,111,112,113,114,115,116,117};

int iDes[21]={2,10,18,26,34,42,50,58,66,74,82,98,99,
			  100,101,102,103,104,105,106,107};

int iMec[21]={4,12,20,28,36,44,52,60,68,76,84,118,
			  119,120,121,122,123,124,125,126,127};

int iDriv[41]={5,6,7,13,14,15,21,22,29,30,31,37,
			   38,45,46,47,53,54,55,61,62,63,69,
			   70,77,78,79,85,86,87,128,129,130,
			   131,132,133,134,135,136,137,138};

int iCom[21]={1,9,17,25,33,41,49,57,65,73,81,88,89,
			  90,91,92,93,94,95,96,97};

HTREEITEM hRoot;
HTREEITEM hChild;
HTREEITEM hChildChild;
int i;
int ii;
CString szTeam;

	//Load Text
	m_Text.LoadText();
	//build tree with nodes
	m_Close=1;
	//Image List	
CSaveEditApp* pApp;

	pApp = (CSaveEditApp*)AfxGetApp();

	m_pImageList=new CImageList();
	m_pImageList->Create(16, 16, ILC_MASK|ILC_COLOR8, 2, 2);
	m_pImageList->Add(pApp->LoadIcon(IDI_OPEN));//			0
	m_pImageList->Add(pApp->LoadIcon(IDI_CLOSED));//		1
	m_pImageList->Add(pApp->LoadIcon(IDI_DRIVER));//		2
	m_pImageList->Add(pApp->LoadIcon(IDI_TRACK));//			3
	m_pImageList->Add(pApp->LoadIcon(IDI_MECHANICS));//		4
	m_pImageList->Add(pApp->LoadIcon(IDI_COMMERCIAL));//	5
	m_pImageList->Add(pApp->LoadIcon(IDI_DESIGN));//		6
	m_pImageList->Add(pApp->LoadIcon(IDI_ENGINEERING));//	7

	m_Tree.SetImageList(m_pImageList,TVSIL_NORMAL);

	m_Tree.DeleteAllItems();

	//Build Tree
	hRoot=BuildNode("GPW Save File",1,0,0,TVI_ROOT);

	GetTeam(file);

	for(i=0;i<12;i++)
	{
		szTeam=m_Text.m_Teams[i];
		if(i==m_Team)
			szTeam+=" *";
		hChild=BuildNode((LPTSTR)(LPCTSTR)szTeam,1,0,8000+i,hRoot);
		hChildChild=BuildNode("Drivers",2,2,820+i,hChild);
		{
			for(ii=0;ii<41;ii++)
			{
				if(m_WorkTeam[iDriv[ii]]==i)
					BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Name[iDriv[ii]],2,2,2000+ii,hChildChild);
			}
		}
		hChildChild=BuildNode("Commercial",5,5,840+i,hChild);
		{
			if(i!=0)
			{
				BuildNode("Department",5,5,3100+i,hChildChild);
				BuildNode("Licensing",5,5,3200+i,hChildChild);
				BuildNode("Sponcors",5,5,3300+i,hChildChild);

			}
			for(ii=0;ii<21;ii++)
			{
				if(m_WorkTeam[iCom[ii]]==i)
					BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Name[iCom[ii]],5,5,3000+ii,hChildChild);
			}
		}
		hChildChild=BuildNode("Design",6,6,860+i,hChild);
		{
			if(i!=0)
			{
				BuildNode("Department",6,6,4100+i,hChildChild);
				BuildNode("Technology",6,6,4200+i,hChildChild);
			}
			for(ii=0;ii<21;ii++)
			{
				if(m_WorkTeam[iDes[ii]]==i)
					BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Name[iDes[ii]],6,6,4000+ii,hChildChild);
			}
		}
		hChildChild=BuildNode("Engineering",7,7,880+i,hChild);
		{
			if(i!=0)
			{
				BuildNode("Department",7,7,5100+i,hChildChild);
				BuildNode("Technology",7,7,5200+i,hChildChild);
			}
			for(ii=0;ii<21;ii++)
			{
				if(m_WorkTeam[iEng[ii]]==i)
					BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Name[iEng[ii]],7,7,5000+ii,hChildChild);
			}
		}
		hChildChild=BuildNode("Mechanics",4,4,900+i,hChild);
		{
			if(i!=0)
			{
				BuildNode("Department",4,4,6100+i,hChildChild);
				BuildNode("Testing",4,4,6200+i,hChildChild);
			}
			for(ii=0;ii<21;ii++)
			{
				if(m_WorkTeam[iMec[ii]]==i)
					BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Name[iMec[ii]],4,4,6000+ii,hChildChild);
			}
		}
	}
	hChild=BuildNode("Tracks",1,0,920,hRoot);
	for(i=0;i<16;i++)
		BuildNode((LPTSTR)(LPCTSTR)m_Text.m_Tracks[i],3,3,7000+i,hChild);

	m_Tree.EnsureVisible(hChild);
	m_Tree.Select(hRoot,TVGN_CARET);
	m_Tree.EnableWindow(TRUE);
	m_MainFrame->ShowInfo();
}

void CSaveEditView::GetTeam(CString file)
{
CFile f;
int iData;
int i;

	f.Open(file,CFile::modeRead,NULL);
	
	for(i=0;i<139;i++)
	{
		f.Seek(97832+(i*3576),CFile::begin);
		f.Read((char*)&iData,sizeof(int));
		m_WorkTeam[i]=iData;
	}
	f.Seek(144,CFile::begin);
	f.Read((char*)&m_Team,sizeof(int));
	f.Close();
}

void CSaveEditView::CloseFile()
{
	m_Close=0;
	m_Tree.EnableWindow(FALSE);
	m_Tree.DeleteAllItems();
}
