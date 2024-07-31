// Gp3 Setup SpliterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Gp3 Setup Spliter.h"
#include "Gp3 Setup SpliterDlg.h"

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
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
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
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp3SetupSpliterDlg dialog

CGp3SetupSpliterDlg::CGp3SetupSpliterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGp3SetupSpliterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGp3SetupSpliterDlg)
	m_RightFrontRearRebound = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGp3SetupSpliterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGp3SetupSpliterDlg)
	DDX_Control(pDX, IDC_TREE, m_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGp3SetupSpliterDlg, CDialog)
	//{{AFX_MSG_MAP(CGp3SetupSpliterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_VGSOFTWAREONLINE, OnHelpVgsoftwareonline)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_COMMAND(ID_FILE_SAVEASGP2, OnFileSaveasgp2)
	ON_COMMAND(ID_FILE_SAVEASGP3, OnFileSaveasgp3)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_EXTRACTASGP2, OnFileExtractasgp2)
	ON_COMMAND(ID_FILE_EXTRACTASGP3, OnFileExtractasgp3)
	ON_NOTIFY(NM_RCLICK, IDC_TREE, OnRclickTree)
	ON_COMMAND(ID_FILE_CLOSEALL, OnFileCloseall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGp3SetupSpliterDlg message handlers

BOOL CGp3SetupSpliterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	/*
	* Build tabs
	*/
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Init Dialog");
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Build Property Sheet");
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Adding Misc");
#endif
	m_PropertySheet.AddPage(&m_Misc);
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Adding Front");
#endif
	m_PropertySheet.AddPage(&m_Front);
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Adding Rear");
#endif
	m_PropertySheet.AddPage(&m_Rear);
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Create Property Sheet");
#endif
	m_PropertySheet.Create(this,WS_CHILD|WS_VISIBLE|WS_TABSTOP,WS_EX_CONTROLPARENT);
	CRect rcSheet;
	GetDlgItem(IDC_TAB_HOLDER)->GetWindowRect(&rcSheet);
	ScreenToClient(&rcSheet);
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Set Property Sheet winpos");
#endif
	m_PropertySheet.SetWindowPos(NULL,rcSheet.left-7,rcSheet.top-7,0,0,SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);

	/**
	 * Build image list and add it to the tree view
	 */
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Build Imagelist for tree");
#endif
	CGp3SetupSpliterApp* pApp;
	pApp = (CGp3SetupSpliterApp*)AfxGetApp();

	m_pImageList=new CImageList();
	m_pImageList->Create(16, 16, ILC_MASK|ILC_COLOR8, 2, 2);
	m_pImageList->Add(pApp->LoadIcon(IDI_OPEN));//			0
	m_pImageList->Add(pApp->LoadIcon(IDI_CLOSED));//		1
	m_pImageList->Add(pApp->LoadIcon(IDI_SETUP));//		2

	m_Tree.SetImageList(m_pImageList,TVSIL_NORMAL);

	m_iCurNode=-1;
	/*
	* Build standard tree
	*/
#ifdef __debug__
				CGp3SetupSpliterApp::m_LogTrace.WriteLine("CGp3SetupSpliterDlg: Build track name list's");
#endif
	strcpy(m_Gp3TrackName[0],"Melbourne");
	strcpy(m_Gp3TrackName[1],"Interlagos");
	strcpy(m_Gp3TrackName[2],"Buenos Aires");
	strcpy(m_Gp3TrackName[3],"Imola");
	strcpy(m_Gp3TrackName[4],"Barcelona");
	strcpy(m_Gp3TrackName[5],"Monte-Carlo");
	strcpy(m_Gp3TrackName[6],"Montreal");
	strcpy(m_Gp3TrackName[7],"Magny Cours");
	strcpy(m_Gp3TrackName[8],"Silverstone");
	strcpy(m_Gp3TrackName[9],"Spielberg");
	strcpy(m_Gp3TrackName[10],"Hockenheim");
	strcpy(m_Gp3TrackName[11],"Budapest");
	strcpy(m_Gp3TrackName[12],"Spa-Francorchamps");
	strcpy(m_Gp3TrackName[13],"Monza");
	strcpy(m_Gp3TrackName[14],"Nürburgring");
	strcpy(m_Gp3TrackName[15],"Suzuka");

	strcpy(m_Gp2TrackName[0],"Interlagos");
	strcpy(m_Gp2TrackName[1],"TI Circuit Aida");
	strcpy(m_Gp2TrackName[2],"Imola");
	strcpy(m_Gp2TrackName[3],"Monte-Carlo");
	strcpy(m_Gp2TrackName[4],"Barcelona");
	strcpy(m_Gp2TrackName[5],"Gilles Villeneuve");
	strcpy(m_Gp2TrackName[6],"Magny Cours");
	strcpy(m_Gp2TrackName[7],"Silverstone");
	strcpy(m_Gp2TrackName[8],"Hockenheim");
	strcpy(m_Gp2TrackName[9],"Hungaroring");
	strcpy(m_Gp2TrackName[10],"Spa-Francorchamps");
	strcpy(m_Gp2TrackName[11],"Monza");
	strcpy(m_Gp2TrackName[12],"Estoril");
	strcpy(m_Gp2TrackName[13],"Jerez");
	strcpy(m_Gp2TrackName[14],"Suzuka");
	strcpy(m_Gp2TrackName[15],"Adelaide");

	BuildTree();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGp3SetupSpliterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGp3SetupSpliterDlg::OnPaint() 
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
HCURSOR CGp3SetupSpliterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGp3SetupSpliterDlg::OnFileExit() 
{
	OnOK();	
}

void CGp3SetupSpliterDlg::OnHelpVgsoftwareonline() 
{
	ShellExecute(NULL,"open","http://www.vgsoftware.com/",NULL,NULL,1);
}

void CGp3SetupSpliterDlg::OnHelpAbout() 
{
	CAboutDlg ab;
	ab.DoModal();
}

void CGp3SetupSpliterDlg::OnFileOpen() 
{
	POSITION pos;
	char* tmp;
	CString FileName("");
	CFileDialog fileDlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"GpX Setup File (*.cs*;*.tsu)|*.cs*;*.tsu|",NULL);
	if(fileDlg.DoModal()==IDOK)
	{
		pos = fileDlg.GetStartPosition();
		while(pos!=NULL)
		{
			FileName=fileDlg.GetNextPathName(pos);
			m_SetupFile=new CSetupFile;
			tmp=new char[FileName.GetLength()+1];
			strcpy(tmp,FileName);
			if(m_SetupFile->OpenFile(tmp)==true)
			{
				m_SetupFileList.Add(m_SetupFile);
			}
			else
			{
				delete m_SetupFile;
			}
			delete[] tmp;
		};
		BuildTree();
	}
}

void CGp3SetupSpliterDlg::OnFileClose() 
{
	if(m_iCurNode!=-1)
	{
		m_SetupFileList.Remove(m_iCurNode);
		m_iCurNode=-1;
		BuildTree();
	}
}

void CGp3SetupSpliterDlg::LoadSetup()
{
	m_Misc.SetGpXSetupFile(m_SetupFile,m_Id);
	m_Front.SetGpXSetupFile(m_SetupFile,m_Id);
	m_Rear.SetGpXSetupFile(m_SetupFile,m_Id);
}

HTREEITEM CGp3SetupSpliterDlg::BuildNode(LPSTR szText, int Image, int SelectedImage, char* id, HTREEITEM Parant)
{
	TV_ITEM tvItem;
	TV_INSERTSTRUCT tvIns;

	// The pszText, iImage, and iSelectedImage members are filled out.
	tvItem.mask						= TVIF_TEXT | TVIF_PARAM|TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tvItem.pszText				= szText;
	tvItem.iImage					= Image;
	tvItem.iSelectedImage = SelectedImage;
	tvItem.lParam					=(LPARAM)id;

	tvIns.hParent					= Parant;
	tvIns.hInsertAfter		= TVI_LAST;
	tvIns.item=tvItem;

	return(m_Tree.InsertItem(&tvIns));
}

/**
 * Pos in list, Track Nr, Track Setup
 */
void CGp3SetupSpliterDlg::BuildTree()
{
/*
	HTREEITEM hRoot;
	HTREEITEM hChild;
	*/
	for(int iLoop=0;iLoop<m_SetupFileList.GetSize();iLoop++)
	{
			char* FileTitle;
			char * pBuffer;
			pBuffer=new char[_MAX_PATH];
			strcpy(pBuffer,m_SetupFile->GetFileName());
			FileTitle=GetFileTitle(pBuffer);
			delete[] pBuffer;
			delete[] FileTitle;
	}
/*
	HTREEITEM hRoot;
	HTREEITEM hChild;
	HTREEITEM hChildChild;
	HTREEITEM hChildChildChild;
	char *cBuffer;
	char *cTrack;
	m_Tree.DeleteAllItems();
	cBuffer=new char[15];
	cBuffer[0]='\0';
	sprintf(cBuffer,"%d%d%d",-1,-1,-1);
	hRoot=BuildNode("GpX Setup File Editor",1,0,cBuffer,TVI_ROOT);

	for(int iLoop=0;iLoop<m_SetupFileList.GetSize();iLoop++)
	{
		m_SetupFile = m_SetupFileList.GetItem(iLoop);
		if(m_SetupFile->GetFileType()<3)
		{
			cBuffer = new char[7];
			char* FileTitle;
			FileTitle=GetFileTitle(m_SetupFile->GetFileName());
			itoa(iLoop+1,cBuffer,10);
			cTrack=new char[strlen(cBuffer) + strlen(GetFileTitle(m_SetupFile->GetFileName()))+9];
			if(m_SetupFile->GetFileType()==1)
				sprintf(cTrack,"%s. %s %s",cBuffer,GetFileTitle(m_SetupFile->GetFileName()),"[Gp2]");
			else
				sprintf(cTrack,"%s. %s %s",cBuffer,GetFileTitle(m_SetupFile->GetFileName()),"[Gp3]");
			delete[] cBuffer;
			cBuffer=new char[7];
			sprintf(cBuffer,"%.2d%.2d%.2d",iLoop,0,0);
			hChild = BuildNode(cTrack,2,2,cBuffer,hRoot);
			delete[] cBuffer;
			delete[] FileTitle;
		}
		else
		{
			cBuffer = new char[7];
			itoa(iLoop+1,cBuffer,10);
			cTrack=new char[strlen(cBuffer) + strlen(GetFileTitle(m_SetupFile->GetFileName()))+9];
			if(m_SetupFile->GetFileType()==3)
				sprintf(cTrack,"%s. %s %s",cBuffer,GetFileTitle(m_SetupFile->GetFileName()),"[Gp2]");
			else
				sprintf(cTrack,"%s. %s %s",cBuffer,GetFileTitle(m_SetupFile->GetFileName()),"[Gp3]");
			delete[] cBuffer;
			cBuffer = new char[7];
			sprintf(cBuffer,"%.2d%d%d",iLoop,-1,-1);
			hChild=BuildNode(cTrack,1,0,cBuffer,hRoot);
			for(int i=0;i<16;i++)
			{
				cBuffer = new char[7];
				cTrack = new char[50];
				sprintf(cBuffer,"%.2d%d%d",iLoop,-1,-1);
				if(m_SetupFile->GetFileType()==4)
					sprintf(cTrack,"%s %d, %s","Track",i+1,m_Gp3TrackName[i]);
				else
					sprintf(cTrack,"%s %d, %s","Track",i+1,m_Gp2TrackName[i]);
				hChildChild=BuildNode(cTrack,1,0,cBuffer,hChild);
				delete[] cTrack;
				cBuffer = new char[7];
				sprintf(cBuffer,"%.2d%.2d%.2d",iLoop,i,0);
				hChildChildChild=BuildNode("Dry Qual",2,2,cBuffer,hChildChild);
				if(m_SetupFile->GetFileType()==4)
				{
					cBuffer = new char[7];
					sprintf(cBuffer,"%.2d%.2d%.2d",iLoop,i,1);
					hChildChildChild=BuildNode("Wet Qual",2,2,cBuffer,hChildChild);
				}
				cBuffer = new char[7];
				sprintf(cBuffer,"%.2d%.2d%.2d",iLoop,i,2);
				hChildChildChild=BuildNode("Dry Race",2,2,cBuffer,hChildChild);
				if(m_SetupFile->GetFileType()==4)
				{
					cBuffer = new char[7];
					sprintf(cBuffer,"%.2d%.2d%.2d",iLoop,i,3);
					hChildChildChild=BuildNode("Wet Race",2,2,cBuffer,hChildChild);
				}
			}
		}
	}
	m_iCurNode=-1;
	m_iCurTrack=-1;
	m_iCurType=-1;
	m_Tree.EnsureVisible(hChild);
	m_Tree.SelectItem(hRoot);
	if(m_SetupFileList.GetSize()==0)
		this->GetMenu()->EnableMenuItem(ID_FILE_CLOSEALL,TRUE);
	else
		this->GetMenu()->EnableMenuItem(ID_FILE_CLOSEALL,FALSE);*/
}

char* CGp3SetupSpliterDlg::GetFileTitle(char* FileName)
{
	char *NewFileName;
	int i = strlen(FileName);
	do
	{
		i--;
	}while(FileName[i]!='\\');
	int t=strlen(FileName);
	NewFileName=new char[t-i+1];
	i++;
	strncpy(NewFileName,&FileName[i],strlen(NewFileName)-1);
	int tt=strlen(NewFileName);
	return(NewFileName);
}

void CGp3SetupSpliterDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	SaveSetup();
	char* tmp;
	char tmp2[2];
	tmp=(char*)pNMTreeView->itemNew.lParam;
	if(strlen(tmp)==6)
	{
		sprintf(tmp2,"%c%c",tmp[0],tmp[1]);
		m_iCurNode=atoi(tmp2);
		sprintf(tmp2,"%c%c",tmp[2],tmp[3]);
		m_iCurTrack=atoi(tmp2);
		sprintf(tmp2,"%c%c",tmp[4],tmp[5]);
		m_iCurType=atoi(tmp2);
		SelChange();
	}
	m_Tree.SetFocus();
	*pResult = 0;
}

void CGp3SetupSpliterDlg::SelChange()
{
	if(m_iCurNode!=-1)
	{
		m_SetupFile = m_SetupFileList.GetItem(m_iCurNode);
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVE,FALSE);
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVEASGP2,FALSE);
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVEASGP3,FALSE);
		this->GetMenu()->EnableMenuItem(ID_FILE_CLOSE,FALSE);
		if(m_SetupFile->GetFileType()>2&&m_iCurTrack!=-1)
		{
			this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP3,FALSE);
			this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP2,FALSE);
		}
		else
		{
			this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP3,TRUE);
			this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP2,TRUE);
		}
		if(m_iCurTrack!=-1)
		{
			m_Id=m_iCurTrack*4+m_iCurType;
			switch(m_PropertySheet.GetActiveIndex())
			{
				case 0:
					m_Misc.EnableControls(true);
					break;
				case 1:
					m_Front.EnableControls(true);
					break;
				case 2:
					m_Rear.EnableControls(true);
					break;
			}
			m_PropertySheet.EnableWindow(TRUE);
			LoadSetup();
			m_PropertySheet.SetActivePage(m_PropertySheet.GetActiveIndex());
		}
		else
		{
			switch(m_PropertySheet.GetActiveIndex())
			{
				case 0:
					m_Misc.EnableControls(false);
					break;
				case 1:
					m_Front.EnableControls(false);
					break;
				case 2:
					m_Rear.EnableControls(false);
					break;
			}
			m_PropertySheet.EnableWindow(FALSE);
		}
	}
	else
	{
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVE,TRUE);
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVEASGP2,TRUE);
		this->GetMenu()->EnableMenuItem(ID_FILE_SAVEASGP3,TRUE);
		this->GetMenu()->EnableMenuItem(ID_FILE_CLOSE,TRUE);
		this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP3,TRUE);
		this->GetMenu()->EnableMenuItem(ID_FILE_EXTRACTASGP2,TRUE);

		switch(m_PropertySheet.GetActiveIndex())
		{
			case 0:
				m_Misc.EnableControls(false);
				break;
			case 1:
				m_Front.EnableControls(false);
				break;
			case 2:
				m_Rear.EnableControls(false);
				break;
		}
		m_PropertySheet.EnableWindow(FALSE);
	}
}

void CAboutDlg::OnButtonOk() 
{
	OnOK();	
}

void CGp3SetupSpliterDlg::SaveSetup()
{
	if(m_iCurTrack!=-1)
	{
		switch(m_PropertySheet.GetActiveIndex())
		{
			case 0:
				m_Misc.SaveSetup();
				break;
			case 1:
				m_Front.SaveSetup();
				break;
			case 2:
				m_Rear.SaveSetup();
				break;
		}
	}
}

void CGp3SetupSpliterDlg::OnFileSaveasgp2() 
{
	if(m_SetupFile->GetFileType()<3)
	{
		char *cFilter={"Track 1 (Interlagos, *.csa)|*.csa|Track 2 (TI Circuit Aida, *.csb)|*.csb|Track 3 (Imola, *.csc)|*.csc|Track 4 (Monte-Carlo, *.csd)|*.csd|Track 5 (Barcelona, *.cse)|*.cse|Track 6 (Gilles Villeneuve, *.csf)|*.csf|Track 7 (Magny Cours, *.csg)|*.csg|Track 8 (Silverstone, *.csh)|*.csh|Track 9 (Hockenheim, *.csi)|*.csi|Track 10 (Hungaroring, *.csj)|*.csj|Track 11 (Spa-Francorchamps, *.csk)|*.csk|Track 12 (Monza, *.csl)|*.csl|Track 13 (Estoril, *.csm)|*.csm|Track 14 (Jerez, *.csn)|*.csn|Track 15 (Suzuka, *.cso)|*.cso|Track 16 (Adelaide, *.csp)|*.csp|"};
		char *fileName;
		char tmp[5];
		CFileDialog fileDlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,cFilter,NULL);
		if(fileDlg.DoModal()==IDOK)
		{
			SaveSetup();
			if(fileDlg.GetFileExt()=="")
			{
				fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+5];
				strcpy(tmp,".cs");
				tmp[3]=(char)fileDlg.m_ofn.nFilterIndex+96;
				tmp[4]='\0';
				strcpy(fileName, fileDlg.m_ofn.lpstrFile);
				strcat(fileName,tmp);
			}
			else
			{
				fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+1];
				strcpy(fileName,fileDlg.m_ofn.lpstrFile);
			}
			m_SetupFile->SaveGp2File(fileDlg.m_ofn.nFilterIndex-1,((m_iCurTrack*4)+m_iCurType),fileName);
			BuildTree();
		}
	}
	else
	{
		CFileDialog fileDlg(FALSE,"tsu",NULL,NULL,"All Tracks (*.tsu)|*.tsu||",NULL);
		if(fileDlg.DoModal()==IDOK)
		{
			SaveSetup();
			m_SetupFile->SaveGp2MultiFile(fileDlg.m_ofn.lpstrFile);
			BuildTree();
		}
	}
}

void CGp3SetupSpliterDlg::OnFileSaveasgp3() 
{
	if(m_SetupFile->GetFileType()<3)
	{
		char *cFilter={"Track 1 (Melbourne, *.csa)|*.csa|Track 2 (Interlagos, *.csb)|*.csb|Track 3 (Buenos Aires, *.csc)|*.csc|Track 4 (Imola, *.csd)|*.csd|Track 5 (Barcelona, *.cse)|*.cse|Track 6 (Monte-Carlo, *.csf)|*.csf|Track 7 (Montreal, *.csg)|*.csg|Track 8 (Magny Cours, *.csh)|*.csh|Track 9 (Silverstone, *.csi)|*.csi|Track 10 (Spielberg, *.csj)|*.csj|Track 11 (Hockenheim, *.csk)|*.csk|Track 12 (Budapest, *.csl)|*.csl|Track 13 (Spa-Francorchamps, *.csm)|*.csm|Track 14 (Monza, *.csn)|*.csn|Track 15 (Nürburgring, *.cso)|*.cso|Track 16 (Suzuka, *.csp)|*.csp||"};
		char *fileName;
		char tmp[5];
		CFileDialog fileDlg(FALSE,NULL,NULL,NULL,cFilter,NULL);
		if(fileDlg.DoModal()==IDOK)
		{
			SaveSetup();
			if(fileDlg.GetFileExt()=="")
			{
				fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+5];
				strcpy(tmp,".cs");
				tmp[3]=(char)fileDlg.m_ofn.nFilterIndex+96;
				tmp[4]='\0';
				strcpy(fileName, fileDlg.m_ofn.lpstrFile);
				strcat(fileName,tmp);
			}
			else
			{
				fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+1];
				strcpy(fileName,fileDlg.m_ofn.lpstrFile);
			}
			m_SetupFile->SaveGp3File(fileDlg.m_ofn.nFilterIndex-1,((m_iCurTrack*4)+m_iCurType),fileName);
			BuildTree();
			delete[] fileName;
		}
	}
	else
	{
		CFileDialog fileDlg(FALSE,"tsu",NULL,NULL,"All Tracks (*.tsu)|*.tsu||",NULL);
		if(fileDlg.DoModal()==IDOK)
		{
			SaveSetup();
			m_SetupFile->SaveGp3MultiFile(fileDlg.m_ofn.lpstrFile);
			BuildTree();
		}
	}
}

void CGp3SetupSpliterDlg::OnFileSave() 
{
	SaveSetup();
	if(m_SetupFile->GetFileType()==1)
		m_SetupFile->SaveGp2File();
	else if(m_SetupFile->GetFileType()==2)
		m_SetupFile->SaveGp3File();
	else if(m_SetupFile->GetFileType()==3)
		m_SetupFile->SaveGp2MultiFile();
	else if(m_SetupFile->GetFileType()==4)
		m_SetupFile->SaveGp3MultiFile();
}

void CGp3SetupSpliterDlg::OnFileExtractasgp2() 
{
	char *cFilter={"Track 1 (Interlagos, *.csa)|*.csa|Track 2 (TI Circuit Aida, *.csb)|*.csb|Track 3 (Imola, *.csc)|*.csc|Track 4 (Monte-Carlo, *.csd)|*.csd|Track 5 (Barcelona, *.cse)|*.cse|Track 6 (Gilles Villeneuve, *.csf)|*.csf|Track 7 (Magny Cours, *.csg)|*.csg|Track 8 (Silverstone, *.csh)|*.csh|Track 9 (Hockenheim, *.csi)|*.csi|Track 10 (Hungaroring, *.csj)|*.csj|Track 11 (Spa-Francorchamps, *.csk)|*.csk|Track 12 (Monza, *.csl)|*.csl|Track 13 (Estoril, *.csm)|*.csm|Track 14 (Jerez, *.csn)|*.csn|Track 15 (Suzuka, *.cso)|*.cso|Track 16 (Adelaide, *.csp)|*.csp|"};
	char *fileName;
	char tmp[5];
	CFileDialog fileDlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,cFilter,NULL);
	if(fileDlg.DoModal()==IDOK)
	{
		SaveSetup();
		if(fileDlg.GetFileExt()=="")
		{
			fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+5];
			strcpy(tmp,".cs");
			tmp[3]=(char)fileDlg.m_ofn.nFilterIndex+96;
			tmp[4]='\0';
			strcpy(fileName, fileDlg.m_ofn.lpstrFile);
			strcat(fileName,tmp);
		}
		else
		{
			fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+1];
			strcpy(fileName,fileDlg.m_ofn.lpstrFile);
		}
		m_SetupFile->SaveGp2File(fileDlg.m_ofn.nFilterIndex-1,((m_iCurTrack*4)+m_iCurType),fileName);
		delete[] fileName;
	}
}

void CGp3SetupSpliterDlg::OnFileExtractasgp3() 
{
	char *cFilter={"Track 1 (Melbourne, *.csa)|*.csa|Track 2 (Interlagos, *.csb)|*.csb|Track 3 (Buenos Aires, *.csc)|*.csc|Track 4 (Imola, *.csd)|*.csd|Track 5 (Barcelona, *.cse)|*.cse|Track 6 (Monte-Carlo, *.csf)|*.csf|Track 7 (Montreal, *.csg)|*.csg|Track 8 (Magny Cours, *.csh)|*.csh|Track 9 (Silverstone, *.csi)|*.csi|Track 10 (Spielberg, *.csj)|*.csj|Track 11 (Hockenheim, *.csk)|*.csk|Track 12 (Budapest, *.csl)|*.csl|Track 13 (Spa-Francorchamps, *.csm)|*.csm|Track 14 (Monza, *.csn)|*.csn|Track 15 (Nürburgring, *.cso)|*.cso|Track 16 (Suzuka, *.csp)|*.csp||"};
	char *fileName;
	char tmp[5];
	CFileDialog fileDlg(FALSE,NULL,NULL,NULL,cFilter,NULL);
	if(fileDlg.DoModal()==IDOK)
	{
		SaveSetup();
		if(fileDlg.GetFileExt()=="")
		{
			fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+5];
			strcpy(tmp,".cs");
			tmp[3]=(char)fileDlg.m_ofn.nFilterIndex+96;
			tmp[4]='\0';
			strcpy(fileName, fileDlg.m_ofn.lpstrFile);
			strcat(fileName,tmp);
		}
		else
		{
			fileName=new char[strlen(fileDlg.m_ofn.lpstrFile)+1];
			strcpy(fileName,fileDlg.m_ofn.lpstrFile);
		}
		m_SetupFile->SaveGp3File(fileDlg.m_ofn.nFilterIndex-1,((m_iCurTrack*4)+m_iCurType),fileName);
		delete[] fileName;
	}
}

void CGp3SetupSpliterDlg::OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POINT pt;
	if(GetCursorPos(&pt))
	{
		TVHITTESTINFO HitTest;
		m_Tree.ScreenToClient(&pt);
		HitTest.pt.x =  pt.x;
		HitTest.pt.y = pt.y;
		HTREEITEM hItem = m_Tree.HitTest(&HitTest);
		if(hItem!=NULL)
			m_Tree.SelectItem(hItem);
		GetCursorPos(&pt);
	}
	if(m_iCurNode!=-1)
	{
		CMenu menu, *popup;
		menu.LoadMenu(IDR_POPUP);
		if(m_iCurType!=-1&&m_SetupFile->GetFileType()>2)
			popup = menu.GetSubMenu(1);
		else
			popup = menu.GetSubMenu(0);
		ASSERT(popup != NULL);
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y,AfxGetMainWnd());
	}
	*pResult = 0;
}

void CGp3SetupSpliterDlg::OnFileCloseall() 
{
	m_SetupFileList.Clear();
	m_iCurNode=-1;
	BuildTree();
}
