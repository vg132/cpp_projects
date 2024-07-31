// SplitFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplitFile.h"
#include "SplitFileDlg.h"

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
// CSplitFileDlg dialog

CSplitFileDlg::CSplitFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSplitFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSplitFileDlg)
	m_File = _T("");
	m_StartPos = 0;
	m_Part1 = _T("");
	m_Part2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSplitFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplitFileDlg)
	DDX_Text(pDX, IDC_STATIC_FILE, m_File);
	DDX_Text(pDX, IDC_EDIT_START_POS, m_StartPos);
	DDV_MinMaxUInt(pDX, m_StartPos, 0, 4294967295);
	DDX_Text(pDX, IDC_STATIC_PART1, m_Part1);
	DDX_Text(pDX, IDC_STATIC_PART2, m_Part2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSplitFileDlg, CDialog)
	//{{AFX_MSG_MAP(CSplitFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SELECT_FILE, OnButtonSelectFile)
	ON_BN_CLICKED(IDC_BUTTON_SPLIT_FILE, OnButtonSplitFile)
	ON_BN_CLICKED(IDC_BUTTON_PART1, OnButtonPart1)
	ON_BN_CLICKED(IDC_BUTTON_PART2, OnButtonPart2)
	ON_BN_CLICKED(IDC_BUTTON_JOIN, OnButtonJoin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitFileDlg message handlers

BOOL CSplitFileDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSplitFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSplitFileDlg::OnPaint() 
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
HCURSOR CSplitFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSplitFileDlg::OnButtonSelectFile() 
{
	CFileDialog dlgFile(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"All files (*.*)|*.*||",NULL);
	if(dlgFile.DoModal()==IDOK)
	{
		m_File=dlgFile.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CSplitFileDlg::OnButtonSplitFile() 
{
	BeginWaitCursor();
	UpdateData(TRUE);
	DWORD dwCurPos;
	DWORD dwSize;
	DWORD dwReadSize=8096;
	char* pBuffer;
	CString pNewFileName;
	pNewFileName=m_File;
	pNewFileName+=".part2";

	CFile cOldFile,cNewFile;
	cOldFile.Open(m_File,CFile::modeRead);
	cNewFile.Open(pNewFileName,CFile::modeWrite|CFile::modeCreate);
	dwSize=cOldFile.GetLength();
	pBuffer=new char[dwReadSize];

	dwCurPos=m_StartPos;
	if(dwCurPos<dwSize)
	{
		cOldFile.Seek(dwCurPos,CFile::begin);
		while(dwCurPos<(dwSize-dwReadSize))
		{
			dwCurPos+=cOldFile.Read(pBuffer,dwReadSize);
			cNewFile.Write(pBuffer,dwReadSize);
		}
		delete[] pBuffer;
		pBuffer=new char[dwSize-dwCurPos];
		cOldFile.Read(pBuffer,(dwSize-dwCurPos));
		cNewFile.Write(pBuffer,(dwSize-dwCurPos));
		delete[] pBuffer;
		MessageBox("Finished!");
	}
	else
	{
		MessageBox("Faild!");
	}
	cOldFile.Close();
	cNewFile.Close();
	EndWaitCursor();
}

void CSplitFileDlg::OnButtonPart1() 
{
	CFileDialog dlgFile(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"All files (*.*)|*.*||",NULL);
	if(dlgFile.DoModal()==IDOK)
	{
		m_Part1=dlgFile.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CSplitFileDlg::OnButtonPart2() 
{
	CFileDialog dlgFile(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Part 2 (*.part2)|*.part2|All files (*.*)|*.*||",NULL);
	if(dlgFile.DoModal()==IDOK)
	{
		m_Part2=dlgFile.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CSplitFileDlg::OnButtonJoin() 
{
	BeginWaitCursor();
	UpdateData(TRUE);
	DWORD dwCurPos(0);
	DWORD dwFullSize(0);
	DWORD dwReadSize=8096;
	char* pBuffer=NULL;

	CFile cPart1File,cPart2File;
	cPart2File.Open(m_Part2,CFile::modeRead);
	cPart1File.Open(m_Part1,CFile::modeWrite);
	dwFullSize=cPart2File.GetLength()+cPart1File.GetLength();
	pBuffer=new char[dwReadSize];



	cPart1File.Seek(0,CFile::end);
	dwCurPos=cPart1File.GetPosition();
	cPart2File.Seek(0,CFile::begin);
	while(dwCurPos<(dwFullSize-dwReadSize))
	{
		dwCurPos+=cPart2File.Read(pBuffer,dwReadSize);
		cPart1File.Write(pBuffer,dwReadSize);
	}
	delete[] pBuffer;
	pBuffer=new char[dwFullSize-dwCurPos];
	cPart2File.Read(pBuffer,(dwFullSize-dwCurPos));
	cPart1File.Write(pBuffer,(dwFullSize-dwCurPos));
	delete[] pBuffer;
	MessageBox("Finished!");

	cPart1File.Close();
	cPart2File.Close();
	EndWaitCursor();
}
