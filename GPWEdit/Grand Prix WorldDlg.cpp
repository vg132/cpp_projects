// Grand Prix WorldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Grand Prix World.h"
#include "Grand Prix WorldDlg.h"
#include "stdlib.h"
#include "Data.h"
#include "Common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrandPrixWorldDlg dialog

CGrandPrixWorldDlg::CGrandPrixWorldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGrandPrixWorldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrandPrixWorldDlg)
	m_Root_Team = _T("");
	m_Root_Year = 0;
	m_Root_Years = 0;
	m_Root_Points = 0;
	m_Root_NextRace = _T("");
	m_Root_Pos = 0;
	m_Root_Player = _T("");
	m_Root_Created = _T("");
	m_Root_Modified = _T("");
	m_Root_Score = 0;
	m_Other_Ability = 0;
	m_Other_WCBonus = 0;
	m_Other_Salary = 0;
	m_Other_RaceBonus = 0;
	m_Other_LastYear = 0;
	m_Commercial_Ability = 0;
	m_Commercial_LastYear = 0;
	m_Commercial_Royalty = 0;
	m_Commercial_Salary = 0;
	m_Driver_CHBonus = 0;
	m_Driver_Concentration = 0;
	m_Driver_Experience = 0;
	m_Driver_Morale = 0;
	m_Driver_Overtaking = 0;
	m_Driver_Points = 0;
	m_Driver_RaceBonus = 0;
	m_Driver_Salary = 0;
	m_Driver_Skill = 0;
	m_Driver_Speed = 0;
	m_Driver_Stamina = 0;
	m_Driver_WetWether = 0;
	m_Team_Budget = 0;
	m_Team_Points = 0;
	m_Team_TestPrice = 0;
	m_OtherRoot_Average = 0;
	m_OtherRoot_Excellent = 0;
	m_OtherRoot_Good = 0;
	m_OtherRoot_Morale = 0;
	m_OtherRoot_Trainee = 0;
	m_OtherRoot_VeryGood = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGrandPrixWorldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrandPrixWorldDlg)
	DDX_Control(pDX, IDC_TreeView, m_Tree);
	DDX_Text(pDX, IDC_ROOT_TEAM, m_Root_Team);
	DDX_Text(pDX, IDC_ROOT_YEAR, m_Root_Year);
	DDX_Text(pDX, IDC_ROOT_YEARS, m_Root_Years);
	DDX_Text(pDX, IDC_ROOT_POINTS, m_Root_Points);
	DDX_Text(pDX, IDC_ROOT_NEXTRACE, m_Root_NextRace);
	DDX_Text(pDX, IDC_ROOT_POS, m_Root_Pos);
	DDX_Text(pDX, IDC_ROOT_PLAYER, m_Root_Player);
	DDX_Text(pDX, IDC_ROOT_CREATED, m_Root_Created);
	DDX_Text(pDX, IDC_ROOT_MODIFIED, m_Root_Modified);
	DDX_Text(pDX, IDC_ROOT_SCORE, m_Root_Score);
	DDX_Text(pDX, IDC_OTHER_ABILITY, m_Other_Ability);
	DDX_Text(pDX, IDC_OTHER_CHBONUS, m_Other_WCBonus);
	DDX_Text(pDX, IDC_OTHER_SALARY, m_Other_Salary);
	DDX_Text(pDX, IDC_OTHER_RACEBONUS, m_Other_RaceBonus);
	DDX_Text(pDX, IDC_OTHER_LASTYEAR, m_Other_LastYear);
	DDX_Text(pDX, IDC_COMMERCIAL_ABILITY, m_Commercial_Ability);
	DDX_Text(pDX, IDC_COMMERCIAL_LASTYEAR, m_Commercial_LastYear);
	DDX_Text(pDX, IDC_COMMERCIAL_ROYALTY, m_Commercial_Royalty);
	DDX_Text(pDX, IDC_COMMERCIAL_SALARY, m_Commercial_Salary);
	DDX_Text(pDX, IDC_DRIVER_CHBONUS, m_Driver_CHBonus);
	DDX_Text(pDX, IDC_DRIVER_CONCENTRATION, m_Driver_Concentration);
	DDV_MinMaxInt(pDX, m_Driver_Concentration, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_EXPERIENCE, m_Driver_Experience);
	DDV_MinMaxInt(pDX, m_Driver_Experience, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_MORALE, m_Driver_Morale);
	DDV_MinMaxInt(pDX, m_Driver_Morale, 0, 100);
	DDX_Text(pDX, IDC_DRIVER_OVERTAKING, m_Driver_Overtaking);
	DDV_MinMaxInt(pDX, m_Driver_Overtaking, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_POINTS, m_Driver_Points);
	DDX_Text(pDX, IDC_DRIVER_RACEBONUS, m_Driver_RaceBonus);
	DDX_Text(pDX, IDC_DRIVER_SALARY, m_Driver_Salary);
	DDX_Text(pDX, IDC_DRIVER_SKILL, m_Driver_Skill);
	DDV_MinMaxInt(pDX, m_Driver_Skill, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_SPEED, m_Driver_Speed);
	DDV_MinMaxInt(pDX, m_Driver_Speed, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_STAMINA, m_Driver_Stamina);
	DDV_MinMaxInt(pDX, m_Driver_Stamina, 0, 5);
	DDX_Text(pDX, IDC_DRIVER_WETWETHER, m_Driver_WetWether);
	DDV_MinMaxInt(pDX, m_Driver_WetWether, 0, 5);
	DDX_Text(pDX, IDC_TEAM_BUDGET, m_Team_Budget);
	DDX_Text(pDX, IDC_TEAM_POINTS, m_Team_Points);
	DDX_Text(pDX, IDC_TEAM_TESTPRICE, m_Team_TestPrice);
	DDX_Text(pDX, IDC_OTHERROOT_AVERAGE, m_OtherRoot_Average);
	DDV_MinMaxInt(pDX, m_OtherRoot_Average, 0, 255);
	DDX_Text(pDX, IDC_OTHERROOT_EXCELLENT, m_OtherRoot_Excellent);
	DDV_MinMaxInt(pDX, m_OtherRoot_Excellent, 0, 255);
	DDX_Text(pDX, IDC_OTHERROOT_GOOD, m_OtherRoot_Good);
	DDV_MinMaxInt(pDX, m_OtherRoot_Good, 0, 255);
	DDX_Text(pDX, IDC_OTHERROOT_MORALE, m_OtherRoot_Morale);
	DDV_MinMaxInt(pDX, m_OtherRoot_Morale, 0, 100);
	DDX_Text(pDX, IDC_OTHERROOT_TRAINEE, m_OtherRoot_Trainee);
	DDV_MinMaxInt(pDX, m_OtherRoot_Trainee, 0, 255);
	DDX_Text(pDX, IDC_OTHERROOT_VERYGOOD, m_OtherRoot_VeryGood);
	DDV_MinMaxInt(pDX, m_OtherRoot_VeryGood, 0, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGrandPrixWorldDlg, CDialog)
	//{{AFX_MSG_MAP(CGrandPrixWorldDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TreeView, OnSelchangedTreeView)
	ON_NOTIFY(TVN_SELCHANGING, IDC_TreeView, OnSelchangingTreeView)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(IDC_FILE_SAVEAS, OnFileSaveas)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(IDC_HELP_ONLINE, OnHelpOnline)
	ON_COMMAND(IDC_EDIT_GPWPath, OnEDITGPWPath)
	ON_COMMAND(IDC_FILE_EXPORT, OnFileExport)
	ON_COMMAND(IDC_FILE_IMPORT, OnFileImport)
	ON_COMMAND(IDC_FILE_CLOSE, OnFileClose)
	ON_COMMAND(IDC_HELP_HOWTO, OnHelpHowto)
	ON_COMMAND(IDC_HELP_MENUHELP, OnHelpMenuhelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrandPrixWorldDlg message handlers

BOOL CGrandPrixWorldDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//Disable treeview
	m_Tree.EnableWindow(FALSE);

	//Disable/enable menu items
	CMenu* m=GetMenu();
	EnableMenuItem(m->m_hMenu,ID_FILE_SAVE,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_SAVEAS,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_CLOSE,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_EXPORT,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_IMPORT,MF_GRAYED);



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	CString sPath=m_Common.AppPath();
	sPath+="name.dat";
//	sPath="c:\\name.dat";
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	//build tree with nodes
	TV_INSERTSTRUCT TreeCtrlItem;

	TreeCtrlItem.hParent = TVI_ROOT;
	TreeCtrlItem.hInsertAfter = TVI_LAST;
	TreeCtrlItem.item.mask = TVIF_TEXT | TVIF_PARAM;
	TreeCtrlItem.item.pszText = "Grand Prix World Save File";
	TreeCtrlItem.item.lParam = 700;
	HTREEITEM hTreeItem1 = m_Tree.InsertItem(&TreeCtrlItem);

	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Teams";
	TreeCtrlItem.item.lParam= 600;
	HTREEITEM hTeams = m_Tree.InsertItem(&TreeCtrlItem);
	
	m_Tree.EnsureVisible(hTeams);

	CString szNames=GetFile(sPath);
	int iEnd;
	int i;
	for(i=0;i<11;i++)
	{
		//build tree with Teams
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hTeams;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =601+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}

	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Drivers";
	TreeCtrlItem.item.lParam = 100;
	HTREEITEM hDrivers = m_Tree.InsertItem(&TreeCtrlItem);
	for(i=0;i<44;i++)
	{
		//build tree with drivers
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hDrivers;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =101+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}
	
	DeleteObject(hDrivers);
	
	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Commercial";
	TreeCtrlItem.item.lParam = 200;
	HTREEITEM hCommercial = m_Tree.InsertItem(&TreeCtrlItem);



	for(i=0;i<21;i++)
	{
		//build tree with commercial
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hCommercial;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =201+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}

	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Design";
	TreeCtrlItem.item.lParam = 300;
	HTREEITEM hDesign = m_Tree.InsertItem(&TreeCtrlItem);

	for(i=0;i<21;i++)
	{
		//build tree with design
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hDesign;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =301+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}

	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Engineering";
	TreeCtrlItem.item.lParam = 400;
	HTREEITEM hEngineering = m_Tree.InsertItem(&TreeCtrlItem);
	
	for(i=0;i<21;i++)
	{
		//build tree with Engineering
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hEngineering;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =401+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}

	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = "Mechanics";
	TreeCtrlItem.item.lParam = 500;
	HTREEITEM hMechanics = m_Tree.InsertItem(&TreeCtrlItem);
	
	for(i=0;i<21;i++)
	{
		//build tree with Mechanics
		iEnd=szNames.Find("|",0);
		if(iEnd!=0)
		{
			TreeCtrlItem.hParent = hMechanics;
			CString h=szNames.Left(iEnd);
			TreeCtrlItem.item.pszText =(LPTSTR)(LPCTSTR)h;
			szNames=szNames.Right(szNames.GetLength()-iEnd-1);
			TreeCtrlItem.item.lParam =501+i;
			m_Tree.InsertItem(&TreeCtrlItem);
		}
	}
	iLastPos=-1;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGrandPrixWorldDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGrandPrixWorldDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGrandPrixWorldDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGrandPrixWorldDlg::OnFileExit() 
{
	OnOK();	
}

void CGrandPrixWorldDlg::OnFileOpen() 
{
TCHAR szFilter[]=_T("Grand Prix World Save File (*.sav)\0*.sav\0All Files (*.*)\0*.*\0\0");
	//Show open dialog
	CFileDialog fDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrTitle="Open GPW Save File";
	CString szDir = m_Common.RegGetValue("Software\\VG Software\\GPWEdit","GPWDir");
	fDialog.m_ofn.lpstrInitialDir = szDir;
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		BeginWaitCursor();
		m_Tree.EnableWindow(TRUE);
		m_Data.m_File = fDialog.m_ofn.lpstrFile;
		m_Data.LoadFile();
		SetWindowText("GPWEdit " + m_Data.m_File);

		//Disable/enable menu items
		CMenu* m=GetMenu();
		EnableMenuItem(m->m_hMenu,ID_FILE_SAVE,MF_ENABLED);
		EnableMenuItem(m->m_hMenu,IDC_FILE_SAVEAS,MF_ENABLED);
		EnableMenuItem(m->m_hMenu,IDC_FILE_CLOSE,MF_ENABLED);
		EnableMenuItem(m->m_hMenu,IDC_FILE_EXPORT,MF_ENABLED);
		EnableMenuItem(m->m_hMenu,IDC_FILE_IMPORT,MF_ENABLED);
		m_Tree.SetFocus();
		EndWaitCursor();
	}	
}

CString CGrandPrixWorldDlg::GetFile(CString sPath)
{
	DWORD dwSize;
	DWORD dwReadSize;
	HANDLE hFile = CreateFile((LPCTSTR)sPath,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		(HANDLE)NULL);
	dwSize=GetFileSize(hFile,NULL);
	char *lpBuffer = (char *)GlobalAlloc( GMEM_FIXED, dwSize );
	ReadFile(hFile,(LPVOID)lpBuffer, dwSize, &dwReadSize,NULL);
	CloseHandle(hFile);
	return(lpBuffer);
}

void CGrandPrixWorldDlg::OnSelchangedTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
CWnd* c=GetDlgItem(IDC_FRAME);

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	iCurPos=(int)pNMTreeView->itemNew.lParam;
	if(iCurPos>=100&&iCurPos<200)
	{
		//Drivers
		c->SetWindowText("Driver Info");
		if(iCurPos==100)
		{
			iShowNext=-1;
			SaveLastClick();
			iCurShow=-1;
		}
		else
		{
			iShowNext=1;
			SaveLastClick();
			if(iCurShow!=1)
				ShowDriver(true);
			m_Driver_Salary=m_Data.iDriver[0][iCurPos-101];
			m_Driver_RaceBonus=m_Data.iDriver[1][iCurPos-101];
			m_Driver_CHBonus=m_Data.iDriver[2][iCurPos-101];
			m_Driver_Points=m_Data.iDriver[3][iCurPos-101];
			m_Driver_Speed=m_Data.iDriver[4][iCurPos-101];
			m_Driver_Overtaking=m_Data.iDriver[5][iCurPos-101];
			m_Driver_WetWether=m_Data.iDriver[6][iCurPos-101];
			m_Driver_Concentration =m_Data.iDriver[7][iCurPos-101];
			m_Driver_Experience=m_Data.iDriver[8][iCurPos-101];
			m_Driver_Stamina=m_Data.iDriver[9][iCurPos-101];
			m_Driver_Morale=m_Data.iDriver[10][iCurPos-101];
			m_Driver_Skill=m_Data.iDriver[11][iCurPos-101];
		}
	}
	else if(iCurPos>=200&&iCurPos<300)
	{
		//Comm
		if(iCurPos==200)
		{
			c->SetWindowText("Commercial Department Info");
			iShowNext=3;
			SaveLastClick();
			if(iCurShow!=3)
				ShowOtherRoot(true);
			m_OtherRoot_Trainee=m_Data.iRoot[0][0];
			m_OtherRoot_Average=m_Data.iRoot[1][0];
			m_OtherRoot_Good=m_Data.iRoot[2][0];
			m_OtherRoot_VeryGood=m_Data.iRoot[3][0];
			m_OtherRoot_Excellent=m_Data.iRoot[4][0];
			m_OtherRoot_Morale=m_Data.iRoot[5][0];
		}
		else
		{
			c->SetWindowText("Commercial Info");
			iShowNext=5;
			SaveLastClick();
			if(iCurShow!=5)
				ShowCommercial(true);
			m_Commercial_Salary = m_Data.iCommercial[0][iCurPos-201];
			m_Commercial_Royalty = m_Data.iCommercial[1][iCurPos-201];
			m_Commercial_Ability =m_Data.iCommercial[2][iCurPos-201];
			m_Commercial_LastYear =m_Data.iCommercial[3][iCurPos-201]+m_Data.iHead[3]-1;
		}
	}
	else if(iCurPos>=300&&iCurPos<400)
	{
		//Design
		if(iCurPos==300)
		{
			c->SetWindowText("Design Department Info");
			iShowNext=3;
			SaveLastClick();
			if(iCurShow!=3)
				ShowOtherRoot(true);
			m_OtherRoot_Trainee=m_Data.iRoot[0][1];
			m_OtherRoot_Average=m_Data.iRoot[1][1];
			m_OtherRoot_Good=m_Data.iRoot[2][1];
			m_OtherRoot_VeryGood=m_Data.iRoot[3][1];
			m_OtherRoot_Excellent=m_Data.iRoot[4][1];
			m_OtherRoot_Morale=m_Data.iRoot[5][1];
		}
		else
		{
			c->SetWindowText("Design Info");
			iShowNext=2;
			SaveLastClick();
			if(iCurShow!=2)
				ShowOther(true);
			m_Other_Salary=m_Data.iDesign[0][iCurPos-301];
			m_Other_RaceBonus=m_Data.iDesign[1][iCurPos-301];
			m_Other_WCBonus=m_Data.iDesign[2][iCurPos-301];
			m_Other_Ability=m_Data.iDesign[3][iCurPos-301];
			m_Other_LastYear=m_Data.iDesign[4][iCurPos-301]+m_Data.iHead[3]-1;
		}
	}
	else if(iCurPos>=400&&iCurPos<500)
	{
		//Eng
		if(iCurPos==400)
		{
			c->SetWindowText("Engineering Department Info");
			iShowNext=3;
			SaveLastClick();
			if(iCurShow!=3)
				ShowOtherRoot(true);
			m_OtherRoot_Trainee=m_Data.iRoot[0][2];
			m_OtherRoot_Average=m_Data.iRoot[1][2];
			m_OtherRoot_Good=m_Data.iRoot[2][2];
			m_OtherRoot_VeryGood=m_Data.iRoot[3][2];
			m_OtherRoot_Excellent=m_Data.iRoot[4][2];
			m_OtherRoot_Morale=m_Data.iRoot[5][2];
		}
		else
		{
			c->SetWindowText("Engineering Info");
			iShowNext=2;
			SaveLastClick();
			if(iCurShow!=2)
				ShowOther(true);
			m_Other_Salary=m_Data.iEngineering[0][iCurPos-401];
			m_Other_RaceBonus=m_Data.iEngineering[1][iCurPos-401];
			m_Other_WCBonus=m_Data.iEngineering[2][iCurPos-401];
			m_Other_Ability=m_Data.iEngineering[3][iCurPos-401];
			m_Other_LastYear=m_Data.iEngineering[4][iCurPos-401]+m_Data.iHead[3]-1;
		}
	}
	else if(iCurPos>=500&&iCurPos<600)
	{
		//Mec
		if(iCurPos==500)
		{
			c->SetWindowText("Mechanics Department Info");
			iShowNext=3;
			SaveLastClick();
			if(iCurShow!=3)
				ShowOtherRoot(true);
			m_OtherRoot_Trainee=m_Data.iRoot[0][3];
			m_OtherRoot_Average=m_Data.iRoot[1][3];
			m_OtherRoot_Good=m_Data.iRoot[2][3];
			m_OtherRoot_VeryGood=m_Data.iRoot[3][3];
			m_OtherRoot_Excellent=m_Data.iRoot[4][3];
			m_OtherRoot_Morale=m_Data.iRoot[5][3];
		}
		else
		{
			c->SetWindowText("Mechanics Info");
			iShowNext=2;
			SaveLastClick();
			if(iCurShow!=2)
				ShowOther(true);
			m_Other_Salary=m_Data.iMechanics[0][iCurPos-501];
			m_Other_RaceBonus=m_Data.iMechanics[1][iCurPos-501];
			m_Other_WCBonus=m_Data.iMechanics[2][iCurPos-501];
			m_Other_Ability=m_Data.iMechanics[3][iCurPos-501];
			m_Other_LastYear=m_Data.iMechanics[4][iCurPos-501]+m_Data.iHead[3]-1;
		}
	}
	else if(iCurPos>=600&&iCurPos<700)
	{
		//Team
		c->SetWindowText("Team Info");
		if(iCurPos==600)
		{
			iShowNext=-1;
			SaveLastClick();
			iCurShow=-1;
		}
		else
		{
			iShowNext=0;
			SaveLastClick();
			if(iCurShow!=0)
				ShowTeam(true);
			m_Team_Budget=m_Data.iTeam[0][iCurPos-601];
			m_Team_TestPrice=m_Data.iTeam[1][iCurPos-601];
			m_Team_Points=m_Data.iTeam[2][iCurPos-601];
		}
	}
	else if(iCurPos>=700&&iCurPos<800)
	{
		//Root
		c->SetWindowText("Save File Info");
		iShowNext=4;
		SaveLastClick();
		if(iCurShow!=4)
			ShowRoot(true);
		//Get Data
		m_Root_Created=m_Data.cCreated;
		m_Root_Created=m_Root_Created.Left(24);
		
		m_Root_Modified=m_Data.cModified;
		m_Root_Modified=m_Root_Modified.Left(24);
		
		m_Root_Player =m_Data.cPlayer;
		m_Root_Player=m_Root_Player.Left(m_Root_Player.GetLength()-5);

		m_Root_Points =m_Data.iHead[5];
		m_Root_Pos=m_Data.iHead[4];
		m_Root_Year=m_Data.iHead[3];
		m_Root_Years=m_Data.iHead[2];
		m_Root_Score=m_Data.iHead[1];
		m_Root_NextRace=m_Data.ConvertCountry(m_Data.iHead[6]);
		m_Root_Team=m_Data.ConvertTeam(m_Data.iHead[0]);
	}

	iLastPos=iCurPos;
	
	//free(&c);


	UpdateData(FALSE);
	*pResult = 0;
}
void CGrandPrixWorldDlg::OnSelchangingTreeView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CGrandPrixWorldDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	int retVal=MessageBox("Would you like to make a backup of "+m_Common.GetFileName(m_Data.m_File) +" ("+m_Common.GetFileNameNoExt(m_Common.GetFileName(m_Data.m_File))+".tmp)" ,"Backup",MB_YESNOCANCEL|MB_ICONQUESTION);
	if(IDYES)
	{
		CopyFile(m_Data.m_File,m_Common.GetFileNameNoExt(m_Data.m_File)+".tmp",FALSE);
	}
	if(retVal!=IDCANCEL)
	{
	
		BeginWaitCursor();
		SaveLastClick();
		m_Data.SaveFile();
		EndWaitCursor();
	}
}

void CGrandPrixWorldDlg::OnFileSaveas() 
{
	// TODO: Add your command handler code here
TCHAR szFilter[]=_T("GPWEdit Save File (*.sav)\0*.sav\0All Files (*.*)\0*.*\0\0");
	//Show save dialog
	SaveLastClick();
	CFileDialog fDialog(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrTitle="Save as";
	fDialog.m_ofn.lpstrDefExt="sav";
ShowDialog:
	if(fDialog.DoModal())
	{
		BeginWaitCursor();

		if(CopyFile(m_Data.m_File,fDialog.m_ofn.lpstrFile,TRUE))
		{
			m_Data.m_File=fDialog.m_ofn.lpstrFile;
			m_Data.SaveFile();
		}
		else
		{
			CString szTmp=fDialog.m_ofn.lpstrFileTitle;
			int tmp;
			tmp=MessageBox("The file "+szTmp+" already exists. Do you want to replace the exisiting file?","GPWEdit",MB_ICONEXCLAMATION|MB_YESNOCANCEL);
			if(tmp==IDYES)
			{
				CopyFile(m_Data.m_File,fDialog.m_ofn.lpstrFile,FALSE);
				m_Data.m_File=fDialog.m_ofn.lpstrFile;
				m_Data.SaveFile();
			}	
			else if(tmp==IDNO)
				goto ShowDialog;
		}
		EndWaitCursor();
	}
}

void CGrandPrixWorldDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
CAboutDlg About;
	About.DoModal();
}

void CGrandPrixWorldDlg::OnHelpOnline() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL,"open","http://www.vgsoftware.com/",NULL,NULL,1);	
}

void CGrandPrixWorldDlg::OnEDITGPWPath() 
{
CString szPath;
	// TODO: Add your command handler code here
	szPath=m_Common.BrowseForFolders("Grand Prix World Directory",m_hWnd);
	if(szPath!="")
	{
		m_Common.RegSaveValue("Software\\VG Software\\GPWEdit","GPWDir",szPath);
	}	
}


void CGrandPrixWorldDlg::OnFileExport() 
{
	// TODO: Add your command handler code here

TCHAR szFilter[]=_T("GPWEdit Save File (*.gsf)\0*.gsf\0All Files (*.*)\0*.*\0\0");
	//Show save dialog
	CFileDialog fDialog(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrTitle="Export GPWFile Data";
	fDialog.m_ofn.lpstrDefExt="gsf";
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		BeginWaitCursor();
		m_Data.SaveData(fDialog.m_ofn.lpstrFile);
		EndWaitCursor();
	}
}


void CGrandPrixWorldDlg::OnFileImport() 
{
	// TODO: Add your command handler code here
TCHAR szFilter[]=_T("GPWEdit Save File (*.gsf)\0*.gsf\0All Files (*.*)\0*.*\0\0");
	//Show open dialog
	CFileDialog fDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_EXPLORER, NULL, NULL);
	fDialog.m_ofn.lpstrFilter=szFilter;
	fDialog.m_ofn.lpstrTitle="Import GPWEdit File Data";
	int iReturn = fDialog.DoModal();
	if(iReturn ==  IDOK)
	{
		BeginWaitCursor();
		m_Data.LoadData(fDialog.m_ofn.lpstrFile);
		EndWaitCursor();
	}
}

void CGrandPrixWorldDlg::ShowDriver(bool show)
{
	if(show==true)
		iCurShow=1;
	GetDlgItem(IDC_DRIVER_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_RACEBONUS)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_RACEBONUS)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_CHBONUS)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_WCBONUS)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_SPEED)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_SPEED)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_SKILL)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_SKILL)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_OVERTAKING)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_OVERTAKING)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_WETWETHER)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_WETWETHER)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_CONCENTRATION)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_CONCENTRATION)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_EXPERIENCE)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_EXPERIENCE)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STAMINA)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_STAMINA)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_MORALE)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_MORALE)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_POINTS)->ShowWindow(show);
	GetDlgItem(IDC_DRIVER_STATIC_POINTS)->ShowWindow(show);
}

void CGrandPrixWorldDlg::ShowRoot(bool show)
{
	if(show==true)
		iCurShow=4;
	GetDlgItem(IDC_ROOT_PLAYER)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_PLAYER)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_TEAM)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_TEAM)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_CREATED)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_CREATED)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_MODIFIED)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_MODIFIED)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_SCORE)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_SCORE)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_YEARS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_YEARS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_YEAR)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_YEAR)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_POS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_POS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_POINTS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_POINTS)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_NEXTRACE)->ShowWindow(show);
	GetDlgItem(IDC_ROOT_STATIC_NEXTRACE)->ShowWindow(show);
}

void CGrandPrixWorldDlg::ShowCommercial(bool show)
{
	if(show==true)
		iCurShow=5;
	GetDlgItem(IDC_COMMERCIAL_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_STATIC_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_ROYALTY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_STATIC_ROYALTY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_ABILITY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_STATIC_ABILITY)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_LASTYEAR)->ShowWindow(show);
	GetDlgItem(IDC_COMMERCIAL_STATIC_LASTYEAR)->ShowWindow(show);
}

void CGrandPrixWorldDlg::ShowTeam(bool show)
{
	if(show==true)
		iCurShow=0;
	GetDlgItem(IDC_TEAM_BUDGET)->ShowWindow(show);
	GetDlgItem(IDC_TEAM_STATIC_BUDGET)->ShowWindow(show);
	GetDlgItem(IDC_TEAM_TESTPRICE)->ShowWindow(show);
	GetDlgItem(IDC_TEAM_STATIC_TESTPRICE)->ShowWindow(show);
	GetDlgItem(IDC_TEAM_POINTS)->ShowWindow(show);
	GetDlgItem(IDC_TEAM_STATIC_POINTS)->ShowWindow(show);
}

void CGrandPrixWorldDlg::ShowOther(bool show)
{
	if(show==true)
		iCurShow=2;
	GetDlgItem(IDC_OTHER_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_STATIC_SALARY)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_RACEBONUS)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_STATIC_RACEBONUS)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_CHBONUS)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_STATIC_WCBONUS)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_ABILITY)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_STATIC_ABILITY)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_LASTYEAR)->ShowWindow(show);
	GetDlgItem(IDC_OTHER_STATIC_LASTYEAR)->ShowWindow(show);
}

void CGrandPrixWorldDlg::ShowOtherRoot(bool show)
{
	if(show==true)
		iCurShow=3;
	GetDlgItem(IDC_OTHERROOT_EXCELLENT)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_EXCELLENT)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_VERYGOOD)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_VERYGOOD)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_GOOD)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_GOOD)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_AVERAGE)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_AVERAGE)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_TRAINEE)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_TRAINEE)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_MORALE)->ShowWindow(show);
	GetDlgItem(IDC_OTHERROOT_STATIC_MORALE)->ShowWindow(show);
}

void CGrandPrixWorldDlg::SaveLastClick()
{
	UpdateData(TRUE);
	if(iLastPos>=101&&iLastPos<200)
	{
		//Drivers
		m_Data.iDriver[0][iLastPos-101]=m_Driver_Salary;
		m_Data.iDriver[1][iLastPos-101]=m_Driver_RaceBonus;
		m_Data.iDriver[2][iLastPos-101]=m_Driver_CHBonus;
		m_Data.iDriver[3][iLastPos-101]=m_Driver_Points;
		m_Data.iDriver[4][iLastPos-101]=m_Driver_Speed;
		m_Data.iDriver[5][iLastPos-101]=m_Driver_Overtaking;
		m_Data.iDriver[6][iLastPos-101]=m_Driver_WetWether;
		m_Data.iDriver[7][iLastPos-101]=m_Driver_Concentration;
		m_Data.iDriver[8][iLastPos-101]=m_Driver_Experience;
		m_Data.iDriver[9][iLastPos-101]=m_Driver_Stamina;
		m_Data.iDriver[10][iLastPos-101]=m_Driver_Morale;
		m_Data.iDriver[11][iLastPos-101]=m_Driver_Skill;
	}
	else if(iLastPos>=200&&iLastPos<300)
	{
		//Comm
		if(iLastPos==200)
		{
			m_Data.iRoot[0][0]=m_OtherRoot_Trainee;
			m_Data.iRoot[1][0]=m_OtherRoot_Average;
			m_Data.iRoot[2][0]=m_OtherRoot_Good;
			m_Data.iRoot[3][0]=m_OtherRoot_VeryGood;
			m_Data.iRoot[4][0]=m_OtherRoot_Excellent;
			m_Data.iRoot[5][0]=m_OtherRoot_Morale;
		}
		else
		{
			m_Data.iCommercial[0][iLastPos-201]=m_Commercial_Salary;
			m_Data.iCommercial[1][iLastPos-201]=m_Commercial_Royalty;
			m_Data.iCommercial[2][iLastPos-201]=m_Commercial_Ability;
			m_Data.iCommercial[3][iLastPos-201]=m_Commercial_LastYear-m_Data.iHead[3]+1;
		}
	}
	else if(iLastPos>=300&&iLastPos<400)
	{
		//Design
		if(iLastPos==300)
		{
			m_Data.iRoot[0][1]=m_OtherRoot_Trainee;
			m_Data.iRoot[1][1]=m_OtherRoot_Average;
			m_Data.iRoot[2][1]=m_OtherRoot_Good;
			m_Data.iRoot[3][1]=m_OtherRoot_VeryGood;
			m_Data.iRoot[4][1]=m_OtherRoot_Excellent;
			m_Data.iRoot[5][1]=m_OtherRoot_Morale;
		}
		else
		{
			m_Data.iDesign[0][iLastPos-301]=m_Other_Salary;
			m_Data.iDesign[1][iLastPos-301]=m_Other_RaceBonus;
			m_Data.iDesign[2][iLastPos-301]=m_Other_WCBonus;
			m_Data.iDesign[3][iLastPos-301]=m_Other_Ability;
			m_Data.iDesign[4][iLastPos-301]=m_Other_LastYear-m_Data.iHead[3]+1;		
		}
	}
	else if(iLastPos>=400&&iLastPos<500)
	{
		//Eng
		if(iLastPos==400)
		{
			m_Data.iRoot[0][2]=m_OtherRoot_Trainee;
			m_Data.iRoot[1][2]=m_OtherRoot_Average;
			m_Data.iRoot[2][2]=m_OtherRoot_Good;
			m_Data.iRoot[3][2]=m_OtherRoot_VeryGood;
			m_Data.iRoot[4][2]=m_OtherRoot_Excellent;
			m_Data.iRoot[5][2]=m_OtherRoot_Morale;
		}
		else
		{
			m_Data.iEngineering[0][iLastPos-401]=m_Other_Salary;
			m_Data.iEngineering[1][iLastPos-401]=m_Other_RaceBonus;
			m_Data.iEngineering[2][iLastPos-401]=m_Other_WCBonus;
			m_Data.iEngineering[3][iLastPos-401]=m_Other_Ability;
			m_Data.iEngineering[4][iLastPos-401]=m_Other_LastYear-m_Data.iHead[3]+1;
		}
	}
	else if(iLastPos>=500&&iLastPos<600)
	{
		//Mec
		if(iLastPos==500)
		{
			m_Data.iRoot[0][3]=m_OtherRoot_Trainee;
			m_Data.iRoot[1][3]=m_OtherRoot_Average;
			m_Data.iRoot[2][3]=m_OtherRoot_Good;
			m_Data.iRoot[3][3]=m_OtherRoot_VeryGood;
			m_Data.iRoot[4][3]=m_OtherRoot_Excellent;
			m_Data.iRoot[5][3]=m_OtherRoot_Morale;
		}
		else
		{
			m_Data.iMechanics[0][iLastPos-501]=m_Other_Salary;
			m_Data.iMechanics[1][iLastPos-501]=m_Other_RaceBonus;
			m_Data.iMechanics[2][iLastPos-501]=m_Other_WCBonus;
			m_Data.iMechanics[3][iLastPos-501]=m_Other_Ability;
			m_Data.iMechanics[4][iLastPos-501]=m_Other_LastYear-m_Data.iHead[3]+1;
		}
	}
	else if(iLastPos>=601&&iLastPos<700)
	{
		//Team
		m_Data.iTeam[0][iLastPos-601]=m_Team_Budget;
		m_Data.iTeam[1][iLastPos-601]=m_Team_TestPrice;
		m_Data.iTeam[2][iLastPos-601]=m_Team_Points;
	}
	else if(iLastPos>=700&&iLastPos<800)
	{
		//Root
	}

	if(iShowNext!=iCurShow)
	{
		if(iCurShow==0)
			ShowTeam(false);
		else if(iCurShow==1)
			ShowDriver(false);
		else if(iCurShow==2)
			ShowOther(false);
		else if(iCurShow==3)
			ShowOtherRoot(false);
		else if(iCurShow==4)
			ShowRoot(false);
		else if(iCurShow==5)
			ShowCommercial(false);
	}
}

void CGrandPrixWorldDlg::OnFileClose() 
{
	//Disable/enable menu items
	CMenu* m=GetMenu();
	EnableMenuItem(m->m_hMenu,ID_FILE_SAVE,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_SAVEAS,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_CLOSE,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_EXPORT,MF_GRAYED);
	EnableMenuItem(m->m_hMenu,IDC_FILE_IMPORT,MF_GRAYED);
	SetWindowText("GPWEdit");

	m_Data.m_File="";
	m_Tree.EnableWindow(FALSE);
	ShowTeam(false);
	ShowDriver(false);
	ShowOther(false);
	ShowOtherRoot(false);
	ShowRoot(false);
	ShowCommercial(false);
	CWnd* c=GetDlgItem(IDC_FRAME);
	c->SetWindowText("");
}

void CGrandPrixWorldDlg::OnHelpHowto() 
{
	CString sPath=m_Common.AppPath();	
	sPath+="Help\\Howto.htm";
	ShellExecute(m_hWnd,"open",sPath,NULL,NULL,1);
}

void CGrandPrixWorldDlg::OnHelpMenuhelp() 
{
	CString sPath=m_Common.AppPath();	
	sPath+="Help\\Menu.htm";
	ShellExecute(m_hWnd,"open",sPath,NULL,NULL,1);
}
