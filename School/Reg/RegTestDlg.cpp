// RegTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegTest.h"
#include "RegTestDlg.h"

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
// CRegTestDlg dialog

CRegTestDlg::CRegTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegTestDlg)
	m_Email = _T("");
	m_Name = _T("");
	m_Key = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegTestDlg)
	DDX_Text(pDX, IDC_EMAIL, m_Email);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_KEY, m_Key);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRegTestDlg, CDialog)
	//{{AFX_MSG_MAP(CRegTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEWCODE, OnNewcode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegTestDlg message handlers

BOOL CRegTestDlg::OnInitDialog()
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

void CRegTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRegTestDlg::OnPaint() 
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
HCURSOR CRegTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRegTestDlg::OnNewcode() 
{
int datasize(0);
int i(0);
int sum(0),cycle(0), total(0);
unsigned char c;
char *buffer=new char[50];

	UpdateData(TRUE);
	i=0;
	datasize=m_Name.GetLength();
	while(datasize--) 
	{
		c=m_Name.GetAt(i);
		sum += c&sum;
		cycle = (cycle<<3)+(cycle>>13);
		cycle+=c;
		cycle+=cycle^sum;
		i+=1;
	}
	total=(cycle+sum);
	itoa(total,buffer,10);
	if(buffer[0]=='-')
		strcpy(buffer,&buffer[1]);
	m_Key=buffer;
	m_Key+="-";
	i=0;
	datasize=m_Email.GetLength();
	while(datasize--) 
	{
		c=m_Email.GetAt(i);
		sum += c;
		cycle = (cycle<<13)+(cycle>>3);
		cycle+=c;
		cycle+=cycle^sum;
		i+=1;
	}
	int tmp=(cycle+sum)&total;
	itoa(tmp,buffer,10);
	if(buffer[0]=='-')
		strcpy(buffer,&buffer[1]);
	m_Key+=buffer;
	m_Key+="-";
	tmp=(cycle+sum);
	itoa(tmp,buffer,10);
	if(buffer[0]=='-')
		strcpy(buffer,&buffer[1]);
	m_Key+=buffer;
	delete[] buffer;
	UpdateData(FALSE);
}
