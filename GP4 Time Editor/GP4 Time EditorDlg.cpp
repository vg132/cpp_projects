// GP4 Time EditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GP4 Time Editor.h"
#include "GP4 Time EditorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGP4TimeEditorDlg dialog



CGP4TimeEditorDlg::CGP4TimeEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGP4TimeEditorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGP4TimeEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_TAB, m_Tab);
}

BEGIN_MESSAGE_MAP(CGP4TimeEditorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnTcnSelchangeTab)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnNMDblclkList)
END_MESSAGE_MAP()


// CGP4TimeEditorDlg message handlers

BOOL CGP4TimeEditorDlg::OnInitDialog()
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
	
	//Add tabs
	m_Tab.InsertItem(0,"Pole Position Records");
	m_Tab.InsertItem(1,"Fastest Lap Records");
	m_Tab.InsertItem(2,"2000 Pole Position");
	m_Tab.InsertItem(3,"2000 Fastest Lap");
	m_Tab.InsertItem(4,"2000 Winner");

	//Set extended styles
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//Add column headers to the list
	m_List.InsertColumn(0,"Nr",LVCFMT_LEFT,30);
	m_List.InsertColumn(1,"Driver",LVCFMT_LEFT,140);
	m_List.InsertColumn(2,"Team",LVCFMT_LEFT,100);
	m_List.InsertColumn(3,"Date",LVCFMT_LEFT,80);
	m_List.InsertColumn(4,"Time",LVCFMT_LEFT,80);



	ReadSaveFile("F:\\Grand Prix 4\\f1gstate.sav");
	ShowRecords();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGP4TimeEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGP4TimeEditorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGP4TimeEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CGP4TimeEditorDlg::CheckSum(char* FileName, bool gp4)
{
long datasize;
unsigned short sum=0,cycle=0;
unsigned char c;

	CFile file;
	file.Open(FileName,CFile::modeReadWrite);

	datasize=(long)file.GetLength()-4;

	while(datasize--)
	{
		file.Read((char*)&c,sizeof(c));
		sum+=c;
		cycle=(cycle<<3)+(cycle>>13);
		cycle+=c;
	}
	if(gp4==true)
	{
		cycle+=0x8465;
		sum+=0x8065;
	}
	file.Seek(-4,CFile::end);
	file.Write((char*)&sum,sizeof(sum));
	file.Write((char*)&cycle,sizeof(cycle));
	file.Close();
	return(true);
}

// Read the file and show all records in the list view
bool CGP4TimeEditorDlg::ReadSaveFile(char* Filename)
{
	if(Filename==NULL)
		return(false);

	CFile f;
	f.Open(Filename,CFile::modeRead,NULL);
	f.Seek(1848,CFile::begin);

	for(int i=0;i<17;i++)
		f.Read(&m_Records[i],sizeof(m_Records[i]));
	f.Close();

	return(true);
}

void CGP4TimeEditorDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	ShowRecords();
	*pResult = 0;
}

void CGP4TimeEditorDlg::ShowRecords(void)
{
	int i(0), pos(0);
	char* buffer;
	LVCOLUMN pColumn;
	
	buffer=new char[30];	
	m_List.DeleteAllItems();

	if(m_Tab.GetCurSel()==0)
	{
		//PP Records
		for(i=0;i<17;i++)
		{
			sprintf(buffer,"%d",i+1);
			pos=m_List.InsertItem(i,buffer);
			m_List.SetItem(pos,1,LVIF_TEXT,m_Records[i].rec_pp_name,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,2,LVIF_TEXT,m_Records[i].rec_pp_team,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,3,LVIF_TEXT,m_Records[i].rec_pp_year,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,4,LVIF_TEXT,GetTime(m_Records[i].rec_pp_time,buffer),NULL,NULL,NULL,NULL);
		}
		m_List.GetColumn(3,&pColumn);
		pColumn.pszText="Year";
		m_List.SetColumn(3,&pColumn);
	}
	else if(m_Tab.GetCurSel()==1)
	{
		//FL Records
		for(i=0;i<17;i++)
		{
			sprintf(buffer,"%d",i+1);
			pos=m_List.InsertItem(i,buffer);
			m_List.SetItem(pos,1,LVIF_TEXT,m_Records[i].rec_fl_name,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,2,LVIF_TEXT,m_Records[i].rec_fl_team,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,3,LVIF_TEXT,m_Records[i].rec_fl_year,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,4,LVIF_TEXT,GetTime(m_Records[i].rec_fl_time,buffer),NULL,NULL,NULL,NULL);
		}
		m_List.GetColumn(3,&pColumn);
		pColumn.pszText="Year";
		m_List.SetColumn(3,&pColumn);
	}
	else if(m_Tab.GetCurSel()==2)
	{
		//PP 2000
		for(i=0;i<17;i++)
		{
			sprintf(buffer,"%d",i+1);
			pos=m_List.InsertItem(i,buffer);
			m_List.SetItem(pos,1,LVIF_TEXT,m_Records[i].pp_name,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,2,LVIF_TEXT,m_Records[i].pp_team,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,3,LVIF_TEXT,GetDate(m_Records[i].pp_date,buffer),NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,4,LVIF_TEXT,GetTime(m_Records[i].pp_time,buffer),NULL,NULL,NULL,NULL);
		}
		m_List.GetColumn(3,&pColumn);
		pColumn.pszText="Date";
		m_List.SetColumn(3,&pColumn);
	}
	else if(m_Tab.GetCurSel()==3)
	{
		//FL 2000
		for(i=0;i<17;i++)
		{
			sprintf(buffer,"%d",i+1);
			pos=m_List.InsertItem(i,buffer);
			m_List.SetItem(pos,1,LVIF_TEXT,m_Records[i].fl_name,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,2,LVIF_TEXT,m_Records[i].fl_team,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,3,LVIF_TEXT,GetDate(m_Records[i].fl_date,buffer),NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,4,LVIF_TEXT,GetTime(m_Records[i].fl_time,buffer),NULL,NULL,NULL,NULL);
		}
		m_List.GetColumn(3,&pColumn);
		pColumn.pszText="Date";
		m_List.SetColumn(3,&pColumn);
	}
	else if(m_Tab.GetCurSel()==4)
	{
		for(i=0;i<17;i++)
		{
			sprintf(buffer,"%d",i+1);
			pos=m_List.InsertItem(i,buffer);
			m_List.SetItem(pos,1,LVIF_TEXT,m_Records[i].winner_name,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,2,LVIF_TEXT,m_Records[i].winner_team,NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,3,LVIF_TEXT,"-",NULL,NULL,NULL,NULL);
			m_List.SetItem(pos,4,LVIF_TEXT,"-",NULL,NULL,NULL,NULL);
		}
	}
	delete[] buffer;
}

char* CGP4TimeEditorDlg::GetTime(int time, char* buffer)
{
	int m(0),s(0);

	while(time>=60000)
	{
		m++;
		time-=60000;
	}
	while(time>=1000)
	{
		s++;
		time-=1000;
	}
	sprintf(buffer,"%d:%02d.%03d\0",m,s,time);
	return(buffer);
}

char* CGP4TimeEditorDlg::GetDate(int date, char* buffer)
{
	struct tm time_str;
	time_str.tm_year = 1978-1900;
	time_str.tm_mon = 0;
	time_str.tm_mday = date;
	time_str.tm_hour = 0;
	time_str.tm_min = 0;
	time_str.tm_sec = 0;
	time_str.tm_wday=0;
	time_str.tm_yday=0;
	time_str.tm_isdst = -1;

	_mktime64(&time_str);
	strftime(buffer,30,"%Y-%m-%d",&time_str);
	return(buffer);
}
void CGP4TimeEditorDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	


	POSITION pos;
	int iSelItem;
	char* buffer;
	buffer=new char[30];
	pos=m_List.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		iSelItem=m_List.GetNextSelectedItem(pos);
		CTimeEdit* te=new CTimeEdit(this);
		te->Create(IDD_TIME_EDIT,this);
		te->m_Name.SetWindowText(m_Records[iSelItem].fl_name);
		te->m_Team.SetWindowText(m_Records[iSelItem].fl_team);
		te->m_Date.SetWindowText(GetDate(m_Records[iSelItem].fl_date,buffer));
		te->m_Time.SetWindowText(GetTime(m_Records[iSelItem].fl_time,buffer));
		te->ShowWindow(SW_SHOW);
	}
	delete[] buffer;
	*pResult = 0;
}
