// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SaveEdit.h"

#include "MainFrm.h"

#include "Driver.h"
#include "TeamFinance.h"
#include "TeamTech.h"
#include "SaveEditView.h"
#include "Track.h"
#include "Info.h"
#include "Mechanics.h"
#include "Engineering.h"
#include "Design.h"
#include "Commercial.h"
#include "Main.h"
#include "DepCommercial.h"
#include "DepDesign.h"
#include "DepMechanics.h"
#include "DepEngineering.h"
#include "Licensing.h"
#include "WorkMech.h"
#include "WorkDesign.h"
#include "Sponsor.h"
#include "Common.h"

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
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVEFILE, OnFileSavefile)
	ON_COMMAND(ID_FILE_SAVEFILEAS, OnFileSavefileas)
	ON_COMMAND(ID_FILE_CLOSEFILE, OnFileClosefile)
	ON_COMMAND(ID_EDIT_GPWDIRECTORY, OnEditGpwdirectory)
	ON_COMMAND(ID_EDIT_RUNGPW, OnEditRungpw)
	ON_COMMAND(ID_EDIT_SAVEFILEDIRECTORY, OnEditSavefiledirectory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_TEXT,
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

	m_GPWPath=m_Common.RegGetValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWPath");
	if(m_GPWPath=="")
		OnEditGpwdirectory();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	cs.cx=707;
	cs.cy=447;

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
	// TODO: Add your specialized code here and/or call the base class
	
	CRect cr;	
	BOOL rc;	
	if (!m_wndSplitter.CreateStatic(this,1,2))
	{
		TRACE0("Failed to create split bar ");		
		return FALSE; // failed to create
	}
	GetClientRect(&cr);	
	CSize paneSize(203, cr.Height());
	CSize paneSize1(3*cr.Width()/4, cr.Height());
	((CSaveEditApp*)AfxGetApp())->m_pDoc=(CSaveEditDoc*)(pContext->m_pCurrentDoc);
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0, 0,pContext->m_pNewViewClass,paneSize, pContext);
	if(!rc)
		return(FALSE);
	pContext->m_pNewViewClass=RUNTIME_CLASS(CMain);
	pContext->m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,1,pContext->m_pNewViewClass,paneSize1,pContext);
	m_wndSplitter.RecalcLayout();	
	m_wndSplitter.SetActivePane(0,1);
	return(rc);
}

void CMainFrame::ShowDriver(int id)
{
	SaveCur();
	if(iCur!=1)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDriver);
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDriver),paneSize1, &Context);
		CDriver *pView=(CDriver*)m_wndSplitter.GetPane(0,1);
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDriver *pView=(CDriver*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=1;
}

void CMainFrame::ShowTechTeam(int id)
{
	SaveCur();
	if(iCur!=2)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CTeamTech);
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CTeamTech),paneSize1, &Context);
		CTeamTech *pView=(CTeamTech*)m_wndSplitter.GetPane(0,1);
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CTeamTech *pView=(CTeamTech*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=2;
}

void CMainFrame::ShowFinanceTeam(int id)
{
	SaveCur();
	if(iCur!=3)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CTeamFinance);
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CTeamFinance),paneSize1, &Context);
		CTeamFinance *pView=(CTeamFinance*)m_wndSplitter.GetPane(0,1);
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 	
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CTeamFinance *pView=(CTeamFinance*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=3;
}

void CMainFrame::ShowInfo()
{
	SaveCur();
	if(iCur!=4)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CInfo); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CInfo),paneSize1, &Context);//Change 1
		CInfo *pView=(CInfo*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 
		pView->Load(m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	iCur=4;
}

void CMainFrame::OnFileOpen() 
{

TCHAR szFilter[]=_T("Grand Prix World Save File (*.sav)\0*.sav\0All Files (*.*)\0*.*\0\0");
	//Show open dialog
	CFileDialog fDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrTitle="Open GPW Save File";
	CString szDir = m_Common.RegGetValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWSaveFile");
	fDialog.m_ofn.lpstrInitialDir = szDir;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		BeginWaitCursor();
		m_DataFile=m_Common.AppPath();
		m_DataFile+="WorkFile.gpw";
		CopyFile(fDialog.m_ofn.lpstrFile,m_DataFile,FALSE);
		CString szTitle;
		szTitle="GPW Save File Editor - ";
		szTitle+=fDialog.m_ofn.lpstrFile;
		SetWindowText(szTitle);

		CSaveEditView *pView=(CSaveEditView*)m_wndSplitter.GetPane(0,0);
		pView->BuildTree(m_DataFile);

		m_RealName=fDialog.m_ofn.lpstrFile;
		EndWaitCursor();
	}	
}

void CMainFrame::ShowTrack(int id)
{
	SaveCur();
	if(iCur!=5)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CTrack); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CTrack),paneSize1, &Context);//Change 1
		CTrack *pView=(CTrack*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CTrack *pView=(CTrack*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=5;
}

void CMainFrame::ShowCommercial(int id)
{
	SaveCur();
	if(iCur!=6)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CCommercial); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CCommercial),paneSize1, &Context);//Change 1
		CCommercial *pView=(CCommercial*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CCommercial *pView=(CCommercial*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=6;
}

void CMainFrame::ShowDesign(int id)
{
	SaveCur();
	if(iCur!=7)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDesign); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDesign),paneSize1, &Context);//Change 1
		CDesign *pView=(CDesign*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDesign *pView=(CDesign*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=7;
}

void CMainFrame::ShowEngineering(int id)
{
	SaveCur();
	if(iCur!=8)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CEngineering); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CEngineering),paneSize1, &Context);//Change 1
		CEngineering *pView=(CEngineering*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CEngineering *pView=(CEngineering*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=8;
}

void CMainFrame::ShowMechanics(int id)
{
	SaveCur();
	if(iCur!=9)
	{
		CRect cr;	
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CMechanics); //Change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CMechanics),paneSize1, &Context);//Change 1
		CMechanics *pView=(CMechanics*)m_wndSplitter.GetPane(0,1);//Change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate(); 	
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CMechanics *pView=(CMechanics*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=9;
}

void CMainFrame::ShowDepCommercial(int id)
{
	SaveCur();
	if(iCur!=10)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDepCommercial);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDepCommercial),paneSize1, &Context);//change 1
		CDepCommercial *pView=(CDepCommercial*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDepCommercial *pView=(CDepCommercial*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=10;
}

void CMainFrame::ShowDepDesign(int id)
{
	SaveCur();
	if(iCur!=11)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDepDesign);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDepDesign),paneSize1, &Context);//change 1
		CDepDesign *pView=(CDepDesign*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDepDesign *pView=(CDepDesign*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=11;
}

void CMainFrame::ShowDepEngineering(int id)
{
	SaveCur();
	if(iCur!=12)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDepEngineering);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDepEngineering),paneSize1, &Context);//change 1
		CDepEngineering *pView=(CDepEngineering*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDepEngineering *pView=(CDepEngineering*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=12;
}

void CMainFrame::ShowDepMechanics(int id)
{
	SaveCur();
	if(iCur!=13)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CDepMechanics);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CDepMechanics),paneSize1, &Context);//change 1
		CDepMechanics *pView=(CDepMechanics*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CDepMechanics *pView=(CDepMechanics*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=13;
}

void CMainFrame::ShowLicensing(int id)
{
	SaveCur();
	if(iCur!=14)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CLicensing);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CLicensing),paneSize1, &Context);//change 1
		CLicensing *pView=(CLicensing*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CLicensing *pView=(CLicensing*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=14;
}

void CMainFrame::ShowWorkMech(int id)
{
	SaveCur();
	if(iCur!=15)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CWorkMech);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CWorkMech),paneSize1, &Context);//change 1
		CWorkMech *pView=(CWorkMech*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CWorkMech *pView=(CWorkMech*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=15;
}

void CMainFrame::SaveCur()
{

	if(iCur==1)
	{
		CDriver *pView=(CDriver*)m_wndSplitter.GetPane(0,1);
		pView->SaveDriver(m_DataFile);
	}
	else if(iCur==2)
	{
		CTeamTech *pView=(CTeamTech*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==3)
	{
		CTeamFinance *pView=(CTeamFinance*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==5)
	{
		CTrack *pView=(CTrack*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==6)
	{
		CCommercial *pView=(CCommercial*)m_wndSplitter.GetPane(0,1);
		pView->SaveCommercial(m_DataFile);
	}

	else if(iCur==7)
	{
		CDesign *pView=(CDesign*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==8)
	{
		CEngineering *pView=(CEngineering*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==9)
	{
		CMechanics *pView=(CMechanics*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==10)
	{
		CDepCommercial *pView=(CDepCommercial*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==11)
	{
		CDepDesign *pView=(CDepDesign*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==12)
	{
		CDepEngineering *pView=(CDepEngineering*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==13)
	{
		CDepMechanics *pView=(CDepMechanics*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==14)
	{
		CLicensing *pView=(CLicensing*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==15)
	{
		CWorkMech *pView=(CWorkMech*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==16)
	{
		CWorkDesign *pView=(CWorkDesign*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
	else if(iCur==17)
	{
		CSponsor *pView=(CSponsor*)m_wndSplitter.GetPane(0,1);
		pView->Save(m_DataFile);
	}
}

void CMainFrame::OnFileSavefile() 
{
	// TODO: Add your command handler code here
	BeginWaitCursor();
	if(m_RealName!="")
	{
		SaveCur();
		CopyFile(m_DataFile,m_RealName,FALSE);
		
		CSaveEditView *pView=(CSaveEditView*)m_wndSplitter.GetPane(0,0);
			pView->BuildTree(m_DataFile);
	}
	else
		MessageBox("You have to open a file to save it.",NULL,MB_ICONEXCLAMATION);
	EndWaitCursor();
}

void CMainFrame::OnFileSavefileas() 
{
TCHAR szFilter[]=_T("Grand Prix World Save File (*.sav)\0*.sav\0All Files (*.*)\0*.*\0\0");
	//Show save dialog
	if(m_RealName!="")
	{
		SaveCur();
		CFileDialog fDialog(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
		fDialog.m_ofn.lpstrFilter=szFilter;
		fDialog.m_ofn.lpstrTitle="Save GPW Save File";
		CString szDir = m_Common.RegGetValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWDir");
		fDialog.m_ofn.lpstrInitialDir = szDir;
		fDialog.m_ofn.lpstrDefExt="sav";
		int iReturn = fDialog.DoModal();
		if(iReturn ==  IDOK)
		{
			BeginWaitCursor();
			m_DataFile=m_Common.AppPath();
			m_DataFile+="WorkFile.gpw";
			CopyFile(m_DataFile,fDialog.m_ofn.lpstrFile,FALSE);
			CString szTitle;
			szTitle="GPW Save File Editor - ";
			szTitle+=fDialog.m_ofn.lpstrFile;
			SetWindowText(szTitle);

			CSaveEditView *pView=(CSaveEditView*)m_wndSplitter.GetPane(0,0);
			pView->BuildTree(m_DataFile);

			m_RealName=fDialog.m_ofn.lpstrFile;

			EndWaitCursor();
		}
	}
	else
	{
		MessageBox("You have to open a file to save it.",NULL,MB_ICONEXCLAMATION);
	}
}

void CMainFrame::SelectGPWPath()
{
CString szTmp;
CString szCheck;
WIN32_FIND_DATA wfd;
HANDLE hFile;
	szTmp=m_Common.BrowseForFolders("Select your GPW directory",m_hWnd);
	if(szTmp!="")
	{
		szCheck=szTmp;
		szCheck+="\\gpw.exe";
		hFile=FindFirstFile(szCheck,&wfd);
		if(hFile!=(HANDLE)-1)
		{
			m_Common.RegSaveValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWPath",szTmp);
			m_GPWPath=szTmp;
		}
		else
		{
			MessageBox("This is not your GPW directory, please select your GPW directory\nor press 'Cancel' if you dont want to select your GPW directory.\nIf you dont select your GPW directory all names etc will be default and not change if you change them in the game.",NULL,MB_ICONEXCLAMATION);
			SelectGPWPath();
		}

	}
}

void CMainFrame::OnFileClosefile() 
{
	if(m_DataFile!="")
	{
		DeleteFile(m_DataFile);
		CSaveEditView *pView=(CSaveEditView*)m_wndSplitter.GetPane(0,0);
		pView->CloseFile();
		m_RealName="";
		m_DataFile="";
		ShowMain();
		SetWindowText("GPW Save File Editor");
	}
}

void CMainFrame::ShowMain()
{
	SaveCur();
	if(iCur!=0)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		Context.m_pNewViewClass=RUNTIME_CLASS(CMain);//change 1
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CMain),paneSize1, &Context);//change 1
		CMain *pView=(CMain*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		m_wndSplitter.SetActivePane(0,1);
	}
	iCur=0;
}

void CMainFrame::ShowWorkDesign(int id)
{
	SaveCur();
	if(iCur!=16)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CWorkDesign);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CWorkDesign),paneSize1, &Context);//change 1
		CWorkDesign *pView=(CWorkDesign*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CWorkDesign *pView=(CWorkDesign*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=16;
}

void CMainFrame::ShowSponsors(int id)
{
	SaveCur();
	if(iCur!=17)
	{
		CRect cr;
		GetClientRect(&cr);	
		CSize paneSize1(3*cr.Width()/4, cr.Height());
		CCreateContext Context;	
		Context.m_pNewViewClass=RUNTIME_CLASS(CSponsor);//change 1
		Context.m_pCurrentDoc=((CSaveEditApp*)AfxGetApp())->m_pDoc;
		Context.m_pCurrentFrame=this;
		Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
		Context.m_pLastView=(CView*)m_wndSplitter.GetPane(0,0);
		m_wndSplitter.DeleteView(0, 1);
		m_wndSplitter.CreateView(0, 1,RUNTIME_CLASS(CSponsor),paneSize1, &Context);//change 1
		CSponsor *pView=(CSponsor*)m_wndSplitter.GetPane(0,1);//change 2
		pView->GetParentFrame()->RecalcLayout();	
		m_wndSplitter.RecalcLayout();
		pView->OnInitialUpdate();
		if(id!=-1)
			pView->Load(id,m_DataFile);
		m_wndSplitter.SetActivePane(0,1);
	}
	else
	{
		CSponsor *pView=(CSponsor*)m_wndSplitter.GetPane(0,1);
		if(id!=-1)
			pView->Load(id,m_DataFile);
	}
	iCur=17;
}
void CMainFrame::OnEditGpwdirectory() 
{
CString szPath;
	szPath=m_Common.BrowseForFolders("GPW Directory",m_hWnd);	
	if(szPath!="")
		m_Common.RegSaveValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWPath",szPath);
}

void CMainFrame::OnEditRungpw() 
{
CString szPath;
	szPath=m_Common.RegGetValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWPath");
	if(szPath!="")
		ShellExecute(m_hWnd,"open","gpw.exe","",szPath,1);
}

void CMainFrame::OnEditSavefiledirectory() 
{
CString szPath;
	szPath=m_Common.BrowseForFolders("GPW Save File Directory",m_hWnd);
	if(szPath!="")
		m_Common.RegSaveValue("Software\\VG Software\\GPW Save File Editor\\Settings","GPWSaveFile",szPath);
}
