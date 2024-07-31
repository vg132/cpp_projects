// GPW Misc EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GPW Misc Edit.h"
#include "GPW Misc EditDlg.h"
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
	void SetSpin();
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
// CGPWMiscEditDlg dialog

CGPWMiscEditDlg::CGPWMiscEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGPWMiscEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGPWMiscEditDlg)
	m_Staff1 = 0;
	m_Staff2 = 0;
	m_Staff3 = 0;
	m_Staff4 = 0;
	m_Staff5 = 0;
	m_Factory1 = 0;
	m_Factory2 = 0;
	m_Factory4 = 0;
	m_Factory3 = 0;
	m_Factory5 = 0;
	m_Commercial_Average = 0;
	m_Commercial_Excellent = 0;
	m_Commercial_Good = 0;
	m_Commercial_Trainee = 0;
	m_Commercial_VeryGood = 0;
	m_Design_Average = 0;
	m_Design_Excellent = 0;
	m_Design_Good = 0;
	m_Design_Trainee = 0;
	m_Design_VeryGood = 0;
	m_Engineering_Average = 0;
	m_Engineering_VeryGood = 0;
	m_Engineering_Trainee = 0;
	m_Engineering_Good = 0;
	m_Engineering_Excellent = 0;
	m_Mechanics_VeryGood = 0;
	m_Mechanics_Trainee = 0;
	m_Mechanics_Good = 0;
	m_Mechanics_Excellent = 0;
	m_Mechanics_Average = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGPWMiscEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGPWMiscEditDlg)
	DDX_Control(pDX, IDC_SPIN9, m_Spin9);
	DDX_Control(pDX, IDC_SPIN7, m_Spin7);
	DDX_Control(pDX, IDC_SPIN8, m_Spin8);
	DDX_Control(pDX, IDC_SPIN5, m_Spin5);
	DDX_Control(pDX, IDC_SPIN6, m_Spin6);
	DDX_Control(pDX, IDC_SPIN30, m_Spin30);
	DDX_Control(pDX, IDC_SPIN4, m_Spin4);
	DDX_Control(pDX, IDC_SPIN29, m_Spin29);
	DDX_Control(pDX, IDC_SPIN28, m_Spin28);
	DDX_Control(pDX, IDC_SPIN26, m_Spin26);
	DDX_Control(pDX, IDC_SPIN27, m_Spin27);
	DDX_Control(pDX, IDC_SPIN3, m_Spin3);
	DDX_Control(pDX, IDC_SPIN25, m_Spin25);
	DDX_Control(pDX, IDC_SPIN24, m_Spin24);
	DDX_Control(pDX, IDC_SPIN23, m_Spin23);
	DDX_Control(pDX, IDC_SPIN22, m_Spin22);
	DDX_Control(pDX, IDC_SPIN21, m_Spin21);
	DDX_Control(pDX, IDC_SPIN20, m_Spin20);
	DDX_Control(pDX, IDC_SPIN2, m_Spin2);
	DDX_Control(pDX, IDC_SPIN19, m_Spin19);
	DDX_Control(pDX, IDC_SPIN18, m_Spin18);
	DDX_Control(pDX, IDC_SPIN17, m_Spin17);
	DDX_Control(pDX, IDC_SPIN16, m_Spin16);
	DDX_Control(pDX, IDC_SPIN15, m_Spin15);
	DDX_Control(pDX, IDC_SPIN14, m_Spin14);
	DDX_Control(pDX, IDC_SPIN13, m_Spin13);
	DDX_Control(pDX, IDC_SPIN12, m_Spin12);
	DDX_Control(pDX, IDC_SPIN11, m_Spin11);
	DDX_Control(pDX, IDC_SPIN10, m_Spin10);
	DDX_Control(pDX, IDC_SPIN1, m_Spin1);
	DDX_Text(pDX, IDC_STAFF_1, m_Staff1);
	DDV_MinMaxInt(pDX, m_Staff1, 0, 1000000);
	DDX_Text(pDX, IDC_STAFF_2, m_Staff2);
	DDV_MinMaxInt(pDX, m_Staff2, 0, 1000000);
	DDX_Text(pDX, IDC_STAFF_3, m_Staff3);
	DDV_MinMaxInt(pDX, m_Staff3, 0, 1000000);
	DDX_Text(pDX, IDC_STAFF_4, m_Staff4);
	DDV_MinMaxInt(pDX, m_Staff4, 0, 1000000);
	DDX_Text(pDX, IDC_STAFF_5, m_Staff5);
	DDV_MinMaxInt(pDX, m_Staff5, 0, 1000000);
	DDX_Text(pDX, IDC_FACTORY_1, m_Factory1);
	DDV_MinMaxInt(pDX, m_Factory1, 0, 1000000000);
	DDX_Text(pDX, IDC_FACTORY_2, m_Factory2);
	DDV_MinMaxInt(pDX, m_Factory2, 0, 1000000000);
	DDX_Text(pDX, IDC_FACTORY_4, m_Factory4);
	DDV_MinMaxInt(pDX, m_Factory4, 0, 1000000000);
	DDX_Text(pDX, IDC_FACTORY_3, m_Factory3);
	DDV_MinMaxInt(pDX, m_Factory3, 0, 1000000000);
	DDX_Text(pDX, IDC_FACTORY_5, m_Factory5);
	DDV_MinMaxInt(pDX, m_Factory5, 0, 1000000000);
	DDX_Text(pDX, IDC_COMMERCIAL_AVERAGE, m_Commercial_Average);
	DDV_MinMaxInt(pDX, m_Commercial_Average, 0, 1000000);
	DDX_Text(pDX, IDC_COMMERCIAL_EXCELLENT, m_Commercial_Excellent);
	DDV_MinMaxInt(pDX, m_Commercial_Excellent, 0, 1000000);
	DDX_Text(pDX, IDC_COMMERCIAL_GOOD, m_Commercial_Good);
	DDV_MinMaxInt(pDX, m_Commercial_Good, 0, 1000000);
	DDX_Text(pDX, IDC_COMMERCIAL_TRAINEE, m_Commercial_Trainee);
	DDV_MinMaxInt(pDX, m_Commercial_Trainee, 0, 1000000);
	DDX_Text(pDX, IDC_COMMERCIAL_VERYGOOD, m_Commercial_VeryGood);
	DDV_MinMaxInt(pDX, m_Commercial_VeryGood, 0, 1000000);
	DDX_Text(pDX, IDC_DESIGN_AVERAGE, m_Design_Average);
	DDV_MinMaxInt(pDX, m_Design_Average, 0, 1000000);
	DDX_Text(pDX, IDC_DESIGN_EXCELLENT, m_Design_Excellent);
	DDV_MinMaxInt(pDX, m_Design_Excellent, 0, 1000000);
	DDX_Text(pDX, IDC_DESIGN_GOOD, m_Design_Good);
	DDV_MinMaxInt(pDX, m_Design_Good, 0, 1000000);
	DDX_Text(pDX, IDC_DESIGN_TRAINEE, m_Design_Trainee);
	DDV_MinMaxInt(pDX, m_Design_Trainee, 0, 1000000);
	DDX_Text(pDX, IDC_DESIGN_VERYGOOD, m_Design_VeryGood);
	DDV_MinMaxInt(pDX, m_Design_VeryGood, 0, 1000000);
	DDX_Text(pDX, IDC_ENGINEERING_AVERAGE, m_Engineering_Average);
	DDV_MinMaxInt(pDX, m_Engineering_Average, 0, 1000000);
	DDX_Text(pDX, IDC_ENGINEERING_VERYGOOD, m_Engineering_VeryGood);
	DDV_MinMaxInt(pDX, m_Engineering_VeryGood, 0, 1000000);
	DDX_Text(pDX, IDC_ENGINEERING_TRAINEE, m_Engineering_Trainee);
	DDV_MinMaxInt(pDX, m_Engineering_Trainee, 0, 1000000);
	DDX_Text(pDX, IDC_ENGINEERING_GOOD, m_Engineering_Good);
	DDV_MinMaxInt(pDX, m_Engineering_Good, 0, 1000000);
	DDX_Text(pDX, IDC_ENGINEERING_EXCELLENT, m_Engineering_Excellent);
	DDV_MinMaxInt(pDX, m_Engineering_Excellent, 0, 1000000);
	DDX_Text(pDX, IDC_MECHANICS_VERYGOOD, m_Mechanics_VeryGood);
	DDV_MinMaxInt(pDX, m_Mechanics_VeryGood, 0, 1000000);
	DDX_Text(pDX, IDC_MECHANICS_TRAINEE, m_Mechanics_Trainee);
	DDV_MinMaxInt(pDX, m_Mechanics_Trainee, 0, 1000000);
	DDX_Text(pDX, IDC_MECHANICS_GOOD, m_Mechanics_Good);
	DDV_MinMaxInt(pDX, m_Mechanics_Good, 0, 1000000);
	DDX_Text(pDX, IDC_MECHANICS_EXCELLENT, m_Mechanics_Excellent);
	DDV_MinMaxInt(pDX, m_Mechanics_Excellent, 0, 1000000);
	DDX_Text(pDX, IDC_MECHANICS_AVERAGE, m_Mechanics_Average);
	DDV_MinMaxInt(pDX, m_Mechanics_Average, 0, 1000000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGPWMiscEditDlg, CDialog)
	//{{AFX_MSG_MAP(CGPWMiscEditDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_EDIT_GPWDIRECTORY, OnEditGpwdirectory)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_COMMAND(ID_FILE_EXPORT, OnFileExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGPWMiscEditDlg message handlers

BOOL CGPWMiscEditDlg::OnInitDialog()
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
	SetSpin();

	m_Path=m_Common.RegGetValue("Software\\VG Software\\GPW Misc Edit\\Settings","GPWPath");
	if(m_Path=="")
		OnEditGpwdirectory();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGPWMiscEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGPWMiscEditDlg::OnPaint() 
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
HCURSOR CGPWMiscEditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGPWMiscEditDlg::OnFileExit() 
{
	OnOK();	
}

void CGPWMiscEditDlg::OnHelpAbout() 
{
CAboutDlg ad;
	ad.DoModal();	
}

void CGPWMiscEditDlg::SetSpin()
{
	m_Spin1.SetRange32(0,1000000);
	m_Spin2.SetRange32(0,1000000);
	m_Spin3.SetRange32(0,1000000);
	m_Spin4.SetRange32(0,1000000);
	m_Spin5.SetRange32(0,1000000);
	m_Spin6.SetRange32(0,1000000);
	m_Spin7.SetRange32(0,1000000);
	m_Spin8.SetRange32(0,1000000);
	m_Spin9.SetRange32(0,1000000);
	m_Spin10.SetRange32(0,1000000);
	m_Spin11.SetRange32(0,1000000);
	m_Spin12.SetRange32(0,1000000);
	m_Spin13.SetRange32(0,1000000);
	m_Spin14.SetRange32(0,1000000);
	m_Spin15.SetRange32(0,1000000);
	m_Spin16.SetRange32(0,1000000);
	m_Spin17.SetRange32(0,1000000);
	m_Spin18.SetRange32(0,1000000);
	m_Spin19.SetRange32(0,1000000);
	m_Spin20.SetRange32(0,1000000);
	m_Spin21.SetRange32(0,1000000);
	m_Spin22.SetRange32(0,1000000);
	m_Spin23.SetRange32(0,1000000);
	m_Spin24.SetRange32(0,1000000);
	m_Spin25.SetRange32(0,1000000);
	m_Spin26.SetRange32(0,1000000000);
	m_Spin27.SetRange32(0,1000000000);
	m_Spin28.SetRange32(0,1000000000);
	m_Spin29.SetRange32(0,1000000000);
	m_Spin30.SetRange32(0,1000000000);
}

void CGPWMiscEditDlg::OnEditGpwdirectory() 
{
CString RetVal;

	RetVal=m_Common.BrowseForFolders("GPW Directory",m_hWnd);
	if(RetVal!="")
	{
		m_Path=RetVal;
		m_Common.RegSaveValue("Software\\VG Software\\GPW Misc Edit\\Settings","GPWPath",m_Path);
	}
	else
	{
		if(MessageBox("Please Select your Gpw Directory.","GPW Misc Edit",MB_ICONHAND | MB_RETRYCANCEL)==IDRETRY)
			OnEditGpwdirectory();
		else
			OnOK();
	}
}

void CGPWMiscEditDlg::OnFileImport() 
{
CFile f;
CString szFile;

	BeginWaitCursor();

	szFile=m_Path;
	if(m_Path.Right(1)!="\\")
		szFile+="\\gpw.exe";
	else
		szFile+="gpw.exe";
	f.Open(szFile,CFile::modeRead,NULL);
	
	f.Seek(2672644,CFile::begin);
	f.Read((char*)&m_Staff1,sizeof(int));
	f.Read((char*)&m_Staff2,sizeof(int));
	f.Read((char*)&m_Staff3,sizeof(int));
	f.Read((char*)&m_Staff4,sizeof(int));
	f.Read((char*)&m_Staff5,sizeof(int));

	f.Seek(2676700,CFile::begin);
	f.Read((char*)&m_Factory1,sizeof(int));
	f.Read((char*)&m_Factory2,sizeof(int));
	f.Read((char*)&m_Factory3,sizeof(int));
	f.Read((char*)&m_Factory4,sizeof(int));
	f.Read((char*)&m_Factory5,sizeof(int));

	f.Seek(2713836,CFile::begin);
	f.Read((char*)&m_Commercial_Trainee,sizeof(int));
	f.Read((char*)&m_Commercial_Average,sizeof(int));
	f.Read((char*)&m_Commercial_Good,sizeof(int));
	f.Read((char*)&m_Commercial_VeryGood,sizeof(int));
	f.Read((char*)&m_Commercial_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Read((char*)&m_Design_Trainee,sizeof(int));
	f.Read((char*)&m_Design_Average,sizeof(int));
	f.Read((char*)&m_Design_Good,sizeof(int));
	f.Read((char*)&m_Design_VeryGood,sizeof(int));
	f.Read((char*)&m_Design_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Read((char*)&m_Engineering_Trainee,sizeof(int));
	f.Read((char*)&m_Engineering_Average,sizeof(int));
	f.Read((char*)&m_Engineering_Good,sizeof(int));
	f.Read((char*)&m_Engineering_VeryGood,sizeof(int));
	f.Read((char*)&m_Engineering_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Read((char*)&m_Mechanics_Trainee,sizeof(int));
	f.Read((char*)&m_Mechanics_Average,sizeof(int));
	f.Read((char*)&m_Mechanics_Good,sizeof(int));
	f.Read((char*)&m_Mechanics_VeryGood,sizeof(int));
	f.Read((char*)&m_Mechanics_Excellent,sizeof(int));

	UpdateData(FALSE);
	EndWaitCursor();
}

void CGPWMiscEditDlg::OnFileExport() 
{
CFile f;
CString szFile;

	BeginWaitCursor();
	UpdateData(TRUE);

	szFile=m_Path;
	if(m_Path.Right(1)!="\\")
		szFile+="\\gpw.exe";
	else
		szFile+="gpw.exe";
	f.Open(szFile,CFile::modeWrite,NULL);
	
	f.Seek(2672644,CFile::begin);
	f.Write((char*)&m_Staff1,sizeof(int));
	f.Write((char*)&m_Staff2,sizeof(int));
	f.Write((char*)&m_Staff3,sizeof(int));
	f.Write((char*)&m_Staff4,sizeof(int));
	f.Write((char*)&m_Staff5,sizeof(int));

	f.Seek(2676700,CFile::begin);
	f.Write((char*)&m_Factory1,sizeof(int));
	f.Write((char*)&m_Factory2,sizeof(int));
	f.Write((char*)&m_Factory3,sizeof(int));
	f.Write((char*)&m_Factory4,sizeof(int));
	f.Write((char*)&m_Factory5,sizeof(int));

	f.Seek(2713836,CFile::begin);
	f.Write((char*)&m_Commercial_Trainee,sizeof(int));
	f.Write((char*)&m_Commercial_Average,sizeof(int));
	f.Write((char*)&m_Commercial_Good,sizeof(int));
	f.Write((char*)&m_Commercial_VeryGood,sizeof(int));
	f.Write((char*)&m_Commercial_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Write((char*)&m_Design_Trainee,sizeof(int));
	f.Write((char*)&m_Design_Average,sizeof(int));
	f.Write((char*)&m_Design_Good,sizeof(int));
	f.Write((char*)&m_Design_VeryGood,sizeof(int));
	f.Write((char*)&m_Design_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Write((char*)&m_Engineering_Trainee,sizeof(int));
	f.Write((char*)&m_Engineering_Average,sizeof(int));
	f.Write((char*)&m_Engineering_Good,sizeof(int));
	f.Write((char*)&m_Engineering_VeryGood,sizeof(int));
	f.Write((char*)&m_Engineering_Excellent,sizeof(int));

	f.Seek(4,CFile::current);
	f.Write((char*)&m_Mechanics_Trainee,sizeof(int));
	f.Write((char*)&m_Mechanics_Average,sizeof(int));
	f.Write((char*)&m_Mechanics_Good,sizeof(int));
	f.Write((char*)&m_Mechanics_VeryGood,sizeof(int));
	f.Write((char*)&m_Mechanics_Excellent,sizeof(int));

	EndWaitCursor();	
}
