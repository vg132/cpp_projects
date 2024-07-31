// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MedlemsSystem.h"

#include "MainFrm.h"
#include "LeftMenu.h"
#include "Main.h"
#include "MedlemsSystemView.h"
#include "MemberEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_ADDMEMBER, OnEditAddmember)
	ON_COMMAND(ID_EDIT_REMOVEMEMBER, OnEditRemovemember)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CRect cr;
	BOOL rc;
	if (!m_wndSplitter.CreateStatic(this,1,2)){
		TRACE0("Failed to create split bar ");
		return FALSE; // failed to create
	}
	GetClientRect(&cr);
	CSize paneSize(cr.Width()/4, cr.Height());
	CSize paneSize1(3*cr.Width()/4, cr.Height());
	((CMedlemsSystemApp*)AfxGetApp())->m_pDoc=(CMedlemsSystemDoc*)(pContext->m_pCurrentDoc);
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0, 1,pContext->m_pNewViewClass,paneSize1, pContext);
	if(!rc)
		return FALSE;
	pContext->m_pNewViewClass=RUNTIME_CLASS(CLeftMenu);
	pContext->m_pCurrentDoc=((CMedlemsSystemApp*)AfxGetApp())->m_pDoc;
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,0,pContext->m_pNewViewClass,paneSize,pContext);
	m_wndSplitter.RecalcLayout();
	m_wndSplitter.SetActivePane(0,1);
	return rc;
}

void CMainFrame::OnEditAddmember() 
{
	CLeftMenu *pView=(CLeftMenu*)m_wndSplitter.GetPane(0,0);
	pView->m=new CMember;
	pView->m->SetFirstName("New User");
	pView->l.Add(pView->m);
	pView->BuildTree();
}

void CMainFrame::ShowInfo()
{
	// TODO: Add your command handler code here
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4, cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CMain);
	Context.m_pCurrentDoc=((CMedlemsSystemApp*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
	m_wndSplitter.DeleteView(0, 1);
	m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CMain),paneSize1, &Context);
	CMain *pView=(CMain*)m_wndSplitter.GetPane(0,1);
	pView->GetParentFrame()->RecalcLayout();
	m_wndSplitter.RecalcLayout();
	pView->OnInitialUpdate(); 
	m_wndSplitter.SetActivePane(0,1);
}

void CMainFrame::ShowMemberInfo(CMember *m)
{
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4, cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CMain);
	Context.m_pCurrentDoc=((CMedlemsSystemApp*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
	m_wndSplitter.DeleteView(0, 1);
	m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CMemberEdit),paneSize1, &Context);
	CMemberEdit *pView=(CMemberEdit*)m_wndSplitter.GetPane(0,1);
	pView->GetParentFrame()->RecalcLayout();
	m_wndSplitter.RecalcLayout();
	pView->OnInitialUpdate(); 
	m_wndSplitter.SetActivePane(0,1);
	pView->m=m;
	pView->LoadData();
}

void CMainFrame::OnEditRemovemember() 
{
	CLeftMenu *pView=(CLeftMenu*)m_wndSplitter.GetPane(0,0);
	if(pView->m_CurSelected>-1)
	{
		pView->l.Remove(pView->m_CurSelected);
	}
	pView->BuildTree();
	pView->m_CurSelected=-1;
	ShowInfo();
}