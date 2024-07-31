// F1ImageInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "F1ImageInfo.h"
#include "F1ImageInfoDlg.h"

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
// CF1ImageInfoDlg dialog

CF1ImageInfoDlg::CF1ImageInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CF1ImageInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CF1ImageInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CF1ImageInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CF1ImageInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CF1ImageInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CF1ImageInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CF1ImageInfoDlg message handlers

BOOL CF1ImageInfoDlg::OnInitDialog()
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

void CF1ImageInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CF1ImageInfoDlg::OnPaint() 
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
HCURSOR CF1ImageInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CF1ImageInfoDlg::OnButton1() 
{
WIN32_FIND_DATA wfd;
HANDLE hFile;
CFile file;
char* buffer;
char* tmp;
int i=0;
char* newFile;
char* oldFile;
	BeginWaitCursor();
	tmp=new char[10];
	file.Open("c:\\test.txt",CFile::modeWrite,NULL);
	hFile=FindFirstFile("E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\*.jpg",&wfd);
//	hFile=FindFirstFile("g:\\Färdiga\\3*.jpg",&wfd);
	if(hFile!=(HANDLE)-1)
	{
		do
		{
			if(DecodeImage(wfd.cFileName))
			{
				buffer=new char[1500];
				strcpy(buffer,"INSERT INTO photo (filename, filesize, width, height,info) VALUES ('");
				strcat(buffer,wfd.cFileName);
				strcat(buffer,"'");
				strcat(buffer,",");
				itoa(wfd.nFileSizeLow,tmp,10);
				strcat(buffer,tmp);
				strcat(buffer,",");
				itoa(image_widht,tmp,10);
				strcat(buffer,tmp);
				strcat(buffer,",");
				itoa(image_height,tmp,10);
				strcat(buffer,tmp);
				strcat(buffer,",");

				i=0;
				strcpy(tmp,"\0");
				while(!(isalpha(wfd.cFileName[i])))
				{
					strncat(tmp,&wfd.cFileName[i++],1);
				};
				strcat(buffer,tmp);
				strcat(buffer,");\n\0");
				file.Write(buffer,strlen(buffer));
				newFile=new char[MAX_PATH];
				oldFile=new char[MAX_PATH];

				strcpy(oldFile,"E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\");
				strcat(oldFile,wfd.cFileName);
				strcpy(newFile,"E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\Färdiga\\");
				strcat(newFile,wfd.cFileName);

				MoveFile(oldFile,newFile);

				delete[] buffer;
				delete[] newFile;
				delete[] oldFile;
			}/*
			else
			{
				buffer=new char[500];
				strcpy(buffer,wfd.cFileName);
				strcat(buffer,"\n\0");
				file.Write(buffer,strlen(buffer));
				delete[] buffer;
			}*/
		}while(FindNextFile(hFile,&wfd));
	}
	file.Close();
	EndWaitCursor();
}

bool CF1ImageInfoDlg::DecodeImage(char *filename2)
{
ifstream f;
//ofstream of;
	char* filename;
	filename=new char[260];
	strcpy(filename,"E:\\My Intranet\\viktor_dns2go_test\\dbs.galeforcef1.com\\photo\\");
	strcat(filename,filename2);

	unsigned char* buffer;
	buffer=new unsigned char[BUFFERSIZE];
	
	f.open(filename,ios::in|ios::binary);
	f.seekg(0,ios::beg);
	f.read((unsigned char*)buffer,BUFFERSIZE);
	image_type=unknown;
	if((buffer[0]==137)&&(buffer[1]==80)&&(buffer[2]==78))
	{
		//PNG
		image_type=png;
		switch(buffer[25])
		{
			case 0:
				image_depth=buffer[24];
				break;
			case 2:
				image_depth=buffer[24]*3;
				break;
			case 3:
				image_depth=8;
				break;
			case 4:
				image_depth=buffer[24]*2;
				break;
			case 6:
				image_depth=buffer[24]*4;
				break;
			default:
				image_type=unknown;
				break;
		}
		if(image_type!=unknown)
		{
			image_widht=Mult(buffer[19],buffer[18]);
			image_height=Mult(buffer[23],buffer[22]);
		}
	}
	else if((buffer[0]==71)&&(buffer[1]==73)&&(buffer[2]==70))
	{
		//GIF
		image_type=gif;
		image_widht=Mult(buffer[6],buffer[7]);
		image_height=Mult(buffer[8],buffer[9]);
		image_depth=(buffer[10] & 7)+1;
	}
	else if((buffer[0]==66)&&(buffer[1]==77))
	{
		//BMP
		image_type=bmp;
		image_widht=Mult(buffer[18],buffer[19]);
		image_height=Mult(buffer[22],buffer[23]);
		image_depth=buffer[28];
	}
	if(image_type==unknown)
	{
		//if the file is not one of the above type then
		//check to see if it is a jpeg file
		int iPos=0;
		int iTmp=0;
		
		//||(iPos<=BUFFERSIZE-10));
		while(((buffer[iPos++]!=0xFF)&&(buffer[iPos+1]!=0xD8)&&(buffer[iPos+2]!=0xFF)));
		iPos+=1;
		if(!(iPos>=BUFFERSIZE-10))
		{
			do
			{
				while((buffer[iPos]!=0xFF)&&(buffer[iPos+1]==0xFF))
				{
					iPos++;
				};
				iPos++;
				iTmp=buffer[iPos];
				
				if(((iTmp>=0xC0)&&(iTmp<=0xC3))||
					((iTmp>=0xC5)&&(iTmp<=0xC7))||
					((iTmp>=0xC9)&&(iTmp<=0xCB))||
					((iTmp>=0xCD)&&(iTmp<=0xCF)))
				{
					image_type=jpg;
					image_depth=buffer[iPos+8]*8;
					image_height=Mult(buffer[iPos+5],buffer[iPos+4]);
					image_widht=Mult(buffer[iPos+7],buffer[iPos+6]);
					break;
				}
				iPos+=Mult(buffer[iPos+2],buffer[iPos+1]);
			}while(iPos<BUFFERSIZE-10);
		}
	}
	f.close();
	delete[] buffer;
	if(image_type!=unknown)
		return(true);
	else
		return(false);
}

int CF1ImageInfoDlg::Mult(int a, int b)
{
	return(a+(b*256));
}
