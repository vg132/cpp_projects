// AdressbokDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Adressbok.h"
#include "AdressbokDlg.h"

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
// CAdressbokDlg dialog

CAdressbokDlg::CAdressbokDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdressbokDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdressbokDlg)
	m_Address = _T("");
	m_City = _T("");
	m_LastName = _T("");
	m_FirstName = _T("");
	m_Phone = _T("");
	m_PostNr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdressbokDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdressbokDlg)
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_Save);
	DDX_Control(pDX, IDC_CONTACT_LIST, m_ContactList);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
	DDV_MaxChars(pDX, m_Address, 100);
	DDX_Text(pDX, IDC_EDIT_CITY, m_City);
	DDV_MaxChars(pDX, m_City, 100);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_LastName);
	DDV_MaxChars(pDX, m_LastName, 100);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_FirstName);
	DDV_MaxChars(pDX, m_FirstName, 100);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_Phone);
	DDV_MaxChars(pDX, m_Phone, 100);
	DDX_Text(pDX, IDC_EDIT_POSTNR, m_PostNr);
	DDV_MaxChars(pDX, m_PostNr, 6);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdressbokDlg, CDialog)
	//{{AFX_MSG_MAP(CAdressbokDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SPARASOM, OnFileSparasom)
	ON_NOTIFY(NM_CLICK, IDC_CONTACT_LIST, OnClickContactList)
	ON_BN_CLICKED(IDC_BUTTON_SHOWALL, OnButtonShowall)
	ON_COMMAND(ID_FILE_NY, OnFileNy)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdressbokDlg message handlers

BOOL CAdressbokDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	curitem=-1;
	DWORD dwStyle = m_ContactList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	m_ContactList.SetExtendedStyle(dwStyle);

	m_ContactList.InsertColumn(0,"Namn",NULL,100);
	m_ContactList.InsertColumn(1,"Telefon",NULL,100,0);
	m_ContactList.InsertColumn(2,"Adress",NULL,150,0);
	EnableControls(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdressbokDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdressbokDlg::OnPaint() 
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
HCURSOR CAdressbokDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdressbokDlg::OnFileSave() 
{
	if(!telefonbok.Save())
		OnFileSparasom();
}

void CAdressbokDlg::OnAppAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CAdressbokDlg::OnButtonAdd() 
{
	curitem=-1;
	m_FirstName="";
	m_LastName="";
	m_Phone="";
	m_Address="";
	m_PostNr="";
	m_City="";
	UpdateData(FALSE);
//	m_Save.EnableWindow(TRUE);
}

void CAdressbokDlg::OnButtonRemove() 
{
	telefonbok.RemovePersonById(curitem);
	curitem=-1;
	m_FirstName="";
	m_LastName="";
	m_Phone="";
	m_Address="";
	m_PostNr="";
	m_City="";
	UpdateListView();
	UpdateData(FALSE);
}

void CAdressbokDlg::OnButtonSave() 
{
	UpdateData(TRUE);
	person=new Person;
	char buffer[101];
	sprintf(buffer,"%s",m_FirstName);
	person->SetFirstName(buffer);
	sprintf(buffer,"%s",m_LastName);
	person->SetLastName(buffer);
	sprintf(buffer,"%s",m_Phone);
	person->SetPhone(buffer);
	sprintf(buffer,"%s",m_Address);
	person->SetAddress(buffer);
	sprintf(buffer,"%s",m_City);
	person->SetCity(buffer);
	sprintf(buffer,"%s",m_PostNr);
	person->SetPostNr(buffer);
	if(curitem==-1)
	{
		telefonbok.AddPerson(person);
	}
	else
	{
		telefonbok.RemovePersonById(curitem);
		telefonbok.AddPerson(person);
	}
	UpdateListView();
	UpdateData(FALSE);
}

void CAdressbokDlg::OnButtonSearch() 
{
	char buffer[600];
	CSearchDlg searchDlg;
	if(searchDlg.DoModal()==IDOK)
	{
		buffer[0]='\0';
		if(searchDlg.m_bFirstName==TRUE)
			strcat(buffer,searchDlg.m_FirstName);
		strcat(buffer,"|");
		if(searchDlg.m_bLastName==TRUE)
			strcat(buffer,searchDlg.m_LastName);
		strcat(buffer,"|");
		if(searchDlg.m_bAddress==TRUE)
			strcat(buffer,searchDlg.m_Address);
		strcat(buffer,"|");
		if(searchDlg.m_bPostNr==TRUE)
			strcat(buffer,searchDlg.m_PostNr);
		strcat(buffer,"|");
		if(searchDlg.m_bCity==TRUE)
			strcat(buffer,searchDlg.m_City);
		strcat(buffer,"|");
		if(searchDlg.m_bPhone==TRUE)
			strcat(buffer,searchDlg.m_Phone);
		telefonbok.Search(buffer);
		UpdateListView(false);
	}
}

void CAdressbokDlg::OnFileOpen() 
{
	CFileDialog filedlg(TRUE,
											"vpa",
											NULL,
											NULL,
											"ViPer adressbok (*.vpa)|*.vpa|Alla filer (*.*)|*.*||",
											NULL);

	if(filedlg.DoModal()==IDOK)
	{
		telefonbok.Open(filedlg.m_ofn.lpstrFile);
		UpdateListView();
		EnableControls(true);
	}
}

void CAdressbokDlg::UpdateListView(bool ViewAll)
{
	LVITEM lvi;
	char buffer[200];
	int size(0);
	if(ViewAll==true)
	{
		size=telefonbok.GetSize();
		GetDlgItem(IDC_FRAME_LIST)->SetWindowText("Alla kontakter");
	}
	else
	{
		size=telefonbok.GetSearchResultSize();
		GetDlgItem(IDC_FRAME_LIST)->SetWindowText("Sök resultat");
	}
	lvi.mask =  /*LVIF_IMAGE | */LVIF_TEXT;
	m_ContactList.DeleteAllItems();
	for(int i=0;i<size;i++)
	{
		if(ViewAll==true)
			person=telefonbok.GetPersonByPos(i);
		else
			person=telefonbok.GetSearchResult(i);
		sprintf(buffer,"%s %s",person->GetFirstName(),person->GetLastName());
		lvi.iItem = i;
		lvi.iSubItem = 0;
		lvi.pszText = buffer;
//		lvi.iImage = i%8;
		m_ContactList.InsertItem(&lvi);
		lvi.iSubItem = 1;
		lvi.pszText = person->GetPhone();
		m_ContactList.SetItem(&lvi);
		lvi.iSubItem = 2;
		lvi.pszText = person->GetAddress();
		m_ContactList.SetItem(&lvi);
		m_ContactList.SetItemData(i,person->GetId());
	}
}

void CAdressbokDlg::OnFileSparasom()
{
	CFileDialog filedlg(FALSE,
											"vpa",
											NULL,
											NULL,
											"ViPer adressbok (*.vpa)|*.vpa||",
											NULL);

	if(filedlg.DoModal()==IDOK)
	{
		telefonbok.Save(filedlg.m_ofn.lpstrFile);
	}
}

void CAdressbokDlg::OnClickContactList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	POSITION pos;
	pos = m_ContactList.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		int i = m_ContactList.GetNextSelectedItem(pos);
		i = m_ContactList.GetItemData(i);
		curitem = i;
		person=telefonbok.GetPersonById(i);
		m_FirstName=person->GetFirstName();
		m_LastName=person->GetLastName();
		m_PostNr=person->GetPostNr();
		m_Address=person->GetAddress();
		m_Phone=person->GetPhone();
		m_City=person->GetCity();
		UpdateData(FALSE);
	}
	*pResult = 0;
}

void CAdressbokDlg::OnButtonShowall() 
{
	UpdateListView();	
}

void CAdressbokDlg::OnFileNy() 
{
	telefonbok.New();
	UpdateListView();
	EnableControls(true);
}

void CAdressbokDlg::EnableControls(bool enable)
{
	GetDlgItem(IDC_CONTACT_LIST)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_FIRSTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_LASTNAME)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_ADDRESS)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_POSTNR)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_CITY)->EnableWindow(enable);
	GetDlgItem(IDC_EDIT_PHONE)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_ADD)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_REMOVE)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_SAVE)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_SEARCH)->EnableWindow(enable);
	GetDlgItem(IDC_BUTTON_SHOWALL)->EnableWindow(enable);
}

void CAdressbokDlg::OnFileClose() 
{
	telefonbok.Close();
	m_ContactList.DeleteAllItems();
	m_Address="";
	m_City="";
	m_LastName="";
	m_FirstName="";
	m_Phone="";
	m_PostNr="";
	EnableControls(false);
}
