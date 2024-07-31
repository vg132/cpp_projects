// Uppgift2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Uppgift2.h"
#include "Uppgift2Dlg.h"

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
// CUppgift2Dlg dialog

CUppgift2Dlg::CUppgift2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUppgift2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUppgift2Dlg)
	m_Add1 = _T("");
	m_Add2 = _T("");
	m_Add3 = _T("");
	m_Equals = _T("");
	m_Find = _T("");
	m_Replace = _T("");
	m_Result = _T("");
	m_Real = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUppgift2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUppgift2Dlg)
	DDX_Text(pDX, IDC_EDIT_ADD1, m_Add1);
	DDX_Text(pDX, IDC_EDIT_ADD2, m_Add2);
	DDX_Text(pDX, IDC_EDIT_ADD3, m_Add3);
	DDX_Text(pDX, IDC_EDIT_EQUALS, m_Equals);
	DDX_Text(pDX, IDC_EDIT_FIND, m_Find);
	DDX_Text(pDX, IDC_EDIT_REPLACE, m_Replace);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_Result);
	DDX_Text(pDX, IDC_EDIT_REAL, m_Real);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUppgift2Dlg, CDialog)
	//{{AFX_MSG_MAP(CUppgift2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, OnButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, OnButtonAdd2)
	ON_BN_CLICKED(IDC_BUTTON_REPLACE, OnButtonReplace)
	ON_BN_CLICKED(IDC_BUTTON_UPPERCASE, OnButtonUppercase)
	ON_BN_CLICKED(IDC_BUTTON_LOWERCASE, OnButtonLowercase)
	ON_EN_SETFOCUS(IDC_EDIT_REAL, OnSetfocusEditReal)
	ON_EN_SETFOCUS(IDC_EDIT_RESULT, OnSetfocusEditResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUppgift2Dlg message handlers

BOOL CUppgift2Dlg::OnInitDialog()
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

void CUppgift2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUppgift2Dlg::OnPaint() 
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
HCURSOR CUppgift2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUppgift2Dlg::OnButtonEquals() 
{
	UpdateData(TRUE);
	vs=m_Equals;
	m_Result=vs.ToChar();
	m_Real=m_Result;
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnButtonAdd() 
{
	UpdateData(TRUE);
	vs=m_Add1+m_Add2;
	m_Result=vs.ToChar();
	m_Real=m_Result;
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnButtonAdd2() 
{
	UpdateData(TRUE);
	vs=vs + m_Add3;
	m_Result=vs.ToChar();
	m_Real=m_Result;
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnButtonReplace() 
{
	UpdateData(TRUE);
	m_Result=vs.replace(m_Find,m_Replace).ToChar();
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnButtonUppercase() 
{
	m_Result=vs.uppercase().ToChar();
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnButtonLowercase() 
{
	m_Result=vs.lowercase().ToChar();
	UpdateData(FALSE);
}

void CUppgift2Dlg::OnSetfocusEditReal() 
{
	GetDlgItem(IDC_BUTTON_EQUALS)->SetFocus();
}

void CUppgift2Dlg::OnSetfocusEditResult() 
{
	GetDlgItem(IDC_BUTTON_EQUALS)->SetFocus();
}
